#include <stdio.h>
#include <string.h>

// Multiplies each letter pair by a 2x2 matrix mod 26
void transform(const char *in, char *out, int m[2][2]) {
    for (int i = 0; in[i] && in[i + 1]; i += 2) {
        int a = in[i] - 'A', b = in[i + 1] - 'A';
        out[i]     = (m[0][0] * a + m[0][1] * b) % 26 + 'A';
        out[i + 1] = (m[1][0] * a + m[1][1] * b) % 26 + 'A';
    }
}

int main() {
    int key[2][2] = {{3, 3}, {2, 5}};
    int inv[2][2] = {{15, 17}, {20, 9}};
    char text[100], enc[100] = {0}, dec[100] = {0};

    printf("Enter plaintext (uppercase, even length): ");
    scanf("%99s", text);

   

    transform(text, enc, key);
    transform(enc, dec, inv);

    printf("Encrypted Text: %s\n", enc);
    printf("Decrypted Text: %s\n", dec);
    return 0;
}
