//rc4 algorithm
#include <stdio.h>
#include <string.h>

int s[256];
char key[] = "secret";

void ksa(int key_len) {
    for (int i = 0; i < 256; i++) {
        s[i] = i;
    }
    int j = 0;
    for (int i = 0; i < 256; i++) {
        j = (j + s[i] + (unsigned char)key[i % key_len]) % 256;
        int temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

int main() {
    int key_len = strlen(key);
    char msg[256];
    unsigned char enc[256];
    unsigned char dec[256];

    printf("enter the message : ");
    scanf("%255s", msg);
    int len = strlen(msg);

    // encryption
    ksa(key_len);
    int i = 0;
    int j = 0;
    for (int k = 0; k < len; k++) {
        i = (i + 1) % 256;
        j = (j + s[i]) % 256;
        int temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        int keystream = s[(s[i] + s[j]) % 256];
        enc[k] = (unsigned char)msg[k] ^ keystream;
    }

    printf("encrypted message : ");
    for (int k = 0; k < len; k++) {
        printf("%02x", enc[k]);
    }

    // decryption
    ksa(key_len);
    i = 0;
    j = 0;
    for (int k = 0; k < len; k++) {
        i = (i + 1) % 256;
        j = (j + s[i]) % 256;
        int temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        int keystream = s[(s[i] + s[j]) % 256];
        dec[k] = enc[k] ^ keystream;
    }
    dec[len] = '\0';

    printf("\ndecrypted message : %s\n", dec);
    return 0;
}
