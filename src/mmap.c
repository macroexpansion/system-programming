#include <stdio.h>
#include <sys/mman.h>

#define N 10

int main(int argc, char** argv) {
    const int size = N * 10;

    int* ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
    if (ptr == MAP_FAILED) {
        printf("map failed");
        return -1;
    }

    ptr[0] = 0;
    ptr[1] = 1;

    for (int i = 2; i < N; ++i) {
        ptr[i] = ptr[i - 1] + ptr[i - 2];
    }

    int status = munmap(ptr, size);
    if (status == -1) {
        printf("unmap failed");
        return -1;
    }
}
