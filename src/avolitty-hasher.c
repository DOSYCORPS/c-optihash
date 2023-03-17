void AvolittyHasherA(unsigned short int * a, unsigned short int * b, unsigned short int * c, unsigned short int d, unsigned short int e, unsigned char * f) {
	unsigned short int g = *b;
	unsigned short int h = *c;
	unsigned short int i = 0;
	unsigned short int j;

	while (e != i) {
		g = (((((f[i] + g) + ((g + 2) >> 1))) & 16383) + 2);
		j = (h & d);
		a[j] = ((a[j] + g) & 1023);
		h++;
		i++;
	}

	*b = g;
	*c = h;
	return;
}

void AvolittyHasherB(unsigned short int * a, unsigned short int b, unsigned short int c, unsigned char * d) {
	unsigned short int e = 0;

	while (b != 0) {
		b--;
		a[b] = c;
		c = (((((a[b] + a[e]) + b) + ((b + c) >> 1)) & 16383) + 2);
		a[e] = c;
		d[b] = (c & 15);
		e++;
	}

	return;
}
