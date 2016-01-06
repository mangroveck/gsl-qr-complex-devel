#define hahn1_N      236
#define hahn1_P      7

#define hahn1_NTRIES 1

static double hahn1_x0a[hahn1_P] = { 10, -1, 0.05, -0.00001, -0.05, 0.001, -0.000001 };
static double hahn1_x0b[hahn1_P] = { 1, -0.1, 0.005, -0.000001, -0.005, 0.0001, -0.0000001}; 

static double hahn1_epsrel = 1.0e-5;

static double hahn1_sigma[hahn1_P] = {
  1.7070154742E-01, 1.2000289189E-02, 2.2508314937E-04, 2.7578037666E-07,
  2.4712888219E-04, 1.0449373768E-05, 1.3027335327E-08
};

static double hahn1_F1[hahn1_N] = {
        .591E0, 1.547E0, 2.902E0, 2.894E0, 4.703E0,
       6.307E0, 7.03E0 , 7.898E0, 9.470E0, 9.484E0,
      10.072E0, 10.163E0, 11.615E0, 12.005E0, 12.478E0,
      12.982E0, 12.970E0, 13.926E0, 14.452E0, 14.404E0,
      15.190E0, 15.550E0, 15.528E0, 15.499E0, 16.131E0,
      16.438E0, 16.387E0, 16.549E0, 16.872E0, 16.830E0,
      16.926E0, 16.907E0, 16.966E0, 17.060E0, 17.122E0,
      17.311E0, 17.355E0, 17.668E0, 17.767E0, 17.803E0,
      17.765E0, 17.768E0, 17.736E0, 17.858E0, 17.877E0,
      17.912E0, 18.046E0, 18.085E0, 18.291E0, 18.357E0,
      18.426E0, 18.584E0, 18.610E0, 18.870E0, 18.795E0,
      19.111E0, .367E0, .796E0, 0.892E0, 1.903E0,
       2.150E0, 3.697E0, 5.870E0, 6.421E0, 7.422E0,
       9.944E0, 11.023E0, 11.87E0 , 12.786E0, 14.067E0,
      13.974E0, 14.462E0, 14.464E0, 15.381E0, 15.483E0,
      15.59E0 , 16.075E0, 16.347E0, 16.181E0, 16.915E0,
      17.003E0, 16.978E0, 17.756E0, 17.808E0, 17.868E0,
      18.481E0, 18.486E0, 19.090E0, 16.062E0, 16.337E0,
      16.345E0, 16.388E0, 17.159E0, 17.116E0, 17.164E0,
      17.123E0, 17.979E0, 17.974E0, 18.007E0, 17.993E0,
      18.523E0, 18.669E0, 18.617E0, 19.371E0, 19.330E0,
       0.080E0, 0.248E0, 1.089E0, 1.418E0, 2.278E0,
       3.624E0, 4.574E0, 5.556E0, 7.267E0, 7.695E0,
       9.136E0, 9.959E0, 9.957E0, 11.600E0, 13.138E0,
      13.564E0, 13.871E0, 13.994E0, 14.947E0, 15.473E0,
      15.379E0, 15.455E0, 15.908E0, 16.114E0, 17.071E0,
      17.135E0, 17.282E0, 17.368E0, 17.483E0, 17.764E0,
      18.185E0, 18.271E0, 18.236E0, 18.237E0, 18.523E0,
      18.627E0, 18.665E0, 19.086E0, 0.214E0, 0.943E0,
       1.429E0, 2.241E0, 2.951E0, 3.782E0, 4.757E0,
       5.602E0, 7.169E0, 8.920E0, 10.055E0, 12.035E0,
      12.861E0, 13.436E0, 14.167E0, 14.755E0, 15.168E0,
      15.651E0, 15.746E0, 16.216E0, 16.445E0, 16.965E0,
      17.121E0, 17.206E0, 17.250E0, 17.339E0, 17.793E0,
      18.123E0, 18.49E0 , 18.566E0, 18.645E0, 18.706E0,
      18.924E0, 19.1E0  , 0.375E0, 0.471E0, 1.504E0,
       2.204E0, 2.813E0, 4.765E0, 9.835E0, 10.040E0,
      11.946E0, 12.596E0, 13.303E0, 13.922E0, 14.440E0,
      14.951E0, 15.627E0, 15.639E0, 15.814E0, 16.315E0,
      16.334E0, 16.430E0, 16.423E0, 17.024E0, 17.009E0,
      17.165E0, 17.134E0, 17.349E0, 17.576E0, 17.848E0,
      18.090E0, 18.276E0, 18.404E0, 18.519E0, 19.133E0,
      19.074E0, 19.239E0, 19.280E0, 19.101E0, 19.398E0,
      19.252E0, 19.89E0 , 20.007E0, 19.929E0, 19.268E0,
      19.324E0, 20.049E0, 20.107E0, 20.062E0, 20.065E0,
      19.286E0, 19.972E0, 20.088E0, 20.743E0, 20.83E0 ,
      20.935E0, 21.035E0, 20.93E0 , 21.074E0, 21.085E0,
      20.935E0
};


