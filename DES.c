#include <stdio.h>
#include <string.h>

int IP[64] = {
    58,50,42,34,26,18,10,2, 60,52,44,36,28,20,12,4,
    62,54,46,38,30,22,14,6, 64,56,48,40,32,24,16,8,
    57,49,41,33,25,17,9,1,  59,51,43,35,27,19,11,3,
    61,53,45,37,29,21,13,5, 63,55,47,39,31,23,15,7 };

int FP[64] = {
    40,8,48,16,56,24,64,32, 39,7,47,15,55,23,63,31,
    38,6,46,14,54,22,62,30, 37,5,45,13,53,21,61,29,
    36,4,44,12,52,20,60,28, 35,3,43,11,51,19,59,27,
    34,2,42,10,50,18,58,26, 33,1,41,9,49,17,57,25 };


void bytes_to_bits(unsigned char *bytes, int *bits) {
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            bits[i * 8 + j] = (bytes[i] >> (7 - j)) & 1;
}


void bits_to_bytes(int *bits, unsigned char *bytes) {
    for (int i = 0; i < 8; i++) {
        bytes[i] = 0;
        for (int j = 0; j < 8; j++)
            bytes[i] = bytes[i] * 2 + bits[i * 8 + j];
    }
}


void permute(int *in, int *out, int *table) {
    for (int i = 0; i < 64; i++)
        out[i] = in[table[i] - 1];
}


void des_process(unsigned char *block, unsigned char *key) {
    int bits[64], shuffled[64], joined[64], result[64];
    int keybits[64];
    int L[32], R[32], newR[32];

    bytes_to_bits(block, bits);
    bytes_to_bits(key, keybits);      
    permute(bits, shuffled, IP);        

    for (int i = 0; i < 32; i++) {    
        L[i] = shuffled[i];
        R[i] = shuffled[i + 32];
    }

    for (int round = 0; round < 16; round++) {  
        for (int i = 0; i < 32; i++)
            newR[i] = L[i] ^ R[i] ^ keybits[i];  
        for (int i = 0; i < 32; i++) {
            L[i] = R[i];                        
            R[i] = newR[i];
        }
    }

    for (int i = 0; i < 32; i++) {     
        joined[i] = R[i];
        joined[i + 32] = L[i];
    }

    permute(joined, result, FP);     
    bits_to_bytes(result, block);
}

int main(void) {
    unsigned char key[8] = {0x13,0x34,0x57,0x79,0x9B,0xBC,0xDF,0xF1};
    char input[9];

    printf("Enter plaintext (max 8 chars): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    unsigned char block[8] = {0};
    memcpy(block, input, strlen(input));

    printf("Plaintext: %s\n", input);

    des_process(block, key);                     
    printf("Encrypted: ");
    for (int i = 0; i < 8; i++) printf("%02X ", block[i]);
    printf("\n");

    des_process(block, key);                      
    printf("Decrypted: ");
    for (int i = 0; i < (int)strlen(input); i++) printf("%c", block[i]);
    printf("\n");

    return 0;
}
