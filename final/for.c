#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

int last_index = -1;

void bin_result_to_stack(int* stack, int result_to, char op) {
    // printf("%d %c %d = %d\n", stack[last_index - 1], op, stack[last_index], result_to);
    stack[last_index] = 0;
    stack[--last_index] = result_to;
}

int Execute(char op, int* stack) {
    switch (op)
    {
    case '+':
        bin_result_to_stack(stack, stack[last_index - 1] + stack[last_index], op);
        return 1;
    case '-':
        bin_result_to_stack(stack, stack[last_index - 1] - stack[last_index], op);
        return 1;
    case '*':
        bin_result_to_stack(stack, stack[last_index - 1] * stack[last_index], op);
        return 1;
    case '/':
        if (stack[last_index] != 0) {
            bin_result_to_stack(stack, stack[last_index - 1] / stack[last_index], op);
            return 1;
        }
        return -1;
    case '#':
        if (stack[last_index] >= 0) {
            // printf("sqrt(%d) = %d\n", stack[last_index], (int)sqrt(stack[last_index]));
            stack[last_index] = sqrt(stack[last_index]);
            return 1;
        }
        return -1;
    case '!':
        if (stack[last_index] >= 0) {
            int in = stack[last_index];
            int out = 1;
            if (in < 0 || in > 25)
                return -1;
            while (in > 1) {
                out *= in;
                --in;
            }
            // printf("%d! = %d\n", stack[last_index], out);
            stack[last_index] = out;
            return 1;
        }
    case '_':
    {
        int c = 0;
        if (stack[last_index - 1] < 0 || stack[last_index] < 0) return -1;
        else if (stack[last_index] == 0) c = 1;
        else for (int tmp = stack[last_index]; tmp != 0; c++) tmp = tmp / 10;
        bin_result_to_stack(stack, stack[last_index - 1] * (int)pow((double)10, (double)c) + stack[last_index], op);
        return 1;
    }
    default:
        return -1;
    }
}

int calc(char* in_arr) {
    int stack[30] = { 0 };
    int lenght = strlen(in_arr);
    for (int i = 0; i < lenght; i++) {
        if (in_arr[i] >= '0' && in_arr[i] <= '9') {
            stack[++last_index] = in_arr[i] - '0';
        }
        else {
            Execute(in_arr[i], stack);
        }
    }
    last_index = -1;
    return stack[0];
}


int get_index(int number) {
    switch (number) {
    case 20: return 16;
    case 16: return 14;
    default: return number;
    }
}

void per(char exp[], int n, short out[], int start_unar, int start_bin) {
    if (n == 3 && start_unar == 8) {
        // int res;
         printf("%s = \n", exp);
        int res = calc(exp);
         printf("%d\n", res);
        if (res > -1 && res < 100) {
            out[res] = 1;
        }
        return;
    }

    char actions[] = { '+', '-', '*', '/', '_' };

    char special[] = { '.', '!', '#' };

    if (start_bin > 12) {
        for (int j = 0; j < 3; j++)
            for (int k = start_unar; k < 9; k++) {
                exp[1 + 2 * k] = special[j];
                per(exp, n, out, k + 1, start_bin);
            }
    }
    else {
        for (int j = 0; j < 3; j++)
            for (int k = start_unar; k < 9; k++) {
                exp[1 + 2 * k] = special[j];
                for (int m = start_bin; m < start_bin + 12; m += 4)
                    for (int i = 0; i < 5; i++) {
                        exp[get_index(m)] = actions[i];
                        per(exp, n + 1, out, k + 1, m + 4);
                    }
            }
    }
}




