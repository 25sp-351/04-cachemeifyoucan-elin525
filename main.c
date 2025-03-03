#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rod_cut.h"
#include "cache.h"

#define MAX_PIECES 100

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    // open the file
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    Piece pieces[MAX_PIECES];
    int count = 0;

    // read the pieces from the file
    while (fscanf(file, "%d ,%d", &pieces[count].length, &pieces[count].value) == 2) {
        count++;
        if (count >= MAX_PIECES) break;
    }
    fclose(file);

    init_cache();

    int rod_length;
    // read the rod length from the user
    while (scanf("%d", &rod_length) == 1) {
        int max_value = check_cache(rod_length);
        if (max_value == -1) {
            max_value = rod_cut(rod_length, pieces, count);
            insert_cache(rod_length, max_value);
        }

        printf("Value: %d\n", max_value);
    }

    // free the cache
    free_cache();
    return 0;
}
