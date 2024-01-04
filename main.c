#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 100 * 1024 * 1024 // 100 MB

void measure_memcpy_time(size_t size) {
    char *src = malloc(size);
    char *dest = malloc(size);

    if (src == NULL || dest == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    clock_t start_time = clock();

    // Perform memcpy
    memcpy(dest, src, size);

    clock_t end_time = clock();

    // Calculate elapsed time in milliseconds
    double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1000;

    printf("Size: %zu bytes, Time taken: %.6f ms\n", size, elapsed_time);

    free(src);
    free(dest);
}

int main() {
    printf("Measuring memcpy time for increasing sizes up to 100MB...\n");

    for (size_t size = 1024; size <= MAX_SIZE; size *= 2) {
        measure_memcpy_time(size);
    }

    return 0;
}
