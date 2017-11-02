#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <newton.h>

#define EPS 1e-7

int main(int argc, char *argv[]) {

	if (atoi(argv[1]) == 1) {//1
		Newton(f, atof(argv[2]));	
	}
	else if (atoi(argv[1]) == 2) {//2
		Newton(g, atof(argv[2]));	
	}
	return 0;
}


