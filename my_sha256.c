#include <stdio.h>
#include <stdlib.h>
#include <openssl/evp.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        perror("File open error");
        return 1;
    }

    EVP_MD_CTX *mdctx = EVP_MD_CTX_new();
    const EVP_MD *md = EVP_sha256();

    EVP_DigestInit_ex(mdctx, md, NULL);

    unsigned char buffer[BUFFER_SIZE];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
        EVP_DigestUpdate(mdctx, buffer, bytesRead);
    }

    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int hash_len;

    EVP_DigestFinal_ex(mdctx, hash, &hash_len);

    for (unsigned int i = 0; i < hash_len; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    EVP_MD_CTX_free(mdctx);
    fclose(file);

    return 0;
}