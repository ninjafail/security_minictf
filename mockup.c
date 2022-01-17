//
// Created by florian on 1/14/22.
//

#include <stdio.h>


#define KEY_SIZE 100
#define FLAG_LENGTH 30
const char key[KEY_SIZE] = "Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut l";
const char flag[FLAG_LENGTH] = "MiniCTF{0n3_t0o_m4ny_t1m3_p4d}";
int key_loc = FLAG_LENGTH;
int got_message = 0;
// int bit_mode = 0;


int increment_key() {
    if (key_loc < KEY_SIZE - 1) {
        key_loc++;
    } else {
        key_loc = 0;
    }
    return 0;
}

/*
void printBits(char string[], int length) {
    char *b = string[];
    char byte;
    int i, j;

    for (i = size-1; i >= 0; i--) {
        for (j = 7; j >= 0; j--) {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    puts("");
}
 */


void get_encrypted_flag() {
    char output[FLAG_LENGTH + 1];
    for (int i = 0 ; i < FLAG_LENGTH; i++) {
        output[i] = flag[i] ^ key[i];
    }
    output[FLAG_LENGTH] = '\0';
    printf("The encrypted flag is: %s\n", output);
}


void encrypt_message(char msg[], int msg_length) {
    char output[msg_length + 1];
    for (int i = 0 ; i < msg_length; i++) {
        output[i] = msg[i] ^ key[key_loc];
        increment_key();
    }
    output[msg_length] = '\0';
    printf("The encrypted message is: %s\n", output);
}


void encrypt_known_message(char msg[], int msg_length) {
    if (got_message) {
        printf("You already encrypted this message!\n");
    } else {
        got_message = 1;
        printf("The known message is: %s\n", msg);
        encrypt_message(msg, msg_length);
    }
}


int reset_key() {
    key_loc = FLAG_LENGTH;
    printf("The key has been reset to its beginning. \n");
    return 0;
}


char read_input() {
    char input[100];
    char *r = fgets(input, 100, stdin);
    if (r == NULL) {
        printf("Malformed input! \n");
        return -1;
    }
    return input[0];
}


int parse_message() {
    printf("Which message do you want? \n"
           "1: encrypt the known message (Warning you can only do this once) \n"
           "2: encrypt hidden message of length 3 \n"
           "3: encrypt hidden message of length 34 \n"
           "4: encrypt hidden message of length 42 \n"
           "5: encrypt hidden message of length 69 \n"
           "0: leave \n");

    char c = read_input();
    if (c == -1) {
        return -1;
    }
    switch (c) {
        case '0':
            return 1;
        case '1':
            // Flo: The known encrypted was chosen to be as long as the key, however doesn't need to be so
            encrypt_known_message("Never gonna give you up! -Rick", 30);
            break;
        case '2':
            encrypt_message("420", 3);
            break;
        case '3':
            encrypt_message("Team 'Die Stuhl Gang' is the best!", 34);
            break;
        case '4':
            encrypt_message("Maxi is the BEST tutor in the universe !!!", 42);
            break;
        case '5':
            encrypt_message("Now I have to come up with a hidden message thats 69 chars long, damn", 69);
            break;
        default:
            printf("Please enter valid option. \n");
            break;
    }
    return 0;
}


int parse_input() {
    printf("What do you want? \n"
           "1: get encrypted flag \n"
           "2: encrypt message \n"
//           "3: enter bit mode (output everything in their bit format) \n"
           "9: reset \n"
           "0: leave \n");

    char c = read_input();
    if (c == -1) {
        return -1;
    }
    switch(c) {
        case '1':
            get_encrypted_flag();
            break;
        case '2':
            printf("\n");
            while(1) {
                int leave = parse_message();
                if (leave == -1) {
                    return -1;
                }
                if (leave == 1) {
                    break;
                }
                printf("\n");
            }
            break;
/*        case '3':
            bit_mode = 1;
            break;*/
        case '9':
            reset_key();
            break;
        case '0':
            return 1;
        default:
            printf("Please enter valid option. \n");
            break;
    }
    return 0;
}


int main(int argc, char** argv) {
    while(1) {
        int leave = parse_input();
        if (leave == -1) {
            return 1;
        }
        if (leave == 1) {
            return 0;
        }
        printf("\n");
    }
}
