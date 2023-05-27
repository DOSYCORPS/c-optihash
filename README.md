## C Hasher

#### Description
Create secure and variable-length checksums using C with a fast and unique hashing algorithm.

- Allocates static memory with stack instead of heap
- Bitwise entropy derived without XOR, division or multiplication
- Compiles with forward-compatible C89 and C++
- Conforms to strict ISO C with -pedantic-errors enabled
- Efficient without multithreading or processor-specific vectorization
- Fast hashing speed without relying on compiler optimization
- Hashes sequential bytes with dependence on each previous byte value
- Hashes strings consistently in variable-length blocks of memory
- Input with large files supported
- Memory-safe with defined behavior
- Minified and readable code with single-letter variable names
- Output character length can be 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 or 1024
- Outputs an array of 0xF digits for fast hash table lookups
- Separate hashing functions for each digest length variant

#### Usage
Clone the repository in the current directory with the command `git`.

``` console
git clone https://github.com/frymimori/c-hasher.git
```

Navigate to the cloned repository's root directory with the command `cd`.

``` console
cd c-hasher
```

The following example uses code from the file [test.c](https://github.com/frymimori/c-hasher/blob/main/test.c) to generate hash digests.

``` c
#include <stdio.h>
#include "hasher.h"

int main(int a, char * * b) {
	FILE * c;
	unsigned short d[16];
	unsigned short e = 1024;
	unsigned short f = 16;
	unsigned short g = f;
	unsigned short h = 0;
	unsigned short * i = &g;
	unsigned short * j = &h;
	unsigned char k[1024];
	unsigned char l[16];

	if (a != 0) {
		c = fopen(b[1], "rb");

		if (c != (void *) 0) {
			while (f != 0) {
				f--;
				d[f] = 254;
			}

			f = g;
			g--;

			while (e == 1024) {
				e = fread(k, 1, 1024, c);
				hasherE(d, i, j, e, k);
			}

			if (feof(c) != 0) {
				fclose(c);
				hasherL(d, f, g, l);

				while (f != 0) {
					f--;
					printf("%x", l[f]);
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
```

The function `hasherA()` outputs a 1-character digest.

The function `hasherB()` outputs a 2-character digest.

The function `hasherC()` outputs a 4-character digest.

The function `hasherD()` outputs a 8-character digest.

The function `hasherE()` outputs a 16-character digest.

The function `hasherF()` outputs a 32-character digest.

The function `hasherG()` outputs a 64-character digest.

The function `hasherH()` outputs a 128-character digest.

The function `hasherI()` outputs a 256-character digest.

The function `hasherJ()` outputs a 512-character digest.

The function `hasherK()` outputs a 1024-character digest.

The first argument variable `d` is a pointer to an `unsigned short` array to store the hashed payload bytes.

The default value is an empty array with a default length of `16`.

The length is equivalent to the output length defined as as the bytes for the hash digest output before finalization.

The second argument variable `i` is a pointer to modify the value of the variable `g`.

The variable `g` is an `unsigned short` defined as the variable `f`.

The third argument variable `j` is a pointer to modify the value of the variable `h`.

The variable `h` is an `unsigned short` defined as `0`.

The fourth argument variable `e` is the integer result from each `fread()` iteration defined as `1024`.

The length should be modified based on the expected length of file input and efficiency requirements.

The fifth argument variable `k` is a pointer to an `unsigned char` array to store the chunked file data result before hashing.

The default value is an empty array for file data chunks with a default length of `1024`.

The length should be modified based on efficiency requirements and should match the length of the variable `e` and other instances where `1024` is referenced as the memory buffer size for each chunked file data result.

The minimum length is the value of the variable `h`.

The function `hasherL()` adds entropy finalization and outputs the hash digest as an array of bytes for each hexadecimal digit.

The first argument variable `d` is a pointer to the previous `unsigned short` array defined as the hashed payload bytes to finalize.

The second argument variable `f` is the previous value defined as the output character length.

The third argument variable `g` is the previous value modified by the variable `i` in each hashing iteration for entropy.

The fourth argument variable `l` is a pointer to an `unsigned char` array to store the hashed bytes after finalization.

The default value is an empty array with a default length of `16`.

The length should match the length of the variable `d` and the value of the variable `f`.

``` console
gcc -o c-hasher -pedantic-errors -std=c89 hasher.c test.c
```

The output from the command `./c-hasher` is a hexadecimal hash digest string.

``` console
echo 123456789 > file

./c-hasher file
# f72e2e66353a7efa
```

The first command line argument value `file` is the file name to hash.

These are the outputs for each character length variant.

``` console
# hasherA()
./c-hasher file
# e

# hasherB()
./c-hasher file
# b8

# hasherC()
./c-hasher file
# acf8

# hasherD()
./c-hasher file
# 5dc02d43

# hasherE()
./c-hasher file
# f72e2e66353a7efa

# hasherF()
./c-hasher file
# cfc68e84a832f9722bd17b25c3675340

# hasherG()
./c-hasher file
# 2855a606e7a549feb53edac6b955cdd3aba83e7e5c8a0ad3c2c395dfb1d0b552

# hasherH()
./c-hasher file
# cf0a72772c17f13c815122048dbe909da49ff5df1a67f13c891b9438e606deed2863f55d337d326f239841ac3ca68d9c3b743a6316c3064c5fbb436e0586fae7

# hasherI()
./c-hasher file
# f36397a595fce01181d50f4a960e1cb0e2e733a373c0c519c763d20485fc6c344bc4681d6a6f3746f38618998db6deedacddc9386a677595ea2507802c177511bc641629a13968562fb3520ec6e262079a9fc83b6406725fbe52bb64b34a195537e59b0a318fb452424a533da5c9a625bbf8608ca9fbc8f97911b614c40bdbb1

# hasherJ()
./c-hasher file
# e240c056b221e85fd036189985780b23b53edacef729aa08acddc9bc4fe398571e023be9019bdee566484553f7292623b53eda4258be1cb066c4ec7e7b06d6af54135e2f9e4ce019c7e7bf4a9ec88746fbccaeab3d32759da49ffd9147a549f67763dac6b1931c344b408be1c34c6cb8287c2ac635fc64721e02bfce73c80369c4382f53dd8675c60b4ee37e5cd789b2e8fe30b7551908b6c5e413f2318776345f85ca2a46107becbc6fc0a0e642575f3ac6f584e7716dbbae08aed82449dc24052de94a2a6d6cba267cf77afb709f5ccf665796af4e7dd29a103e4529a18f3d18a611ddb4b5b9361ae27a5b9217cc81c4bcbe4d90a5169eae0d03fa8fca185a

# hasherK()
./c-hasher file
# cf0a32c3219bd6a71e0233a373c049fe31512a4250fce0110df0078862292e69cfa9e43862a549721e86105b3dbe9011053694b485f4aa006e0afd152c931c3c0d7ca6e1c34ce85792eff55bb1177ddbfb400780245d0369c76b1815a0704134cf2583abb9d92e61053694b401931cb06e8e56652c939011815960df1aeb52ca54135e27583275110d7c2ac63dbe1cb8a41b1815a0f42ee5e26b9c763db65a8c05b2332f960e14729aa96891c34c64febdf083abb19bdeedacd50f4a9682f134cfa12aceff677595664083a3734c64feb5369cf2dc177d5fd874ecfa9ec887cad0361891cb06d6a79aa12ac6b9d1e0194b408b65a0fc6cb8a413d280a070cd5fc6aba8d16ebb85591419f74144725726ae89598081584d098986bcd287d9f3d77053335768389affce1492fe0f1f02111c5fd71ad1b86cb7c6d69dab92623078fe1f184edd549ea6f3799750e3e559c22e0065b703cb10c68f514505e313efad4f970e76c9031010eaed50143f14d4b26c8e290466c6e7e01d0e2cea58268dce1a18cdc7411267e856715cb3f71fde6387187c134de36b4943cf6373b6a4e11fa74a01bbe02e157d25507f0651b8ed6ea314137baff54d093b4e30b7dcd70267e068fba28ca187cca072c0f8b75d5914710282dc3755642f69ff370607246d3fd8b541f4a1b0d53f0f23ee19eaa8fc84574ad71217f06c62d8ec513d4b518079
```
