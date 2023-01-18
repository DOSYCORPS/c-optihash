void AvolittyHasherA(unsigned short int *a, unsigned short int *b, unsigned short int *c, unsigned short int d, unsigned short int e, unsigned char *f) {
	unsigned short int g = *b;
	unsigned short int h = *c;
	unsigned short int i = 0U;
	unsigned short int j = 0U;

	while (e != i) {
		g = (((((unsigned short int) f[i++]) + g + ((g + 2U) >> 1U)) & 16383U) + 2U);
		j = (h++ & d);
		a[j] = ((a[j] + g) & 1023U);
	}

	*b = g;
	*c = h;
	return;
}

void AvolittyHasherB(unsigned short int *a, unsigned short int b, unsigned short int c, unsigned char *d) {
	unsigned short int e = 0U;

	while (b != 0U) {
		a[--b] = c;
		c = (((a[b] + a[e] + b + ((b + c) >> 1U)) & 16383U) + 2U);
		a[e++] = c;
		d[b] = (c & 15U);
	}

	return;
}
