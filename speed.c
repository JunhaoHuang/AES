#include "aes.h"
#include <stdio.h>
#include <time.h>

int main(){
	// Speed test for AES-128
	clock_t start, end;
	double sum = 0, sum1 = 0;
	const int count=100000;
	uint8_t buf[] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,
					 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff};
	uint8_t key[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
					 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};
	uint8_t iv[] = {0x60, 0xef, 0x17, 0x10, 0xd7, 0xcc, 0x28, 0xf8,
					0x56, 0xbd, 0xe4, 0x8b, 0xa1, 0xce, 0xb0, 0x87};// temp iv
	uint8_t data[sizeof(buf)*count];
	for(int i=0;i<count;i++)
	{
		for(int j=0;j<sizeof(buf);j++){
			data[i*sizeof(buf)+j]=buf[j];
		}
	}

	start=clock();
	aes_encrypt_ecb(AES_CYPHER_128, data, sizeof(data), key);
	end=clock();
	printf("aes_encrypt_ecb_128 %ld bytes time(s): %lf\n", sizeof(data), (double)(end - start) / CLOCKS_PER_SEC);
	aes_dump("cipher", data, 16);

	start = clock();
	aes_decrypt_ecb(AES_CYPHER_128, data, sizeof(data), key);
	end = clock();
	printf("aes_decrypt_ecb_128 %ld bytes time(s): %lf\n", sizeof(data), (double)(end - start) / CLOCKS_PER_SEC);

	start = clock();
	aes_encrypt_cbc(AES_CYPHER_128, data, sizeof(data), key, iv);
	end = clock();
	printf("aes_encrypt_cbc_128 %ld bytes time(s): %lf\n", sizeof(data), (double)(end - start) / CLOCKS_PER_SEC);
	aes_dump("cipher", data, 16);

	start = clock();
	aes_decrypt_cbc(AES_CYPHER_128, data, sizeof(data), key, iv);
	end = clock();
	printf("aes_decrypt_cbc_128 %ld bytes time(s): %lf\n", sizeof(data), (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}