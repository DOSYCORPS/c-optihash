## Avolitty Hasher

#### Author
William Parsons <[avolitty.com](https://avolitty.com/)>

#### Description
Create secure and variable-length checksums using C89 with a fast and unique hashing algorithm.

- Allocates static memory with stack instead of heap
- Bitwise entropy derived without division, multiplication or bitwise ^
- Compiles with Clang or GCC
- Compiles with forward-compatible C89 option -std=c89 and C++ option -stdc++98
- Conforms to strict ISO C with -pedantic-errors enabled
- Fast hashing speed without compiler optimization
- Hashes sequential bytes with dependence on each previous byte value
- Hashes strings consistently in variable-length blocks of memory
- Large files are supported
- Length variant values can be adjusted in the same hashing function
- Memory-safe with well-defined behavior
- Minified code
- Output character length can be 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 or 1024
- Outputs an array of 0xF digits for fast hash table lookups

#### Funding
[Avolitty](https://avolitty.com/donate/)

#### License
[MIT](https://github.com/avolitty/avolitty-hasher/blob/main/LICENSE)

#### Usage
Clone the repository in the current directory with `git`.

``` console
git clone https://github.com/avolitty/avolitty-hasher.git
```

Navigate to the cloned repository's root directory with `cd`.

``` console
cd avolitty-hasher
```

The following example uses code from [test/main.c](https://github.com/avolitty/avolitty-hasher/blob/main/test/main.c) to generate hash digests with the `AvolittyHasherA()` and `AvolittyHasherB()` functions from [src/avolitty-hasher.c](https://github.com/avolitty/avolitty-hasher/blob/main/src/avolitty-hasher.c).

``` c
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
```

`AvolittyHasherA()` hashes message payload bytes.

The first argument variable `g` is a pointer to a `unsigned short int` array to store the hashed payload bytes.

The default value is an empty array with a default length of `16U`.

The length is equivalent to the output length and `AvolittyHasherA()` defines it as the bytes for the hash digest output before finalization.

The second argument variable `l` is a pointer to modify the value of the variable `i`.

The variable `i` is an `unsigned short int` defined as `h` with a default value of `16U`.

The third argument variable `m` is a pointer to modify the value of the variable `j`.

The variable `j` is an `unsigned short int`.

The value is `0U`.

The fourth argument variable `h` is an `unsigned short int` defined as the character length of the hash digest output.

The default value is `16U` with a minimum of `1U` and a maximum of `1024U`. If the digest output character length needs to change, this value is in shifted increments (`1U`, `2U`, `4U`, `8U`, `16U`, `32U`, `64U`, `128U`, `256U`, `512U`, `1024U`) with the same value as defined array lengths in variables `g` and `o`.

The fifth argument variable `k` is an `unsigned short int` defined as the casted `size_t` result from each `fread()` iteration before passing as an argument to `AvolittyHasherA()`.

The sixth argument variable `n` is a pointer to an `unsigned char` array to store the chunked file data result before hashing.

The default value is an empty array with a default length of `1024U`.

The length be modified based on the expected length of file input and efficiency requirements. If the default length needs to change, it matches the number defined in the variable `d`.

Changing the default length of `1024U` doesn't change digest output values. It only changes the maximum amount of memory to use for each chunk of data.

The minimum length is the value of the variable `h`.

`AvolittyHasherB()` adds entropy finalization and outputs the hash digest as an array of bytes for each hexadecimal digit.

The first argument variable `g` is a pointer to the previous `unsigned short int` array defined as the hashed payload bytes to finalize.

The second argument variable `h` is the previous value defined as the output character length.

The third argument variable `i` is the previous value modified by the pointer `l` in each hashing iteration for entropy.

The fourth argument variable `o` is a pointer to an `unsigned char` array to store the hashed bytes after finalization from `AvolittyHasherB()`.

The default value is an empty array with a default length of `16U`. As mentioned previously, this value matches the length of `g` and value of `h`.

`AvolittyHasherB()` defines it as the finalized hash digest.

An executable binary for testing can be compiled with either `clang` or `gcc`.

``` console
gcc -o avolitty-hasher -pedantic-errors -std=c89 src/avolitty-hasher.c test/main.c
```

`-pedantic-errors` compiles with strict ISO C standards and `-std=c89` compiles with forward-compatible C89 standards.

It outputs an executable binary file named `avolitty-hasher` in the current directory.

The output from executing `./avolitty-hasher` is a hexadecimal hash digest string.

``` console
echo "123456789" > file

./avolitty-hasher file
# f72e2e66353a7efa
```

The first command line argument value `file` is the file name to hash.

These are the outputs for each character length variant after modifying the lengths in the variables `g` and `o` and the value in the variable `h`.

``` console
# 1 character
./avolitty-hasher file
# e

# 2 characters
./avolitty-hasher file
# b8

# 4 characters
./avolitty-hasher file
# acf8

# 8 characters
./avolitty-hasher file
# 5dc02d43

# 16 characters
./avolitty-hasher file
# f72e2e66353a7efa

# 32 characters
./avolitty-hasher file
# cfc68e84a832f9722bd17b25c3675340

# 64 characters
./avolitty-hasher file
# 2855a606e7a549feb53edac6b955cdd3aba83e7e5c8a0ad3c2c395dfb1d0b552

# 128 characters
./avolitty-hasher file
# cf0a72772c17f13c815122048dbe909da49ff5df1a67f13c891b9438e606deed2863f55d337d326f239841ac3ca68d9c3b743a6316c3064c5fbb436e0586fae7

# 256 characters
./avolitty-hasher file
# f36397a595fce01181d50f4a960e1cb0e2e733a373c0c519c763d20485fc6c344bc4681d6a6f3746f38618998db6deedacddc9386a677595ea2507802c177511bc641629a13968562fb3520ec6e262079a9fc83b6406725fbe52bb64b34a195537e59b0a318fb452424a533da5c9a625bbf8608ca9fbc8f97911b614c40bdbb1

# 512 characters
./avolitty-hasher file
# e240c056b221e85fd036189985780b23b53edacef729aa08acddc9bc4fe398571e023be9019bdee566484553f7292623b53eda4258be1cb066c4ec7e7b06d6af54135e2f9e4ce019c7e7bf4a9ec88746fbccaeab3d32759da49ffd9147a549f67763dac6b1931c344b408be1c34c6cb8287c2ac635fc64721e02bfce73c80369c4382f53dd8675c60b4ee37e5cd789b2e8fe30b7551908b6c5e413f2318776345f85ca2a46107becbc6fc0a0e642575f3ac6f584e7716dbbae08aed82449dc24052de94a2a6d6cba267cf77afb709f5ccf665796af4e7dd29a103e4529a18f3d18a611ddb4b5b9361ae27a5b9217cc81c4bcbe4d90a5169eae0d03fa8fca185a

# 1024 characters
./avolitty-hasher file
# cf0a32c3219bd6a71e0233a373c049fe31512a4250fce0110df0078862292e69cfa9e43862a549721e86105b3dbe9011053694b485f4aa006e0afd152c931c3c0d7ca6e1c34ce85792eff55bb1177ddbfb400780245d0369c76b1815a0704134cf2583abb9d92e61053694b401931cb06e8e56652c939011815960df1aeb52ca54135e27583275110d7c2ac63dbe1cb8a41b1815a0f42ee5e26b9c763db65a8c05b2332f960e14729aa96891c34c64febdf083abb19bdeedacd50f4a9682f134cfa12aceff677595664083a3734c64feb5369cf2dc177d5fd874ecfa9ec887cad0361891cb06d6a79aa12ac6b9d1e0194b408b65a0fc6cb8a413d280a070cd5fc6aba8d16ebb85591419f74144725726ae89598081584d098986bcd287d9f3d77053335768389affce1492fe0f1f02111c5fd71ad1b86cb7c6d69dab92623078fe1f184edd549ea6f3799750e3e559c22e0065b703cb10c68f514505e313efad4f970e76c9031010eaed50143f14d4b26c8e290466c6e7e01d0e2cea58268dce1a18cdc7411267e856715cb3f71fde6387187c134de36b4943cf6373b6a4e11fa74a01bbe02e157d25507f0651b8ed6ea314137baff54d093b4e30b7dcd70267e068fba28ca187cca072c0f8b75d5914710282dc3755642f69ff370607246d3fd8b541f4a1b0d53f0f23ee19eaa8fc84574ad71217f06c62d8ec513d4b518079
```