static double hahn1_F0[hahn1_N] = {
    24.41E0, 34.82E0, 44.09E0, 45.07E0, 54.98E0,
    65.51E0, 70.53E0, 75.70E0, 89.57E0, 91.14E0,
    96.40E0, 97.19E0, 114.26E0, 120.25E0, 127.08E0,
   133.55E0, 133.61E0, 158.67E0, 172.74E0, 171.31E0,
   202.14E0, 220.55E0, 221.05E0, 221.39E0, 250.99E0,
   268.99E0, 271.80E0, 271.97E0, 321.31E0, 321.69E0,
   330.14E0, 333.03E0, 333.47E0, 340.77E0, 345.65E0,
   373.11E0, 373.79E0, 411.82E0, 419.51E0, 421.59E0,
   422.02E0, 422.47E0, 422.61E0, 441.75E0, 447.41E0,
   448.7E0 , 472.89E0, 476.69E0, 522.47E0, 522.62E0,
   524.43E0, 546.75E0, 549.53E0, 575.29E0, 576.00E0,
   625.55E0, 20.15E0, 28.78E0, 29.57E0, 37.41E0,
    39.12E0, 50.24E0, 61.38E0, 66.25E0, 73.42E0,
    95.52E0, 107.32E0, 122.04E0, 134.03E0, 163.19E0,
   163.48E0, 175.70E0, 179.86E0, 211.27E0, 217.78E0,
   219.14E0, 262.52E0, 268.01E0, 268.62E0, 336.25E0,
   337.23E0, 339.33E0, 427.38E0, 428.58E0, 432.68E0,
   528.99E0, 531.08E0, 628.34E0, 253.24E0, 273.13E0,
   273.66E0, 282.10E0, 346.62E0, 347.19E0, 348.78E0,
   351.18E0, 450.10E0, 450.35E0, 451.92E0, 455.56E0,
   552.22E0, 553.56E0, 555.74E0, 652.59E0, 656.20E0,
    14.13E0, 20.41E0, 31.30E0, 33.84E0, 39.70E0,
    48.83E0, 54.50E0, 60.41E0, 72.77E0, 75.25E0,
    86.84E0, 94.88E0, 96.40E0, 117.37E0, 139.08E0,
   147.73E0, 158.63E0, 161.84E0, 192.11E0, 206.76E0,
   209.07E0, 213.32E0, 226.44E0, 237.12E0, 330.90E0,
   358.72E0, 370.77E0, 372.72E0, 396.24E0, 416.59E0,
   484.02E0, 495.47E0, 514.78E0, 515.65E0, 519.47E0,
   544.47E0, 560.11E0, 620.77E0, 18.97E0, 28.93E0,
    33.91E0, 40.03E0, 44.66E0, 49.87E0, 55.16E0,
    60.90E0, 72.08E0, 85.15E0, 97.06E0, 119.63E0,
   133.27E0, 143.84E0, 161.91E0, 180.67E0, 198.44E0,
   226.86E0, 229.65E0, 258.27E0, 273.77E0, 339.15E0,
   350.13E0, 362.75E0, 371.03E0, 393.32E0, 448.53E0,
   473.78E0, 511.12E0, 524.70E0, 548.75E0, 551.64E0,
   574.02E0, 623.86E0, 21.46E0, 24.33E0, 33.43E0,
    39.22E0, 44.18E0, 55.02E0, 94.33E0, 96.44E0,
   118.82E0, 128.48E0, 141.94E0, 156.92E0, 171.65E0,
   190.00E0, 223.26E0, 223.88E0, 231.50E0, 265.05E0,
   269.44E0, 271.78E0, 273.46E0, 334.61E0, 339.79E0,
   349.52E0, 358.18E0, 377.98E0, 394.77E0, 429.66E0,
   468.22E0, 487.27E0, 519.54E0, 523.03E0, 612.99E0,
   638.59E0, 641.36E0, 622.05E0, 631.50E0, 663.97E0,
   646.9E0 , 748.29E0, 749.21E0, 750.14E0, 647.04E0,
   646.89E0, 746.9E0 , 748.43E0, 747.35E0, 749.27E0,
   647.61E0, 747.78E0, 750.51E0, 851.37E0, 845.97E0,
   847.54E0, 849.93E0, 851.61E0, 849.75E0, 850.98E0,
   848.23E0
};