void all_binar(char number, short results[]) {
    char unars[3] = { '.','!','#' };
    char binars[5] = { '+','-','*', '/', '_' };

    char out[19];
    out[18] = '\0';

    int res;

    for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
    for (int k = 0; k < 5; k++) {


        for (int a = 0; a < 3; a++)
        for (int b = 0; b < 3; b++)
        for (int c = 0; c < 3; c++)
        for (int m = 0; m < 3; m++)
        for (int n = 0; n < 3; n++)
        for (int o = 0; o < 3; o++)
        for (int p = 0; p < 3; p++)
        for (int q = 0; q < 3; q++)
        for (int r = 0; r < 3; r++) {
            sprintf(out, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", number, unars[a], number, unars[b], binars[i], unars[c], number, unars[m], binars[j], unars[n], number, unars[o], binars[k], unars[p], '.', unars[q], '.', unars[r]);
            //printf("%d\n", calc(out));
            res = calc(out);
            if (res > -1 && res < 100) {
                results[res] = 1;
            }

            sprintf(out, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", number, unars[a], number, unars[b], binars[i], unars[c], number, unars[m], binars[j], unars[n], number, unars[o], '.', unars[p], binars[k], unars[q], '.', unars[r]);
            //printf("%d\n", calc(out));

            res = calc(out);
            if (res > -1 && res < 100) {
                results[res] = 1;
            }

            sprintf(out, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", number, unars[a], number, unars[b], binars[i], unars[c], number, unars[m], '.', unars[n], number, unars[o], binars[j], unars[p], binars[k], unars[q], '.', unars[r]);
            //printf("%d\n", calc(out));

            res = calc(out);
            if (res > -1 && res < 100) {
                results[res] = 1;
            }

            sprintf(out, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", number, unars[a], number, unars[b], '.', unars[c], number, unars[m], binars[i], unars[n], number, unars[o], binars[j], unars[p], binars[k], unars[q], '.', unars[r]);
            //printf("%d\n", calc(out));

            res = calc(out);
            if (res > -1 && res < 100) {
                results[res] = 1;
            }

            sprintf(out, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", number, unars[a], number, unars[b], '.', unars[c], number, unars[m], binars[i], unars[n], number, unars[o], binars[j], unars[p], '.', unars[q], binars[k], unars[r]);
            //printf("%d\n", calc(out));

            res = calc(out);
            if (res > -1 && res < 100) {
                results[res] = 1;
            }

            sprintf(out, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", number, unars[a], number, unars[b], '.', unars[c], number, unars[m], binars[i], unars[n], number, unars[o], '.', unars[p], binars[j], unars[q], binars[k], unars[r]);
            //printf("%d\n", calc(out));

            res = calc(out);
            if (res > -1 && res < 100) {
                results[res] = 1;
            }

            sprintf(out, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", number, unars[a], number, unars[b], '.', unars[c], number, unars[m], '.', unars[n], number, unars[o], binars[i], unars[p], binars[j], unars[q], binars[k], unars[r]);
            //printf("%d\n", calc(out));

            res = calc(out);
            if (res > -1 && res < 100) {
                results[res] = 1;
            }

            sprintf(out, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", number, unars[a], number, unars[b], binars[i], unars[c], number, unars[m], '.', unars[n], number, unars[o], '.', unars[p], binars[j], unars[q], binars[k], unars[r]);
            //printf("%d\n", calc(out));

            res = calc(out);
            if (res > -1 && res < 100) {
                results[res] = 1;
            }

            sprintf(out, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", number, unars[a], number, unars[b], binars[i], unars[c], number, unars[m], '.', unars[n], number, unars[o], binars[k], unars[p], '.', unars[q], binars[k], unars[r]);
            //printf("%d\n", calc(out));

            res = calc(out);
            if (res > -1 && res < 100) {
                results[res] = 1;
            }

            sprintf(out, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", number, unars[a], number, unars[b], binars[i], unars[c], number, unars[m], binars[j], unars[n], number, unars[o], '.', unars[p], '.', unars[q], binars[k], unars[r]);
            //printf("%d\n", calc(out));

            res = calc(out);
            if (res > -1 && res < 100) {
                results[res] = 1;
            }
        }
    }
}

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



int main() {
    

    char exp[] = "......................";
    short out[100];

    char m;
    scanf("%c", &m);

    exp[0] = m;
    exp[2] = m;
    exp[6] = m;
    exp[10] = m;
    exp[18] = '\0';

    per(exp, 0, out, 0, 4);

    //all_binar('9', out);

    for (int i = 0; i < 100; i++) {
        if (out[i] == 1) {
            printf("%d ", i);
        } 
        if (i % 10 == 0) {
            printf("\n");
        }
    }
    // char in_arr[30] = "11!";
    // printf("result = %d\n", calc(in_arr));
}
