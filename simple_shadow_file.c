#include <openssl/rand.h>

void generate_salt(unsigned char *salt, int length) {
    RAND_bytes(salt, length);
}

void to_hex(unsigned char *in, int len, char *out) {
    for (int i = 0; i < len; i++) {
        sprintf(out + (i * 2), "%02x", in[i]);
    }

    if (strcmp(stored_hash, computed_hash) == 0) {
        printf("Login successful\n");
    } else {
        printf("Wrong password\n");
    }
}