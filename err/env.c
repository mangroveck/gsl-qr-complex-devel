/* err/env.c
 * 
 * Copyright (C) 2001 Brian Gough
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <config.h>
#include <stdlib.h>
#include <gsl/gsl_errno.h>

#define STR_EQ (x,y) (strcmp((x),(y)) == 0)

void
gsl_err_env_setup (void)
{
  const char * p = getenv("GSL_ERROR_MODE") ;

  if (p == 0)  /* GSL_ERROR_MODE environment variable is not set */
    return ;

  if (*p == '\0') /* GSL_ERROR_MODE environment variable is empty */
    return ;

  printf("GSL_ERROR_MODE=\"") ;
  
  if (STR_EQ(p, "abort"))
    {
      gsl_err_set_handler (NULL);
      printf("abort") ;
    }

  printf("\"\n") ;
}





