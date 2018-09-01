#include <stdio.h>

main() {
	printf("Hello World!\n");
	for (int x = 10; x > 0; x--) {
		printf("%d\n", x);
	}
	loopAndPrintNumbers((int) 15);
}

void loopAndPrintNumbers(int num) {
	for (; num > 0; num--) {
		printf("%d\n", num);
	}
}
