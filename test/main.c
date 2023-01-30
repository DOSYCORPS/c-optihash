#include <stdio.h>
#include "../src/avolitty-hasher.h"

int main(int a, char * * b) {
	FILE * c;
	size_t d;
	size_t e;
	size_t f;
	unsigned short int g[((unsigned short int) 16U)];
	unsigned short int h;
	unsigned short int i;
	unsigned short int j;
	unsigned short int k;
	unsigned short int * l;
	unsigned short int * m;
	unsigned char n[((unsigned short int) 1024U)];
	unsigned char o[((unsigned short int) 16U)];
	d = ((size_t) 1024);
	e = ((size_t) 1);
	f = d;
	h = ((unsigned short int) 16U);
	i = h;
	j = ((unsigned short int) 0U);
	k = ((unsigned short int) 0U);
	l = &i;
	m = &j;

	if (a == ((int) j)) {
		printf("Error hashing file without required file name argument.");
		return a;
	}

	c = fopen((const char *) b[e], (const char *) "rb");

	if (c == ((void *) 0)) {
		printf("Error reading file \"%s\".", b[e]);
		return a;
	}

	k = ((unsigned short int) 254U);

	while (h != j) {
		h--;
		g[h] = k;
	}

	i--;
	h = i;

	while (d == f) {
		f = fread(n, e, d, c);
		k = ((unsigned short int) f);
		AvolittyHasherA(g, l, m, h, k, n);
	}

	if (feof(c) == ((int) 0)) {
		printf("Error hashing file \"%s\".", b[1]);
		return a;
	}

	fclose(c);
	h++;
	AvolittyHasherB(g, h, i, o);
	i = ((unsigned short int) 0U);

	while (h != i) {
		h--;
		printf("%x", o[h]);
	}

	return a;
}
