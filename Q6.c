#include <stdio.h>

typedef void (*xform)(char *);

static void
get_line(char *buf, int size)
{
    int i = 0;
    int c;
    
    while ((c = getchar()) != EOF && c != '\n' && i < size - 1) {
        buf[i++] = c;
    }
    buf[i] = 0;
}

static void
reverse(char *s)
{
    char *l = s;
    char *r = s;
    
    while (*r) r++;
    if (r == l) return;
    r--;
    
    while (l < r) {
        char tmp = *l;
        *l++ = *r;
        *r-- = tmp;
    }
}

static void
do_xform(char *s, xform f)
{
    printf("in:  %s\n", s);
    f(s);
    printf("out: %s\n", s);
}

int
main(void)
{
    char buf[1024];
    
    get_line(buf, sizeof(buf));
    do_xform(buf, reverse);
    
    return 0;
}