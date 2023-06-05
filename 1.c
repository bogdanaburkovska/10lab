#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countWordOccurrences(const char *filename, const char *word) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Помилка відкриття файлу\n");
        return -1;
    }

    int count = 0;
    char buffer[256];

    while (fscanf(file, "%s", buffer) == 1) {
        if (strcmp(buffer, word) == 0) {
            count++;
        }
    }

    fclose(file);

    return count;
}

int main() {
    const char *filename = "text.txt";
    const char *word = "привіт";

    int occurrences = countWordOccurrences(filename, word);

    if (occurrences == -1) {
        return 1;
    }

    printf("Слово '%s' зустрічається %d раз(ів) у файлі '%s'\n", word, occurrences, filename);

    return 0;
}
