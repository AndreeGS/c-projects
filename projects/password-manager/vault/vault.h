#ifndef VAULT_H
#define VAULT_H

#include "../models/credential.h"

typedef struct {
    Credential *items;
    int count;
    int capacity;
} Vault;

void vault_init(Vault *v);
void vault_add(Vault *v);
void vault_list(Vault *v);
void vault_delete(Vault *v);
Credential* vault_find(Vault *v, const char *service);
void vault_free(Vault *v);
void vault_exit(Vault *v);

#endif