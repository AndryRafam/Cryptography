/* VMPC (Variably Modified Permutation Composition) encryption program - March 2019

Author: Andry Rafam Andrianjafy

License: Open Source

Tools: Linux Ubuntu 16.04 LTS / GCC -v 6.5.0 && GDB -v 8.2 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "VMPC.h"
#define MAX 2048

int main()
{	
	unsigned char str[MAX];
	system("clear");
	fprintf(stdout,"\n\n");
	fprintf(stdout, "\t========== VMPC Encryption Program - Andry Rafam Andrianjafy ==========\n\n");
	fprintf(stdout, "[ YOUR CLEAR MESSAGE ] >> ");
	fgets(str,MAX,stdin);

	VMPC_key();
	unsigned char *ciphertext = malloc(sizeof(int) * 2048);
	fprintf(stdout, "\n\n[ YOUR ENCRYPTED MESSAGE ] >> ");
	VMPC_Encrypt(str,VMPC_key(),ciphertext);
	for (int x = 0; x < strlen(str); x++)
		fprintf(stdout, "%02x", *(str + x));
	printf("\n\n");
	return EXIT_SUCCESS;
}
