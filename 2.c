#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SECRET_BYTE 0x13

// iamyour1337flag
static const char *first_part_encrypted_password = "\x7a\x72\x7e\x6a\x7c\x66\x61\x22\x20\x20\x24\x75\x7f\x72\x74";

// jujtouhpeffqfs
static const char *second_part_encrypted_password = "itisntgodeeper";

char *decrypt_password_of_the_first_part(const char *encrypted_password);

char *decrypt_password_of_the_second_part(const char *encrypted_password);

int main(int argc, char *argv[]) {

    // the first part of the flag checking
    if (argc < 2) {
        printf("./bin pwd\n");
        return 1;
    }

    char *first_part_password = argv[1];
    char *decrypted_password_of_the_first_part = decrypt_password_of_the_first_part(first_part_encrypted_password);
    if (strcmp(first_part_password, decrypted_password_of_the_first_part) != 0) {
        printf("first part :(\n");
        return 1;
    }

    printf("first part :))\n");

    // second part of the flag checking
    if (argc != 3) {
        printf("nice! you have just got the first part of the flag!\n");
        printf("apply the last one by\n");
        printf("./bin {pwdyouhavejustfound} pwd2\n");
        return 1;
    }

    char *second_part_password = argv[2];
    char *decrypted_password_of_the_second_part = decrypt_password_of_the_second_part(second_part_encrypted_password);
    if (strcmp(second_part_password, decrypted_password_of_the_second_part) != 0) {
        printf("second part :(\n");
        return 1;
    }

    printf("you are amazing!\n");
    printf("your result flag is {%s:%s}\n", first_part_password, second_part_password);

    return 0;
}

char *decrypt_password_of_the_first_part(const char *encrypted_password) {
    unsigned int encrypted_password_length = (unsigned int) strlen(encrypted_password);
    char *decrypted_password = (char *) malloc(sizeof(char) * (encrypted_password_length + 1));

    for (int i = 0; i < encrypted_password_length; i++) {
        decrypted_password[i] = (char) (encrypted_password[i] ^ SECRET_BYTE);
    }

    decrypted_password[encrypted_password_length] = 0x00;

    return decrypted_password;
}

char *decrypt_password_of_the_second_part(const char *encrypted_password) {
    unsigned int encrypted_password_length = (unsigned int) strlen(encrypted_password);
    char *decrypted_password = (char *) malloc(sizeof(char) * (encrypted_password_length + 1));

    for (int i = 0; i < encrypted_password_length; i++) {
        decrypted_password[i] = (char) (encrypted_password[i] + 1);
    }

    decrypted_password[encrypted_password_length] = 0x00;

    return decrypted_password;
}
