#ifndef OPTIHASH_H
#define OPTIHASH_H

void optiHash8192Bit(unsigned long *inputIndexPointer, unsigned short *entropy, unsigned short *salt, unsigned short inputIndex, unsigned char *input);

void optiHash4096Bit(unsigned long *inputIndexPointer, unsigned short *entropy, unsigned short *salt, unsigned short inputIndex, unsigned char *input);

void optiHash2048Bit(unsigned long *inputIndexPointer, unsigned short *entropy, unsigned short *salt, unsigned short inputIndex, unsigned char *input);

void optiHash1024Bit(unsigned long *inputIndexPointer, unsigned short *entropy, unsigned short *salt, unsigned short inputIndex, unsigned char *input);

void optiHash512Bit(unsigned long *inputIndexPointer, unsigned short *entropy, unsigned short *salt, unsigned short inputIndex, unsigned char *input);

void optiHash256Bit(unsigned long *inputIndexPointer, unsigned short *entropy, unsigned short *salt, unsigned short inputIndex, unsigned char *input);

void optiHash128Bit(unsigned long *inputIndexPointer, unsigned short *entropy, unsigned short *salt, unsigned short inputIndex, unsigned char *input);

void optiHash64Bit(unsigned long *inputIndexPointer, unsigned short *entropy, unsigned short *salt, unsigned short inputIndex, unsigned char *input);

void optiHash32Bit(unsigned long *inputIndexPointer, unsigned short *entropy, unsigned short *salt, unsigned short inputIndex, unsigned char *input);

void optiHash16Bit(unsigned long *inputIndexPointer, unsigned short *entropy, unsigned short *salt, unsigned short inputIndex, unsigned char *input);

void optiHash8Bit(unsigned short *entropy, unsigned short *salt, unsigned short inputIndex, unsigned char *input);

void optiHashFinalize(unsigned short *entropy, unsigned short entropyHighIndex, unsigned short salt, unsigned char *digest);

#endif
