#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../include/dh.h"

int main(int argc, char *argv[])
{
	/** SET 5 CHALLENGE 33 **/
	/**  DH KEY EXCHANGE   **/
	unsigned long a, A, b, B, s1, s2;

	srand(time(NULL));

	dh_generate_keypair_smallint(&a, &A);
	dh_generate_keypair_smallint(&b, &B);

	s1 = dh_generate_session_key_smallint(a, B);
	s2 = dh_generate_session_key_smallint(b, A);

	printf("[s5c1] a = %lld, A = %lld, b = %lld, B = %lld, s = %lld ?= %lld\n", a, A, b, B, s1, s2);

	return 0;
}
