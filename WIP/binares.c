#include <stdio.h>

char out[] = ".....";
char oper[] = ".+-/*_";

void per(int n, int count) {
	if (count == 3) {
		printf("%s\n", out);
		return;
	}
	else if (n == 5) return;

	for (int i = 0; i < 6; i++) {
		out[n] = oper[i];
		if (i == 1) count++;
		per(n + 1, count);
	}
}

int main(int argc, char* argv[])
{
	per(0, 0);
}