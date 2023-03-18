void AvolittyHasherA(unsigned short * a, unsigned short * b, unsigned short * c, unsigned short d, unsigned short e, unsigned char * f) {
	unsigned short g = *b;
	unsigned short h = *c;
	unsigned short i = 0;
	unsigned short j;

	while (e != i) {
		g = ((((f[i] + g) + ((g + 2) >> 1))) & 16383) + 2;
		j = h & d;
		a[j] = (a[j] + g) & 1023;
		h++;
		i++;
	}

	*b = g;
	*c = h;
	return;
}

void AvolittyHasherB(unsigned short * a, unsigned short b, unsigned short c, unsigned char * d) {
	unsigned short e = 0;

	while (b != 0) {
		b--;
		a[b] = c;
		c = ((((a[b] + a[e]) + b) + ((b + c) >> 1)) & 16383) + 2;
		a[e] = c;
		d[b] = c & 15;
		e++;
	}

	return;
}
