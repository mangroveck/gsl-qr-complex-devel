#include <config.h>
#include <string.h>
#include <stdlib.h>
#include <gsl_ieee_utils.h>
#include <gsl_errno.h>

static int 
lookup_string (const char * p, int * precision, int * rounding, 
	       int * exception_mask) ;


void
gsl_ieee_env_setup (void)
{
  const char * p = getenv("GSL_IEEE_MODE") ;

  int precision = 0, rounding = 0, exception_mask = 0 ;

  if (p)
    gsl_ieee_read_mode_string (p, &precision, &rounding, &exception_mask) ;

  gsl_ieee_set_mode (precision, rounding, exception_mask) ;
  
  printf("GSL_IEEE_MODE: ") ;
  
  switch (precision) 
    {
    case GSL_IEEE_SINGLE_PRECISION:
      printf("single-precision;") ;
      break ;
    case GSL_IEEE_DOUBLE_PRECISION:
      printf("double-precision;") ;
      break ;
    case GSL_IEEE_EXTENDED_PRECISION:
      printf("extended-precision") ;
      break ;
    default:
      printf("default-precision") ;
    }

  switch (rounding) 
    {
    case GSL_IEEE_ROUND_TO_NEAREST:
      printf(";round-to-nearest") ;
      break ;
    case GSL_IEEE_ROUND_DOWN:
      printf(";round-down") ;
      break ;
    case GSL_IEEE_ROUND_UP:
      printf(";round-up") ;
      break ;
    case GSL_IEEE_ROUND_TO_ZERO:
      printf(";round-to-zero") ;
      break ;
    default:
      printf(";default-rounding") ;
    }

  if (exception_mask & GSL_IEEE_MASK_INVALID)
    printf(";mask-invalid") ;

  if (exception_mask & GSL_IEEE_MASK_DENORMALIZED)
    printf(";mask-denormalized") ;

  if (exception_mask & GSL_IEEE_MASK_DIVISION_BY_ZERO)
    printf(";mask-division-by-zero") ;

  if (exception_mask & GSL_IEEE_MASK_OVERFLOW)
    printf(";mask-overflow") ;

  if (exception_mask & GSL_IEEE_MASK_UNDERFLOW)
    printf(";mask-underflow") ;

  if (exception_mask & GSL_IEEE_TRAP_INEXACT)
    printf(";trap-inexact") ;
  
  printf("\n") ;
}

int
gsl_ieee_read_mode_string (const char * description, 
			   int * precision, 
			   int * rounding, 
			   int * exception_mask)
{
  char * start = strdup (description) ;
  char * end;

  char * p = start;

  int precision_count = 0 ;
  int rounding_count = 0 ;
  int exception_count = 0 ;

  *precision = 0 ;
  *rounding = 0 ;
  *exception_mask = 0 ;

  do {
    int status ;
    int new_precision, new_rounding, new_exception ;

    end = strchr (p,';') ;

    if (end) 
      {
	*end = '\0' ;
	do 
	  {
	    end++ ;  /* skip over trailing whitespace */
	  } 
	while (*end == ' ' || *end == ';') ;
      }
	
    new_precision = 0 ; 
    new_rounding = 0 ; 
    new_exception = 0 ;

    status = lookup_string (p, &new_precision, &new_rounding, &new_exception) ;

    if (status)
      GSL_ERROR ("unrecognized IEEE mode. Valid settings are:\n\n" 
		 "  single-precision double-precision extended-precision\n"
		 "  round-to-nearest round-down round-up round-to-zero\n"
		 "  mask-invalid mask-denormalized mask-overflow "
		 "mask-underflow trap-inexact\n"
		 "\nseparated by semicolons. "
		 "(default is GSL_IEEE_MODE=\"extended;round-to-nearest\")",
		 GSL_EINVAL) ;

    if (new_precision) 
      {
	*precision = new_precision ;
	precision_count ++ ;
	if (precision_count > 1)
	  GSL_ERROR ("attempted to set IEEE precision twice", GSL_EINVAL) ;
      }

    if (new_rounding) 
      {
	*rounding = new_rounding ;
	rounding_count ++ ;
	if (rounding_count > 1)
	  GSL_ERROR ("attempted to set IEEE rounding mode twice", GSL_EINVAL) ;
      }

    if (new_exception) 
      {
	*exception_mask |= new_exception ;
	exception_count ++ ;
      }

    p = end ; 

  } while (end && *p != '\0') ;

  free(start) ;

  return GSL_SUCCESS ;
}

static int 
lookup_string (const char * p, int * precision, int * rounding, 
	       int * exception_mask)
{
  if (strcmp(p,"single-precision") == 0) 
    {
      *precision = GSL_IEEE_SINGLE_PRECISION ;
    }
  else if (strcmp(p,"double-precision") == 0) 
    {
      *precision = GSL_IEEE_DOUBLE_PRECISION ;
    }
  else if (strcmp(p,"extended-precision") == 0) 
    {
      *precision = GSL_IEEE_EXTENDED_PRECISION ;
    }
  else if (strcmp(p,"round-to-nearest") == 0) 
    {
      *rounding = GSL_IEEE_ROUND_TO_NEAREST ;
    }
  else if (strcmp(p,"round-down") == 0) 
    {
      *rounding = GSL_IEEE_ROUND_DOWN ;
    }
  else if (strcmp(p,"round-up") == 0) 
    {
      *rounding = GSL_IEEE_ROUND_UP ;
    }
  else if (strcmp(p,"round-to-zero") == 0) 
    {
      *rounding = GSL_IEEE_ROUND_TO_ZERO ;
    }
  else if (strcmp(p,"mask-invalid") == 0) 
    {
      *exception_mask = GSL_IEEE_MASK_INVALID ;
    }
  else if (strcmp(p,"mask-denormalized") == 0) 
    {
      *exception_mask = GSL_IEEE_MASK_DENORMALIZED ;
    }
  else if (strcmp(p,"mask-division-by-zero") == 0) 
    {
      *exception_mask = GSL_IEEE_MASK_DIVISION_BY_ZERO ;
    }
  else if (strcmp(p,"mask-overflow") == 0) 
    {
      *exception_mask = GSL_IEEE_MASK_OVERFLOW ;
    }
  else if (strcmp(p,"mask-underflow") == 0) 
    {
      *exception_mask = GSL_IEEE_MASK_UNDERFLOW ;
    }
  else if (strcmp(p,"trap-inexact") == 0) 
    {
      *exception_mask = GSL_IEEE_TRAP_INEXACT ;
    }
  else 
    {
      return 1 ;
    }

  return 0 ;
}




