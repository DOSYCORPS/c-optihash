#include <stdio.h>
#include "../src/hasher.h"

int main(int a, char * * b) {
	FILE * c;
	unsigned short d[16];
	unsigned short e = 1024;
	unsigned short f = 16;
	unsigned short g = f;
	unsigned short h = 0;
	unsigned short * i = &g;
	unsigned short * j = &h;
	unsigned char k[1024];
	unsigned char l[16];

	if (a != 0) {
		c = fopen(b[1], "rb");

		if (c != (void *) 0) {
			while (f != 0) {
				f--;
				d[f] = 254;
			}

			f = g;
			g--;

			while (e == 1024) {
				e = fread(k, 1, 1024, c);
				hasherI(d, i, j, e, k);
			}

			if (feof(c) != 0) {
				fclose(c);
				hasherL(d, f, g, l);

				while (f != 0) {
					f--;
					printf("%x", l[f]);
				}
			} else {
				printf("Error hashing file \"%s\".", b[1]);
			}
		} else {
			printf("Error reading file \"%s\".", b[1]);
		}
	} else {
		printf("Error hashing file without required file name argument.");
	}

	return 0;
}
