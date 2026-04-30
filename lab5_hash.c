#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>

void calculate_sha256(const char *message, unsigned char *digest, unsigned int *digest_len) {
    EVP_MD_CTX *mdctx;

    if((mdctx = EVP_MD_CTX_new()) == NULL) {
        printf("Error creating context\n");
        return;
    }

    EVP_DigestInit_ex(mdctx, EVP_sha256(), NULL);
    EVP_DigestUpdate(mdctx, message, strlen(message));
    EVP_DigestFinal_ex(mdctx, digest, digest_len);

    EVP_MD_CTX_free(mdctx);
}

int main() {
    char message[] = "CyberSecurity";
    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int hash_len;

    printf("Original Text: %s\n", message);

    calculate_sha256(message, hash, &hash_len);

    printf("SHA-256 Digest: ");
    for(int i = 0; i < hash_len; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}