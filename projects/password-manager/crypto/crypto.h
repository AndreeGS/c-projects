#ifndef CRYPTO_H
#define CRYPTO_H

#include "../models/credential.h"

void crypto_encrypt(char *data);
void crypto_decrypt(char *data);
void crypto_encrypt_credential(Credential *credential);
void crypto_decrypt_credential(Credential *credential);

#endif