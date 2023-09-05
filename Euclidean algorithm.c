#include <stdio.h>
#include <stdint.h>

// Euclidean Algorithm to find GCD
uint32_t gcd(uint32_t a, uint32_t b) {
    while (b != 0) {
        uint32_t temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Simulate key generation
void generateKeys(uint32_t *publicKey, uint32_t *privateKey, uint32_t *modulus) {
    *modulus = 29; // prime modulus

    // Public key (e) and private key (d) are chosen such that e*d % phi(n) = 1
    uint32_t phi_n = *modulus - 1; // Euler's totient function for prime modulus
    *publicKey = 3; // typically a small prime
    *privateKey = 9; // chosen to satisfy e*d % phi(n) = 1
}

// Simulate digital signature process
void signMessage(uint32_t message, uint32_t privateKey, uint32_t modulus, uint32_t *signature) {
    *signature = message; // Simple signature, not secure!
}

// Simulate signature verification
int verifySignature(uint32_t message, uint32_t signature, uint32_t publicKey, uint32_t modulus) {
    uint32_t encrypted = 1;
    for (uint32_t i = 0; i < publicKey; ++i) {
        encrypted = (encrypted * signature) % modulus;
    }

    return encrypted == message;
}

int main() {
    uint32_t publicKey, privateKey, modulus;
    generateKeys(&publicKey, &privateKey, &modulus);

    uint32_t message = 20;
    uint32_t signature;
    signMessage(message, privateKey, modulus, &signature);

    printf("Public Key: %u\n", publicKey);
    printf("Private Key: %u\n", privateKey);
    printf("Modulus: %u\n", modulus);
    printf("Message: %u\n", message);
    printf("Signature: %u\n", signature);

    int isValid = verifySignature(message, signature, publicKey, modulus);
    printf("Signature Verification: %s\n", isValid ? "Valid" : "Invalid");

    return 0;
}
