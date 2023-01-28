void AvolittyHasherA(unsigned short int *a, unsigned short int *b, unsigned short int *c, unsigned short int d, unsigned short int e, unsigned char *f) {
	unsigned short int g;
	unsigned short int h;
	unsigned short int i;
	unsigned short int j;
	unsigned short int k;
	unsigned short int l;
	unsigned short int m;
	unsigned short int n;
	g = *b;
	h = *c;
	i = ((unsigned short int) 16383U);
	j = ((unsigned short int) 1023U);
	k = ((unsigned short int) 2U);
	l = ((unsigned short int) 1U);
	m = ((unsigned short int) 0U);
	n = ((unsigned short int) 0U);

	while (e != m) {
		g = (((((((unsigned short int) f[m]) + g) + ((g + k) >> l))) & i) + k);
		n = (h & d);
		a[n] = ((a[n] + g) & j);
		h++;
		m++;
	}

	*b = g;
	*c = h;
	return;
}

void AvolittyHasherB(unsigned short int *a, unsigned short int b, unsigned short int c, unsigned char *d) {
	unsigned short int e;
	unsigned short int f;
	unsigned short int g;
	unsigned short int h;
	unsigned short int i;
	unsigned short int j;
	e = ((unsigned short int) 16383U);
	f = ((unsigned short int) 15U);
	g = ((unsigned short int) 2U);
	h = ((unsigned short int) 1U);
	i = ((unsigned short int) 0U);
	j = ((unsigned short int) 0U);

	while (b != j) {
		b--;
		a[b] = c;
		c = (((((a[b] + a[i]) + b) + ((b + c) >> h)) & e) + g);
		a[i] = c;
		d[b] = ((unsigned char) (c & f));
		i++;
	}

	return;
}
