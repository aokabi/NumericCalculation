#include<stdio.h>

void func(int b[4]) {
	printf("%p\n", b);
}
void func2(int b[]) {
	printf("%p\n", b);
}
void func3(int *b) {
	printf("%p\n", b);
}

void main() {
	int a[4] = {1, 2, 4, 6};
	func(a);
	func2(a);
	func3(a);
}