static void
hahn1_checksol(const double x[], const double sumsq,
               const double epsrel, const char *sname,
               const char *pname)
{
  size_t i;
  const double sumsq_exact = 1.5324382854E+00;
  const double hahn1_x[hahn1_P] = {
     1.0776351733E+00, -1.2269296921E-01, 4.0863750610E-03,
    -1.4262662514E-06, -5.7609940901E-03, 2.4053735503E-04,
    -1.2314450199E-07 };

  gsl_test_rel(sumsq, sumsq_exact, epsrel, "%s/%s sumsq",
               sname, pname);

  for (i = 0; i < hahn1_P; ++i)
    {
      gsl_test_rel(x[i], hahn1_x[i], epsrel, "%s/%s i=%zu",
                   sname, pname, i);
    }
}

static int
hahn1_f (const gsl_vector * x, void *params, gsl_vector * f)
{
  double b[hahn1_P];
  size_t i;

  for (i = 0; i < hahn1_P; i++)
    {
      b[i] = gsl_vector_get(x, i);
    }

  for (i = 0; i < hahn1_N; i++)
    {
      double t = hahn1_F0[i];
      double y = ((b[0] + t* (b[1]  + t * (b[2] + t * b[3])))
                  / (1 + t*(b[4]  + t *(b[5] + t*b[6]))));
      gsl_vector_set (f, i, hahn1_F1[i] - y);
    }

  (void)params; /* avoid unused parameter warning */

  return GSL_SUCCESS;
}

static int
hahn1_df (const gsl_vector * x, void *params, gsl_matrix * df)
{
  double b[hahn1_P];
  size_t i;

  for (i = 0; i < hahn1_P; i++)
    {
      b[i] = gsl_vector_get(x, i);
    }

  for (i = 0; i < hahn1_N; i++)
    {
      double t = hahn1_F0[i];
      double u = (b[0] + t*(b[1] + t*(b[2] + t * b[3])));
      double v = (1 + t*(b[4] + t*(b[5] + t*b[6])));
      gsl_matrix_set (df, i, 0, -1/v);
      gsl_matrix_set (df, i, 1, -t/v);
      gsl_matrix_set (df, i, 2, -t*t/v);
      gsl_matrix_set (df, i, 3, -t*t*t/v);
      gsl_matrix_set (df, i, 4, t*u/(v*v));
      gsl_matrix_set (df, i, 5, t*t*u/(v*v));
      gsl_matrix_set (df, i, 6, t*t*t*u/(v*v));
    }

  (void)params; /* avoid unused parameter warning */

  return GSL_SUCCESS;
}

static gsl_multifit_nlinear_fdf hahn1_func =
{
  hahn1_f,
  hahn1_df,
  NULL, /* analytic expression too complex */
  hahn1_N,
  hahn1_P,
  NULL,
  0,
  0,
  0
};

static test_fdf_problem hahn1a_problem =
{
  "nist-hahn1a",
  hahn1_x0a,
  hahn1_sigma,
  &hahn1_epsrel,
  hahn1_NTRIES,
  &hahn1_checksol,
  &hahn1_func
};

static test_fdf_problem hahn1b_problem =
{
  "nist-hahn1b",
  hahn1_x0b,
  hahn1_sigma,
  &hahn1_epsrel,
  hahn1_NTRIES,
  &hahn1_checksol,
  &hahn1_func
};
