void AvolittyHasherA(unsigned short int *a, unsigned short int *b, unsigned short int *c, unsigned short int d, unsigned short int e, unsigned char *f) {
	unsigned short int g = *b;
	unsigned short int h = *c;
	unsigned short int i = 0U;
	unsigned short int j = 0U;

	while (e != i) {
		g = (unsigned short int) f[i++] + ((((g + 2U) >> 1U) + g) & 8191U) + 2U;
		j = h++ & d;
		a[j] = (a[j] + g) & 1023U;
	}

	*b = g;
	*c = h;
	return;
}

void AvolittyHasherB(unsigned short int *a, unsigned short int b, unsigned short int c, unsigned char *d) {
	unsigned short int e = 0U;
	const unsigned char f[16U] = {48U, 49U, 50U, 51U, 52U, 53U, 54U, 55U, 56U, 57U, 97U, 98U, 99U, 100U, 101U, 102U};

	while (c != 0U) {
		a[--c] = b;
		b = (a[c] + a[e] + (((b + c) >> 1U) + c) & 8191U) + 2U;
		a[e++] = b;
		d[c] = f[b & 15U];
	}

	return;
}
