#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <Windows.h>

// Функція для підрахунку груп ", -" у рядку
int countCommaDash(const char* line) {
    int count = 0;
    for (int i = 1; line[i + 1] != '\0'; i++) {
        if (line[i - 1] == ',' && line[i + 1] == '-') {
            count++;
        }
    }
    return count;
}

// Функція для підрахунку груп ", -" у файлі
int countCommaDashInFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Не вдалося відкрити файл: %s\n", filename);
        return 0;
    }

    int totalCount = 0;
    char line[256]; // Буфер для зчитування рядків

    // Зчитуємо файл пострічно і підраховуємо кількість груп
    while (fgets(line, sizeof(line), file) != NULL) {
        totalCount += countCommaDash(line);
    }

    fclose(file); // Закриваємо файл
    return totalCount;
}

// Головна функція
int main() {
    SetConsoleCP(1251);        // Встановлення кодування для вводу (кирилиця)
    SetConsoleOutputCP(1251); // Встановлення кодування для виводу (кирилиця)

    const char* filename = "t.txt"; // Назва файлу для аналізу

    // Викликаємо функцію підрахунку
    int result = countCommaDashInFile(filename);

    // Вивід результатів
    if (result > 0) {
        printf("У файлі знайдено %d груп(и) ', -'.\n", result);
    }
    else {
        printf("У файлі НЕ знайдено груп ', -'.\n");
    }

    return 0;
}
