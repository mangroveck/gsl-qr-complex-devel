#include <config.h>
#include <stdlib.h>
#include <gsl_rng.h>

/* This is the old BSD rand() generator. The sequence is

   x_{n+1} = (a x_n + c) mod m 

   with a = 1103515245, c = 12345 and m = 2^31 = 2147483648. The seed
   specifies the initial value, x_1.

   The theoretical value of x_{10001} is 1910041713.

   The period of this generator is 2^31.

   The rand() generator is not very good -- the low bits of successive
   numbers are correlated. */

unsigned long int bsdrand_get (void *vstate);
void bsdrand_set (void *state, unsigned long int s);

1typedef struct
  {
    unsigned long int x;
  }
bsdrand_state_t;

unsigned long int
bsdrand_get (void *vstate)
{
  bsdrand_state_t *state = (bsdrand_state_t *) vstate;

  /* The following line relies on unsigned 32-bit arithmetic */

  state->x = (1103515245 * state->x + 12345) & 0x7fffffffUL;

  return state->x;
}


void
bsdrand_set (void *vstate, unsigned long int s)
{
  bsdrand_state_t *state = (bsdrand_state_t *) vstate;

  state->x = s;

  return;
}

static const gsl_rng_type bsdrand_type =
{"bsdrand",			/* name */
 0x7fffffffUL,			/* RAND_MAX */
 0,				/* RAND_MIN */
 sizeof (bsdrand_state_t),
 &bsdrand_set,
 &bsdrand_get};

const gsl_rng_type *gsl_rng_bsdrand = &bsdrand_type;
