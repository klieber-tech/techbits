#include <stdio.h>

int bad_function(char *input) {
	printf(input);
}

int main(int argc, char *argv[]) {
	if (argc >= 2) {
		bad_function(argv[1]);
	}
}
