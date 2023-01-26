void AvolittyHasherA(unsigned short int *a, unsigned short int *b, unsigned short int *c, unsigned short int d, unsigned short int e, unsigned char *f) {
	unsigned short int g;
	unsigned short int h;
	unsigned short int i;
	unsigned short int j;
	g = *b;
	h = *c;
	i = ((unsigned short int) 0U);
	j = ((unsigned short int) 0U);

	while (e != i) {
		g = (((((((unsigned short int) f[i]) + g) + ((g + ((unsigned short int) 2U)) >> ((unsigned short int) 1U)))) & ((unsigned short int) 16383U)) + ((unsigned short int) 2U));
		j = (h & d);
		a[j] = ((a[j] + g) & ((unsigned short int) 1023U));
		h++;
		i++;
	}

	*b = g;
	*c = h;
	return;
}

void AvolittyHasherB(unsigned short int *a, unsigned short int b, unsigned short int c, unsigned char *d) {
	unsigned short int e;
	unsigned short int f;
	e = ((unsigned short int) 0U);
	f = ((unsigned short int) 0U);

	while (b != f) {
		b--;
		a[b] = c;
		c = (((((a[b] + a[e]) + b) + ((b + c) >> ((unsigned short int) 1U))) & ((unsigned short int) 16383U)) + ((unsigned short int) 2U));
		a[e] = c;
		d[b] = ((unsigned char) (c & ((unsigned short int) 15U)));
		e++;
	}

	return;
}
