#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>

void calculate_sha256(const char *message, unsigned char *digest, unsigned int *digest_len) {
    EVP_MD_CTX *mdctx;

    mdctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(mdctx, EVP_sha256(), NULL);
    EVP_DigestUpdate(mdctx, message, strlen(message));
    EVP_DigestFinal_ex(mdctx, digest, digest_len);

    EVP_MD_CTX_free(mdctx);
}

int main() {
    char password[100];
    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int hash_len;

    char computed_hash_string[65];
    char stored_hash[] = "8c6976e5b5410415bde908bd4dee15dfb167a9c873fc4bb8a81f6f2ab448a918";

    printf("Enter password: ");
    scanf("%99s", password);

    calculate_sha256(password, hash, &hash_len);

    for(int i = 0; i < hash_len; i++) {
        sprintf(&computed_hash_string[i * 2], "%02x", hash[i]);
    }

    computed_hash_string[64] = '\0';

    if (strcmp(computed_hash_string, stored_hash) == 0) {
        printf("LOGIN SUCCESSFUL!\n");
    } else {
        printf("WRONG PASSWORD!\n");
    }

    return 0;
}