#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("./bin pwd\n");
        return 1;
    }

    char *password = argv[1];
    if (strcmp(password, "whatabeautifulevening") != 0) {
        printf(":(\n");
        return 1;
    }

    printf("well done! :))\n");

    return 0;
}
