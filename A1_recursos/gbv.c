#include "gbv.h"
#include <stdio.h>

/*int gbv_create(const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) return -1;
    // Optionally write header or metadata here
    fclose(fp);
    return 0;
}*/
int gbv_create(const char *filename) {
    FILE *fp = fopen(filename, "rb"); //ponteiro para FILE para abrir novo arquivo
    if (fp) {
        fclose(fp);
        // arquivo existe, depois substituir pelo novo, não será fclose
        return -1;
    }
    fp = fopen(filename, "wb");
    if (!fp) return -1; //se não consegui abrir o arquivo retorna -1
    int count = 0;
    fwrite(&count, sizeof(int), 1, fp);
    fclose(fp);
    return 0;
}

int gbv_open(Library *lib, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) return -1;

    // Read header or metadata here

    fclose(fp);
    return 0;
}