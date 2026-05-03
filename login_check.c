#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>

void sha256(const char *input, char *output_hex) {
    unsigned char hash[32];
    unsigned int len;

    EVP_MD_CTX *ctx = EVP_MD_CTX_new();

    EVP_DigestInit_ex(ctx, EVP_sha256(), NULL);
    EVP_DigestUpdate(ctx, input, strlen(input));
    EVP_DigestFinal_ex(ctx, hash, &len);

    EVP_MD_CTX_free(ctx);

    for(int i = 0; i < len; i++)
        sprintf(output_hex + i*2, "%02x", hash[i]);
}

int main() {

    char password[100];
    char hash_hex[65];
    char stored_hash[] = "8c6976e5b5410415bde908bd4dee15dfb167a9c873fc4bb8a81f6f2ab448a918";

    printf("Enter password: ");
    scanf("%s", password);
    sha256(password, hash_hex);

    if(strcmp(hash_hex, stored_hash) == 0)
        printf("LOGIN SUCCESSFUL!\n");
    else
        printf("WRONG PASSWORD!\n");
    return 0;
}