#include <stdio.h>
#include <string.h>

#define MAX_GENOME 30000
#define MAX_LINE   1024

int main(void) {
    FILE *fp = fopen("PRIMO SEQUENZIAMENTO.fasta", "r");
    if (fp == NULL) {
        perror("Errore apertura file");
        return 1;
    }

    char genome[MAX_GENOME + 1];  // +1 per '\0'
    char line[MAX_LINE];
    int len = 0;

    while (fgets(line, MAX_LINE, fp)) {

        // Salta intestazione
        if (line[0] == '>') continue;

        // Rimuove newline
        line[strcspn(line, "\n")] = '\0';

        // Copia caratteri uno a uno
        for (int i = 0; line[i] != '\0'; i++) {
            if (len < MAX_GENOME) {
                genome[len++] = line[i];
            }
        }
    }

    genome[len] = '\0';
    fclose(fp);

    printf("Genoma letto (%d bp)\n", len);
    // printf("%s\n", genome);  // opzionale

    return 0;
}
