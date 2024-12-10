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


    void all_binar(char number) {
        char operators[5] = { '+','-','*', '/', '_' };

        char out[19];
        out[18] = '\0';

        char unars[10];

        char binars[5];

        for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
        for (int k = 0; k < 5; k++) {
            binars[0] = operators[i];
            binars[1] = operators[j];
            binars[2] = operators[k];
            all_unar_return(0, unars, number, binars);
        }
    }

    char operators[3] = { '.','!','#' };
    short results[101] = {0};
    int res;

    void all_unar_return(int n, char unars[], char number, char binars[]) {
        if (n == 9) {
            char out[19];
            out[18] = '\0';

            sprintf(out, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", number, unars[0], number, unars[1], binars[0], unars[2], number, unars[3], binars[1], unars[4], number, unars[5], binars[2], unars[6], '.', unars[7], '.', unars[8]);
            //printf("%d\n", calc(out));
            res = calc(out);
            if (res > -1 && res < 100) {
                results[res] = 1;
            }

            sprintf(out, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", number, unars[0], number, unars[1], binars[0], unars[2], number, unars[3], binars[1], unars[4], number, unars[5], '.', unars[6], binars[2], unars[7], '.', unars[8]);
            //printf("%d\n", calc(out));

            res = calc(out);
            if (res > -1 && res < 100) {
                results[res] = 1;
            }

            sprintf(out, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", number, unars[0], number, unars[1], binars[0], unars[2], number, unars[3], '.', unars[4], number, unars[5], binars[1], unars[6], binars[2], unars[7], '.', unars[8]);
            //printf("%d\n", calc(out));

            res = calc(out);
            if (res > -1 && res < 100) {
                results[res] = 1;
            }

            sprintf(out, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", number, unars[0], number, unars[1], '.', unars[2], number, unars[3], binars[0], unars[4], number, unars[5], binars[1], unars[6], binars[2], unars[7], '.', unars[8]);
            //printf("%d\n", calc(out));

            res = calc(out);
            if (res > -1 && res < 100) {
                results[res] = 1;
            }

            sprintf(out, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", number, unars[0], number, unars[1], '.', unars[2], number, unars[3], binars[0], unars[4], number, unars[5], binars[1], unars[6], '.', unars[7], binars[2], unars[8]);
            //printf("%d\n", calc(out));

            res = calc(out);
            if (res > -1 && res < 100) {
                results[res] = 1;
            }

            sprintf(out, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", number, unars[0], number, unars[1], '.', unars[2], number, unars[3], binars[0], unars[4], number, unars[5], '.', unars[6], binars[1], unars[7], binars[2], unars[8]);
            //printf("%d\n", calc(out));

            res = calc(out);
            if (res > -1 && res < 100) {
                results[res] = 1;
            }

            sprintf(out, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", number, unars[0], number, unars[1], '.', unars[2], number, unars[3], '.', unars[4], number, unars[5], binars[0], unars[6], binars[1], unars[7], binars[2], unars[8]);
            //printf("%d\n", calc(out));

            res = calc(out);
            if (res > -1 && res < 100) {
                results[res] = 1;
            }

            sprintf(out, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", number, unars[0], number, unars[1], binars[0], unars[2], number, unars[3], '.', unars[4], number, unars[5], '.', unars[6], binars[1], unars[7], binars[2], unars[8]);
            //printf("%d\n", calc(out));

            res = calc(out);
            if (res > -1 && res < 100) {
                results[res] = 1;
            }

            sprintf(out, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", number, unars[0], number, unars[1], binars[0], unars[2], number, unars[3], '.', unars[4], number, unars[5], binars[1], unars[6], '.', unars[7], binars[2], unars[8]);
            //printf("%d\n", calc(out));

            res = calc(out);
            if (res > -1 && res < 100) {
                results[res] = 1;
            }

            sprintf(out, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", number, unars[0], number, unars[1], binars[0], unars[2], number, unars[3], binars[1], unars[4], number, unars[5], '.', unars[6], '.', unars[7], binars[2], unars[8]);
            //printf("%d\n", calc(out));

            res = calc(out);
            if (res > -1 && res < 100) {
                results[res] = 1;
            }
            return;
        }

        for (int i = 0; i < 3; i++) {
            unars[n] = operators[i];
            all_unar_return(n + 1, unars, number, binars);
        }
    }



    int main() {
        

        // char exp[] = "......................";
        // short out[100];

        char m;
        scanf("%c", &m);

        // exp[0] = m;
        // exp[2] = m;
        // exp[6] = m;
        // exp[10] = m;
        // exp[18] = '\0';

        // per(exp, 0, out, 0, 4);

        all_binar(m);

        for (int i = 0; i < 100; i++) {
            if (results[i] == 1) {
                printf("%d ", i);
            } 
            if (i % 10 == 0) {
                printf("\n");
            }
        }
        // char in_arr[30] = "11!";
        // printf("result = %d\n", calc(in_arr));
    }
