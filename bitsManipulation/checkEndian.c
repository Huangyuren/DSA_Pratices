#include <stdio.h>

typedef union {
    unsigned long item;
    unsigned char ca[4];
}endian_example;

int main() {
    endian_example endian;
    endian.item = 0x12345678;
    if(endian.ca[0] == 0x12 && endian.ca[1] == 0x34 && endian.ca[2] == 0x56 && endian.ca[3] == 0x78) {
        printf("This machine is little endian\n");
    }else if(endian.ca[0] == 0x78 && endian.ca[1] == 0x56 && endian.ca[2] == 0x34 && endian.ca[3] == 0x12){
        printf("This machine is big endian\n");
    }else printf("Unknown endian\n");
    printf("%8lX in memory be like:\n", endian.item);
    for(int i=0; i<4; i++){
        printf("%p: %02x\n", &endian.ca[i], endian.ca[i]);
    }
    return 0;
}
