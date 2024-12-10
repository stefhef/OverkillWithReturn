#include <stdio.h>

void all_unar() {
    char operators[3] = { '.','!','#' };
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                for (int m = 0; m < 3; m++) {
                    for (int n = 0; n < 3; n++) {
                        for (int o = 0; o < 3; o++) {
                            for (int p = 0; p < 3; p++) {
                                for (int q = 0; q < 3; q++) {
                                    for (int r = 0; r < 3; r++) {
                                        printf("%c%c%c%c%c%c%c%c%c\n", operators[i], operators[j], operators[k], operators[m], operators[n], operators[o], operators[p], operators[q], operators[r]);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}