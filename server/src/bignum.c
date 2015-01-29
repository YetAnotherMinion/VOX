#include <stddef.h>
#include "bignum.h"

bool bignum_isEqual(struct bignum* a, struct bignum* b) {
	/* make the largest length in a by swapping */
	if(a->num_words < b->num_words) {
		a = a ^ b;
		b = a ^ b;
		a = a ^ b;
	}
	int i = 0;
	while(i < b->num_words) {
		if(a->reg[i] != b->reg[i]) {
			return false;
		}
		i++;
	}
	while(i < a->num_words) {
		if(a->reg[i]) { return false; }
		i++;
	}
}

bool bignum_isLessThan(struct bignum* lhs, struct bignum* rhs) {
	/*record which side is the longest
	unsigned int flag = (lhs->num_words < rhs->num_words) ? 1 : 0;
	bignum* a = flag ? 
} 
