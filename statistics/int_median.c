#include <gsl_statistics_int.h>

double
gsl_stats_int_median_from_sorted_data (const int sorted_data[], unsigned int n)
{
  double median ;
  unsigned int lhs = (n - 1) / 2 ;
  unsigned int rhs = n / 2 ;
  
  if (n == 0)
    return 0.0 ;

  if (lhs == rhs)
    {
      median = sorted_data[lhs] ;
    }
  else 
    {
      median = (sorted_data[lhs] + sorted_data[rhs])/2.0 ;
    }

  return median ;
}

