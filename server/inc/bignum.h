#ifndef _BIGNUM_
#define _BIGNUM_ 

struct bignum {
    uint32_t* reg; /* for 32 bit compatibility */
    uint8_t num_words;
};
/* name mangling to be class like */
bool bignum_isEqual(struct bignum* a, struct bignum* b);

bool bignum_isLessThan(struct bignum* a, struct bignum* b);

void bignum_add(struct bignum* a, struct bignum* b, struct bignum* result);

void bignum_subtract(struct bignum* a, struct bignum* b, struct bignum* result);

void bignum_multiply(struct bignum* a, struct bignum* b, struct bignum* result);


#endif
