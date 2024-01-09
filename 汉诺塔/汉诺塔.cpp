#include <stdio.h>
#include <stdlib.h>



int main() {
	void hanoi(int n, char x = 'A', char y = 'B', char z = 'C');
	hanoi(6);
	return EXIT_SUCCESS;
}

void hanoi(int n, char x = 'A', char y = 'B', char z = 'C') {
	if (n == 0) {

	}
	else {
		hanoi(n - 1, x, z, y);
		printf("%c - > %c, ", x, y);
		hanoi(n - 1, z,y,x);
	}
};