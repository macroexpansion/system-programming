#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "tlpi_hdr.h"
#include "test.h"

int main(int argc, char **argv) {
    float t = 1.131;
    printf("%4.2f\n", t);

    test();

    int32_t a = min(1, 2); 
    printf("%d\n", a);
}
