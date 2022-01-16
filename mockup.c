//
// Created by florian on 1/14/22.
//

#include <stdio.h>


#define KEY_SIZE 100
#define FLAG_LENGTH 30
const char key[KEY_SIZE] = "Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut l";
const char flag[FLAG_LENGTH] = "MiniCTF{0n3_t0o_m4ny_t1m3_p4d}";
int key_loc = FLAG_LENGTH;


int increment_key() {
    if (key_loc < KEY_SIZE - 1) {
        key_loc++;
    } else {
        key_loc = 0;
    }
    return 0;
}


void get_encrypted_flag() {
    char output[FLAG_LENGTH + 1];
    for (int i = 0 ; i < FLAG_LENGTH; i++) {
        output[i] = flag[i] ^ key[i];
    }
    output[FLAG_LENGTH] = '\0';
    printf("The encrypted flag is: %s \n", output);
}


void encrypt_message(char msg[], int msg_length) {
    char output[msg_length + 1];
    for (int i = 0 ; i < msg_length; i++) {
        output[i] = msg[i] ^ key[key_loc];
        increment_key();
    }
    output[msg_length] = '\0';
    printf("The encrypted message is: %s \n", output);
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
    printf("There are 2 messages of different length, which one do you want? \n "
           "Type 0 to return. \n");
    char c = read_input();
    if (c == -1) {
        return -1;
    }
    switch (c) {
        case '0':
            return 1;
        case '1':
            encrypt_message("ABCD", 4);
            break;
        case '2':
            encrypt_message("Maxi ist der allerbeste Tutor.", 30);
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
           "3: reset \n"
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
            int r = parse_message();
            if (r == -1) {
                return -1;
            }
            break;
        case '3':
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
