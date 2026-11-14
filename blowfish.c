#include <stdio.h>
#include <stdint.h>

uint32_t P[18] = {
   
};

uint32_t S[4][256] = {
   
};

uint32_t F(uint32_t x)
{
    unsigned char a = x >> 24;
    unsigned char b = x >> 16;
    unsigned char c = x >> 8;
    unsigned char d = x;

    return ((S[0][a] + S[1][b]) ^ S[2][c]) + S[3][d];
}

void encrypt(uint32_t *L, uint32_t *R)
{
    for (int i = 0; i < 16; i++)
    {
        *L = *L ^ P[i];
        *R = *R ^ F(*L);

        uint32_t temp = *L;
        *L = *R;
        *R = temp;
    }

    
    uint32_t temp = *L;
    *L = *R;
    *R = temp;

    *R = *R ^ P[16];
    *L = *L ^ P[17];
}

int main()
{
    uint32_t L = 0x12345678;
    uint32_t R = 0x9ABCDEF0;

    printf("Plaintext:\n");
    printf("L = %08X\n", L);
    printf("R = %08X\n", R);

    encrypt(&L, &R);

    printf("\nCiphertext:\n");
    printf("L = %08X\n", L);
    printf("R = %08X\n", R);

    return 0;
}
