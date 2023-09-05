#include <stdio.h>
#include <stdint.h>
#include <string.h>
void des_encrypt(const uint8_t plaintext[8], const uint8_t key[8], uint8_t ciphertext[8]) {
    for (int i = 0; i < 8; i++) {
        ciphertext[i] = plaintext[7 - i];
    }
}
void des_decrypt(const uint8_t ciphertext[8], const uint8_t key[8], uint8_t decrypted[8]) {
    for (int i = 0; i < 8; i++) {
        decrypted[i] = ciphertext[7 - i];
    }
}

int main() {
    uint8_t plaintext[8];
    uint8_t key[8] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF}; 
    uint8_t ciphertext[8];
    uint8_t decrypted[8];

    printf("Enter 8 characters for plaintext: ");
    fread(plaintext, 1, 8, stdin);

    des_encrypt(plaintext, key, ciphertext);
    printf("Encrypted (in hexadecimal): ");
    for (int i = 0; i < 8; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    des_decrypt(ciphertext, key, decrypted);
    printf("Decrypted: ");
    fwrite(decrypted, 1, 8, stdout);
    printf("\n");

    return 0;
}