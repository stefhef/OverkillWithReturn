#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

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
