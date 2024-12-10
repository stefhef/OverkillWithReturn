#include <stdio.h>

char operators[3] = { '.','!','#' };

void all_unar_return(int n, char out[]) {
    if (n == 9) {
        calc(out);
        return;
    }

    for (int i = 0; i < 3; i++) {
        out[n] = operators[i];
        all_unar_return(n + 1, out);
    }
}



void calc(char* in_arr) {}