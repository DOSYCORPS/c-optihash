## Avolitty Hasher

#### Author
William Parsons <[avolitty.com](https://avolitty.com/)>

#### Description
Create secure and variable-length checksums using C89 with a fast and unique hashing algorithm.

- Allocates memory with stack instead of heap
- Bitwise entropy derived without division or multiplication
- C89 compilation option -std=c89 supported up to c2x
- Compiles with Clang or GCC
- Conforms to strict ISO C with -pedantic-errors enabled
- Fast hashing speed with optimization level 3
- Hashes sequential bytes with dependence on each previous byte value
- Hashes strings consistently in variable-length blocks of memory
- Large 2GB+ files are supported
- Length variant values can be adjusted in the same hashing function
- Memory-safe with well-defined behavior
- Minified code
- Output character length can be 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 or 1024

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
#include <stddef.h>
#include <stdio.h>
#include "../src/avolitty-hasher.h"

int main(int a, char *b[]) {
	FILE *c;
	size_t d = 1024;
	size_t e = 1;
	size_t f = d;
	unsigned short int g[16U];
	unsigned short int h = 16U;
	unsigned short int i = h;
	unsigned short int j = 0U;
	unsigned short int k = 0U;
	unsigned short int *l = &i;
	unsigned short int *m = &j;
	unsigned char n[1024U];
	unsigned char o[16U];

	if (a == 1) {
		printf("Error hashing file without required file name argument.");
		return a;
	}

	c = fopen((const char *) b[1], (const char *) "rb");

	if (c == 0) {
		printf("Error reading file \"%s\".", b[1]);
		return a;
	}

	while (h != 0U) {
		g[--h] = 254U;
	}

	h = --i;

	while (d == f) {
		f = fread(n, e, d, c);
		k = (unsigned short int) f;
		AvolittyHasherA(g, l, m, h, k, n);
	}

	if (feof(c) == 0) {
		printf("Error hashing file \"%s\".", b[1]);
		return a;
	}

	fclose(c);
	AvolittyHasherB(g, ++h, i, o);

	while (h != 0U) {
		printf("%c", o[--h]);
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

`AvolittyHasherB()` adds entropy finalization and output the hash digest as hexadecimal character bytes.

The first argument variable `g` is a pointer to the previous `unsigned short int` array defined as the hashed payload bytes to finalize.

The second argument variable `h` is the previous value defined as the output character length.

The third argument variable `i` is the previous value modified by the pointer `l` in each hashing iteration for entropy.

The fourth argument variable `o` is a pointer to an `unsigned char` array to store the hashed bytes after finalization from `AvolittyHasherB()`.

The default value is an empty array with a default length of `16U`. As mentioned previously, this value matches the length of `g` and value of `h`.

`AvolittyHasherB()` defines it as the finalized hash digest.

An executable binary for testing can be compiled with either `clang` or `gcc`.

``` console
gcc -O3 -o avolitty-hasher -std=c89 src/avolitty-hasher.c test/main.c
```

`-O3` compiles with maximum optimization and `-std=c89` compiles with C89 standards.

It outputs an executable binary file named `avolitty-hasher` in the current directory.

The output from executing `./avolitty-hasher` is a hexadecimal hash digest string.

``` console
echo "123456789" > file

./avolitty-hasher file
# f72e2e6635be5bb4
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
# f72e2e6635be5bb4

# 32 characters
./avolitty-hasher file
# cfc68e84a8b6dee56ef0585162c0272d

# 64 characters
./avolitty-hasher file
# 2855a606efe398579a2d4d15245d87465d1a6626ed1e56d43bf58cfab992e203

# 128 characters
./avolitty-hasher file
# cf0a7277a0fc64fe31596891cb0652c292ef79bc47a5cdd331d5832f9ec0c59d5365600dadd870e2801ab8745b9422fab1ccc6c93f62e334d64eee66c7b2919f

# 256 characters
./avolitty-hasher file
# f36397add344262b77e7b788eec049fe315122802c1775956e8e5eabb9d1e0194b400f4a1229262b776356e909d164feb5b2bfc6b117f134c76356e9857887cabe27c8bf1a52faebca3fa1c69774f8a72e057456356427d028bd87b8c4f6b0f9f5bdba9eb18adee4fab3059b5cd41f5fe5994d939771e989819565410a1423f7

# 512 characters
./avolitty-hasher file
# e240c0da9729aa0066cca66deec0413c899ffd914721e85716c4ec763dbe9019c76b9cf2dc177d5f5c51a66d62ad0ba79a25078024d9a24ebd7460537b827511053e5e27dc17f9f6fbc4e4bc47ad03610df8c1f258be1cb8a49ff5d75832751189135ea373442eed20bafd9147ad874e391356e1cb0e90956e869c7ef7a5413cd3e6d3b410ad2e685e3e76c14fde44465d9e9dfd95024be4cfed271adc0b826cb429b16e61a68d9faadd96db4a4ea1d6f896d3868b88614ec2f1d889c332cc5a80c027962680dd2bd4545cbe1ba4e42cc4b16cf1cbcb4f73277d7f34102653cd567c70a3072f14a0d2eab0b7084db6c8fe6da6e0a0bcc59ff7a4235749b8ecb3

# 1024 characters
./avolitty-hasher file
# cf0ab6a89b827511053e5e27dc17f9f6fbc4e4bccb82f134438eda42dc17f9fe3151a6e909d16c34438e5eabb95d0369cf25832758be1cb0e26b1053f7ad8f0828f083a3f7ad03eda49f79bc47216c344bc4681dee4426a7926b1891c3442e69430afd91c3c887c29aa122802455cdd3b5b2b780a078874ebdf00f4a96065a08a497b70409d16cb0e2635eab3d3a3f84cf258b6d6a6f37cad8f8c17635788f0828f083a3f7ad03eda49f79bc47216c344bc4681dee4426a79263da42d4d9262b77ef71fa968ab3eda4135eab3570cd571e0a79bc4fe314feb53ed2886229262331d583a37b8a3f082874689147292eedac59e4bcc34ce09566ccae2f1aeb52ca3d6849ea58f25a83603c0cd57958ff45ea6e9dfd90f289361f7865eeb620bebdea6e90d9a44cb21190ecafa953dd26dcf242c0a824c573a6f082d23cdff5425ccfe228000564227bb572105ac5f2db0649165f257ed22cfda1f7fe35e3ed9a400eaba5276d117f76558f7552d9fb995d4c2932dc8d2656a91492a951ef33470a7bba10000a0813b0c0df851fb2f013b5d7cb0dd9a49edab4ad156d71fe59c22e39db76c9b37d077b39dbf55ac57e7ae3876e115199e450dad5d42b733a00d051293d00eee02e9cba267c7bd06f0d422e3ea0f0a0e67823c87531972a1a2493b83c649ab84b782b8261ebb497222f9de5f6de81eadc8a02e8d770a35d2c63383b
```
