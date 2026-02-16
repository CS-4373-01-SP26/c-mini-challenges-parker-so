#include <stdio.h>
#include <math.h>
#include <mach/mach_time.h>

static double
clock_time(void)
{
    static mach_timebase_info_data_t tb;
    if (tb.denom == 0)
        mach_timebase_info(&tb);
    
    uint64_t t = mach_absolute_time();
    return (t * tb.numer / tb.denom) * 1e-9;
}

int
main(void)
{
    int n = 6;
    double side = 1.0;
    
    double start = clock_time();
    
    printf("n,pi_in,pi_out\n");
    
    while (n <= 100) {
        double half = side * 0.5;
        double cosx = sqrt(1.0 - half * half);
        
        double pi_in  = 0.5 * n * side;
        double pi_out = 0.5 * n * (side / cosx);
        
        printf("%d,%.15f,%.15f\n", n, pi_in, pi_out);
        
        side = sqrt(2.0 - 2.0 * cosx);
        n *= 2;
    }
    
    double end = clock_time();
    fprintf(stderr, "time: %.6f s\n", end - start);
    
    return 0;
}