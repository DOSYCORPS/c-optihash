void AvolittyHasherA(unsigned short * a, unsigned short * b, unsigned short * c, unsigned short d, unsigned char * e) {
	unsigned short f = *b;
	unsigned short g = *c;
	unsigned short h = 0;

	while (d != h) {
		f = (((e[h] + f + ((f + 2) >> 1))) & 16383) + 2;
		a[0] = (a[0] + f) & 1023;
		g++;
		h++;
	}

	*b = f;
	*c = g;
	return;
}

void AvolittyHasherB(unsigned short * a, unsigned short * b, unsigned short * c, unsigned short d, unsigned char * e) {
	unsigned short f = *b;
	unsigned short g = *c;
	unsigned short h = 0;
	unsigned short i;

	while (d != h) {
		f = (((e[h] + f + ((f + 2) >> 1))) & 16383) + 2;
		i = g & 1;
		a[i] = (a[i] + f) & 1023;
		g++;
		h++;
	}

	*b = f;
	*c = g;
	return;
}

void AvolittyHasherC(unsigned short * a, unsigned short * b, unsigned short * c, unsigned short d, unsigned char * e) {
	unsigned short f = *b;
	unsigned short g = *c;
	unsigned short h = 0;
	unsigned short i;

	while (d != h) {
		f = (((e[h] + f + ((f + 2) >> 1))) & 16383) + 2;
		i = g & 3;
		a[i] = (a[i] + f) & 1023;
		g++;
		h++;
	}

	*b = f;
	*c = g;
	return;
}

void AvolittyHasherD(unsigned short * a, unsigned short * b, unsigned short * c, unsigned short d, unsigned char * e) {
	unsigned short f = *b;
	unsigned short g = *c;
	unsigned short h = 0;
	unsigned short i;

	while (d != h) {
		f = (((e[h] + f + ((f + 2) >> 1))) & 16383) + 2;
		i = g & 7;
		a[i] = (a[i] + f) & 1023;
		g++;
		h++;
	}

	*b = f;
	*c = g;
	return;
}

void AvolittyHasherE(unsigned short * a, unsigned short * b, unsigned short * c, unsigned short d, unsigned char * e) {
	unsigned short f = *b;
	unsigned short g = *c;
	unsigned short h = 0;
	unsigned short i;

	while (d != h) {
		f = (((e[h] + f + ((f + 2) >> 1))) & 16383) + 2;
		i = g & 15;
		a[i] = (a[i] + f) & 1023;
		g++;
		h++;
	}

	*b = f;
	*c = g;
	return;
}

void AvolittyHasherF(unsigned short * a, unsigned short * b, unsigned short * c, unsigned short d, unsigned char * e) {
	unsigned short f = *b;
	unsigned short g = *c;
	unsigned short h = 0;
	unsigned short i;

	while (d != h) {
		f = (((e[h] + f + ((f + 2) >> 1))) & 16383) + 2;
		i = g & 31;
		a[i] = (a[i] + f) & 1023;
		g++;
		h++;
	}

	*b = f;
	*c = g;
	return;
}

void AvolittyHasherG(unsigned short * a, unsigned short * b, unsigned short * c, unsigned short d, unsigned char * e) {
	unsigned short f = *b;
	unsigned short g = *c;
	unsigned short h = 0;
	unsigned short i;

	while (d != h) {
		f = (((e[h] + f + ((f + 2) >> 1))) & 16383) + 2;
		i = g & 63;
		a[i] = (a[i] + f) & 1023;
		g++;
		h++;
	}

	*b = f;
	*c = g;
	return;
}

void AvolittyHasherH(unsigned short * a, unsigned short * b, unsigned short * c, unsigned short d, unsigned char * e) {
	unsigned short f = *b;
	unsigned short g = *c;
	unsigned short h = 0;
	unsigned short i;

	while (d != h) {
		f = (((e[h] + f + ((f + 2) >> 1))) & 16383) + 2;
		i = g & 127;
		a[i] = (a[i] + f) & 1023;
		g++;
		h++;
	}

	*b = f;
	*c = g;
	return;
}

void AvolittyHasherI(unsigned short * a, unsigned short * b, unsigned short * c, unsigned short d, unsigned char * e) {
	unsigned short f = *b;
	unsigned short g = *c;
	unsigned short h = 0;
	unsigned short i;

	while (d != h) {
		f = (((e[h] + f + ((f + 2) >> 1))) & 16383) + 2;
		i = g & 255;
		a[i] = (a[i] + f) & 1023;
		g++;
		h++;
	}

	*b = f;
	*c = g;
	return;
}

void AvolittyHasherJ(unsigned short * a, unsigned short * b, unsigned short * c, unsigned short d, unsigned char * e) {
	unsigned short f = *b;
	unsigned short g = *c;
	unsigned short h = 0;
	unsigned short i;

	while (d != h) {
		f = (((e[h] + f + ((f + 2) >> 1))) & 16383) + 2;
		i = g & 511;
		a[i] = (a[i] + f) & 1023;
		g++;
		h++;
	}

	*b = f;
	*c = g;
	return;
}

void AvolittyHasherK(unsigned short * a, unsigned short * b, unsigned short * c, unsigned short d, unsigned char * e) {
	unsigned short f = *b;
	unsigned short g = *c;
	unsigned short h = 0;
	unsigned short i;

	while (d != h) {
		f = (((e[h] + f + ((f + 2) >> 1))) & 16383) + 2;
		i = g & 1023;
		a[i] = (a[i] + f) & 1023;
		g++;
		h++;
	}

	*b = f;
	*c = g;
	return;
}

void AvolittyHasherL(unsigned short * a, unsigned short b, unsigned short c, unsigned char * d) {
	unsigned short e = 0;

	while (b != 0) {
		b--;
		a[b] = c;
		c = ((a[b] + a[e] + b + ((b + c) >> 1)) & 16383) + 2;
		a[e] = c;
		d[b] = c & 15;
		e++;
	}

	return;
}
