#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char **argv) {
    // Проверяем, что введён ровно один аргумент
    if (argc != 2) { 
        fprintf(stderr, "Укажите адрес файла.\n");
        return 1;
    }
    
    // Получаем информацию о файле
    struct stat fileInfo;
    if (stat(argv[1], &fileInfo) != 0) {
        fprintf(stderr, "Ошибка: файл '%s' не существует или недоступен.\n", argv[1]);
        return 1;
    }
    
    // Выводим размер файла в байтах
    printf("%ld\n", fileInfo.st_size);
    return 0;
}
