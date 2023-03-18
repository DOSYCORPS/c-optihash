#include <stdio.h>
#include "../src/avolitty-hasher.h"

int main(int a, char * * b) {
	FILE * c;
	size_t d = 1024;
	size_t e = 1;
	size_t f = d;
	unsigned short g[16];
	unsigned short h = 16;
	unsigned short i = h;
	unsigned short j = 0;
	unsigned short * k = &i;
	unsigned short * l = &j;
	unsigned char m[1024];
	unsigned char n[16];

	if (a != 0) {
		c = fopen((const char *) b[1], (const char *) "rb");

		if (c != ((void *) 0)) {
			while (h != 0) {
				h--;
				g[h] = 254;
			}

			i--;
			h = i;

			while (d == f) {
				f = fread(m, e, d, c);
				AvolittyHasherA(g, k, l, h, (unsigned short) f, m);
			}

			if (feof(c) != 0) {
				fclose(c);
				h++;
				AvolittyHasherB(g, h, i, n);

				while (h != 0) {
					h--;
					printf("%x", n[h]);
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
