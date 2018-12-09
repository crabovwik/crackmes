#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

static const char *password = "gAWthOSTfITHgmTh32ziFrsDPY9pTI01SHXq";

char *get_flag();

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("./bin pwd\n");
        return 1;
    }

    char *inputPassword = argv[1];

    if (strcmp(inputPassword, password) != 0) {
        printf(":(\n");
        return 1;
    }

    printf(":))\n");

    while (*password) {
        sleep(111111111);
    }


    char *flag = get_flag();
    printf("congratulations! :))\n");
    printf("your flag is %s\n", flag);

    return 0;
}

char *get_flag() {
    int password_length = (int) strlen(password);
    char *flag = (char *) malloc(sizeof(char) * (password_length + 1));
    strcpy(flag, password);

    for (int i = 0; i < password_length; i++) {
        if (i % 3 == 0) {
            flag[i] ^= 0x01;
        } else if (i % 2 == 0) {
            flag[i] ^= 0x03;
        } else {
            flag[i] ^= 0x02;
        }

        if (flag[i] == 0x00) {
            flag[i] = 'a';
        }
    }

    flag[password_length] = 0x00;

    return flag;
}
