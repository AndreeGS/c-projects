#include <string.h>

#include "crypto.h"
#include "../models/credential.h"

#define KEY 123

void crypto_encrypt(char *data) {
    for (size_t i = 0; i < strlen(data); i++) {
        data[i] ^= KEY;
    }
}

void crypto_decrypt(char *data) {
    crypto_encrypt(data); // XOR encryption is symmetric
}

void crypto_encrypt_credential(Credential *credential) {
    crypto_encrypt(credential->service);
    crypto_encrypt(credential->username);
    crypto_encrypt(credential->password);
}

void crypto_decrypt_credential(Credential *credential) {
    crypto_decrypt(credential->service);
    crypto_decrypt(credential->username);
    crypto_decrypt(credential->password);
}