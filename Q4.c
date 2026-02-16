#include <stdio.h>
#include <math.h>
#include <mach/mach_time.h>

static double
now(void)
{
    static mach_timebase_info_data_t tb;
    if (tb.denom == 0)
        mach_timebase_info(&tb);
    
    uint64_t t = mach_absolute_time();
    return t * tb.numer / tb.denom * 1e-9;
}

int
main(void)
{
    long n = 1000000;
    
    volatile double a = 1.000001;
    volatile double b = 1.0000003;
    volatile double x = 0;
    
    double t0, t1;
    
    a = 1.000001;
    t0 = now();
    for (long i = 0; i < n; i++) {
        x += a * b;
        a += 1e-12;
    }
    t1 = now();
    printf("mul:  %.3f sec\n", t1 - t0);
    
    a = 1.000001;
    t0 = now();
    for (long i = 0; i < n; i++) {
        x = a / b;
        a += 1e-12;
    }
    t1 = now();
    printf("div:  %.3f sec\n", t1 - t0);
    
    a = 1.000001;
    t0 = now();
    for (long i = 0; i < n; i++) {
        x = sqrt(a);
        a += 1e-12;
    }
    t1 = now();
    printf("sqrt: %.3f sec\n", t1 - t0);
    
    a = 1.000001;
    t0 = now();
    for (long i = 0; i < n; i++) {
        x = sin(a);
        a += 1e-12;
    }
    t1 = now();
    printf("sin:  %.3f sec\n", t1 - t0);
    
    fprintf(stderr, "%.3f\n", x);
    return 0;
}