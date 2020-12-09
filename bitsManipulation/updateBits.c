#include <stdio.h>

int update_bits(int n, int m, int i, int j){
    int ret = (1<<i) - 1;
    ret &= n;
    return ((n >> (j+1)) << (j+1)) | (m << i) | ret;
}

int main() {
    int n = 0x12345678;
    int m = 0x000000ab;
    int i=8, j=15;
    int ret = update_bits(n, m, i, j);
    printf("Before updating, n = %08x, m = %08x, and i = %d, j = %d\n", n, m, i, j);
    printf("After updating: %08x\n", ret);
    return 0;
}
