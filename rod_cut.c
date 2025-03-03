#include <stdio.h>
#include <stdlib.h>
#include "rod_cut.h"

int rod_cut(int rod_length, Piece pieces[], int n) {
    // allocate memory
    int *dp = (int *)malloc((rod_length + 1) * sizeof(int));
    // if malloc fails, return -1
    if (!dp) return -1;

    // initialize the dp array
    for (int i = 0; i <= rod_length; i++) dp[i] = 0;

    // calculate the maximum value for each rod length
    for (int i = 1; i <= rod_length; i++) {
        for (int j = 0; j < n; j++) {
            if (pieces[j].length <= i) {
                int new_val = dp[i - pieces[j].length] + pieces[j].value;
                if (new_val > dp[i]) dp[i] = new_val;
            }
        }
    }

    // store the result
    int result = dp[rod_length];
    // free the memory
    free(dp);
    return result;
}
