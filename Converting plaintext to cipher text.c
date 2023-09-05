#include <stdio.h>
#include <string.h>
void caesar_encrypt(char plaintext[], int key) {
    int i = 0;
    char ch;

    while (plaintext[i]) {
        ch = plaintext[i];

        if (ch >= 'A' && ch <= 'Z') {
            ch = ((ch - 'A' + key) % 26) + 'A';
        } else if (ch >= 'a' && ch <= 'z') {
            ch = ((ch - 'a' + key) % 26) + 'a';
        }

        plaintext[i] = ch;
        i++;
    }
}

void caesar_decrypt(char ciphertext[], int key) {
    int i = 0;
    char ch;

    while (ciphertext[i]) {
        ch = ciphertext[i];

        if (ch >= 'A' && ch <= 'Z') {
            ch = ((ch - 'A' - key + 26) % 26) + 'A';
        } else if (ch >= 'a' && ch <= 'z') {
            ch = ((ch - 'a' - key + 26) % 26) + 'a';
        }

        ciphertext[i] = ch;
        i++;
    }
}

int main() {
    char b[100];
    int key;

    printf("Enter the plaintext: ");
    scanf("%s",&b);

    printf("Enter the key (0-25): ");
    scanf("%d", &key);

    caesar_encrypt(b, key);
    printf("Encrypted text: %s\n",b);

    caesar_decrypt(b, key);
    printf("Decrypted text: %s\n",b);

    return 0;
}
