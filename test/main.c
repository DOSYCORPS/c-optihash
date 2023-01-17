#include <stdio.h>
#include "../src/avolitty-hasher.h"

int main(int a, char *b[]) {
	FILE *c;
	size_t d = 1024;
	size_t e = 1;
	size_t f = d;
	unsigned short int g[16U];
	unsigned short int h = 16U;
	unsigned short int i = h;
	unsigned short int j = 0U;
	unsigned short int k = 0U;
	unsigned short int *l = &i;
	unsigned short int *m = &j;
	unsigned char n[1024U];
	unsigned char o[16U];

	if (a == 1) {
		printf("Error hashing file without required file name argument.");
		return a;
	}

	c = fopen((const char *) b[1], (const char *) "rb");

	if (c == 0) {
		printf("Error reading file \"%s\".", b[1]);
		return a;
	}

	while (h != 0U) {
		g[--h] = 254U;
	}

	h = --i;

	while (d == f) {
		f = fread(n, e, d, c);
		k = (unsigned short int) f;
		AvolittyHasherA(g, l, m, h, k, n);
	}

	if (feof(c) == 0) {
		printf("Error hashing file \"%s\".", b[1]);
		return a;
	}

	fclose(c);
	AvolittyHasherB(g, ++h, i, o);

	while (h != 0U) {
		printf("%c", o[--h]);
	}

	return a;
}
