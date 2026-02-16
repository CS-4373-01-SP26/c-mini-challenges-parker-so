#include <stdio.h>
#include <stdlib.h>
#include <mach/mach_time.h>

static double
get_time(void)
{
    static mach_timebase_info_data_t tb;
    if (tb.denom == 0)
        mach_timebase_info(&tb);
    
    uint64_t t = mach_absolute_time();
    return t * tb.numer / tb.denom * 1e-9;
}

int
main(int argc, char **argv)
{
    char *file = "mv.txt";
    if (argc > 1)
        file = argv[1];
    
    FILE *f = fopen(file, "r");
    
    int rows, cols;
    fscanf(f, "%d %d", &rows, &cols);
    
    double *A = malloc(rows * cols * sizeof(double));
    double *y = malloc(rows * sizeof(double));
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int val;
            fscanf(f, "%d", &val);
            A[i * cols + j] = val;
        }
    }
    
    int n;
    fscanf(f, "%d", &n);
    
    double *x = malloc(n * sizeof(double));
    for (int j = 0; j < n; j++) {
        int val;
        fscanf(f, "%d", &val);
        x[j] = val;
    }
    
    fclose(f);
    
    double start = get_time();
    
    for (int i = 0; i < rows; i++) {
        double sum = 0;
        for (int j = 0; j < cols; j++)
            sum += A[i * cols + j] * x[j];
        y[i] = sum;
    }
    
    double end = get_time();
    
    for (int i = 0; i < rows; i++)
        printf("%.0f\n", y[i]);
    
    fprintf(stderr, "%.6f\n", end - start);
    
    free(A);
    free(x);
    free(y);
    return 0;
}