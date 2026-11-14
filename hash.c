#include <stdio.h>

int main() {
    char str[256];
    unsigned long hash = 0;
    int i;

    printf("Enter a message: ");
    scanf("%255s", str);

    for (i = 0; str[i] != '\0'; i++)
        hash = (hash * 31 + str[i]) % 1000000007;

    printf("Hash Value: %lu\n", hash);

    return 0;
}

