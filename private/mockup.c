//
// Created by florian on 1/14/22.
//

#include <stdio.h>


#define KEY_SIZE 1200
#define FLAG_LENGTH 30
const char key[KEY_SIZE] = "@r5uMk$yY^T*vJR#v&Pu4G2MG7txzX I already encrypted the flag Muhaha! Since you cannot read this, I can tell you all about my powerful and fast encryption. It needs a very long key, so trying to get the whole plaintext key will take some good amount of time, try your attack offline first. However I did something sus. I wasn't able to find an infinite key :sus emoji: Luckily you won't find that out. Haha! Now if you you found that out, you first still have to read through the whole first shrek movie >:] Shrek: 'Once upon a time, there was a lovely princess. But she had an enchantment upon her of a fearful sort, which could only be broken by love's first kiss. She was locked away in a castle, guarded by a terrible fire-breathing dragon. Many brave knights had attempted to free her from the dreadful prison, but none prevailed. She waited in the dragon's keep, in the highest roöm of the tallest tower, for her true love and true love's first kiss.' [Laughing] Like that's ever gonna happen.  [Paper Rustling, Toilet Flushes]  Shrek: What a load of--  [Toilet Door slams]  Shrek hops out his outhouse and his routine like taking a mud shower and farting in his pool.  [ All-Star By Smash Mout\0";
const char flag[FLAG_LENGTH] = "MiniCTF{0n3_t00_m4ny_t1m3_p4d}";
int key_loc = FLAG_LENGTH;
int got_message = 0;
int bit_mode = 0;


int increment_key() {
    if (key_loc < KEY_SIZE - 1) {
        key_loc++;
    } else {
        key_loc = 0;
    }
    return 0;
}


void print_bits(char string[], int length) {
    char *b = string;
    char byte;
    int i, j;
    /*
    for (i = 0; i < length - 1; i++) {
        for (j = 0; j < 8; j++) {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    */
    // length-1 since we don't want to print the zero byte
    for (i = 0; i < length - 1; i++) {
        for (j = 7; j >= 0; j--) {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
}


void print_string(char string[], int length) {
    if (bit_mode)
        print_bits(string, length);
    else
        printf("%s", string);
    printf("\n");
}


void get_encrypted_flag() {
    char output[FLAG_LENGTH + 1];
    for (int i = 0 ; i < FLAG_LENGTH; i++) {
        output[i] = flag[i] ^ key[i];
    }
    output[FLAG_LENGTH] = '\0';
    printf("The encrypted flag is: ");
    print_string(output, FLAG_LENGTH + 1);
}


void encrypt_message(char msg[], int msg_length) {
    char output[msg_length + 1];
    for (int i = 0 ; i < msg_length; i++) {
        output[i] = msg[i] ^ key[key_loc];
        increment_key();
    }
    output[msg_length] = '\0';
    printf("The encrypted message is: ");
    print_string(output, msg_length + 1);
}


void encrypt_known_message(char msg[], int msg_length) {
    if (got_message) {
        printf("You already encrypted this message!\n");
    } else {
        got_message = 1;
        printf("The known message is: ");
        print_string(msg, msg_length + 1);
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
           "2: encrypt hidden message of length 10 \n"
           "3: encrypt hidden message of length 32 \n"
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
            // Flo: The known encrypted message was chosen to be as long as the key (excluding zero byte),
            // however doesn't need to be so
            encrypt_known_message("Never gonna give you up! -Rick", 30);
            break;
        case '2':
            encrypt_message("!Reihe_12!", 10);
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
           "3: enter bit mode (output everything in their bit format) \n"
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
        case '3':
            bit_mode = 1;
            break;
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
