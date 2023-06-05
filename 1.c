#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file;
    char surname[50];
    int age;

    // Відкриття файлу для запису
    file = fopen("D:\\Zavd2.txt", "w");
    if (file == NULL) {
        printf("Помилка відкриття файлу.");
        return 1;
    }

    // Запис прізвища та віку в файл
    printf("Введіть своє прізвище: ");
    scanf("%s", surname);
    printf("Введіть свій вік: ");
    scanf("%d", &age);
    fprintf(file, "%s %d", surname, age);

    // Закриття файлу
    fclose(file);

    // Відкриття файлу для читання
    file = fopen("D:\\Zavd2.txt", "r");
    if (file == NULL) {
        printf("Помилка відкриття файлу.");
        return 1;
    }

    // Зчитування інформації з файлу
    fscanf(file, "%s %d", surname, &age);

    // Визначення кількості літер у прізвищі
    int surnameLength = strlen(surname);

    // Виведення прізвища у зворотному порядку та віку + 10
    printf("Прізвище у зворотному порядку:\n");
    for (int i = surnameLength - 1; i >= 0; i--) {
        printf("%c\n", surname[i]);
    }
    printf("Вік + 10: %d\n", age + 10);

    // Закриття файлу
    fclose(file);

    return 0;
}
