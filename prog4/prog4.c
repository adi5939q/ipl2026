#include <stdio.h>
typedef struct{
    unsigned int firstbit : 1;
    unsigned int secondbit : 1;
    unsigned int thirdbit : 1;
    unsigned int value : 5;
}Bitfield;
int main(){
    Bitfield a;
    a.firstbit=1;
    a.secondbit=0;
    a.thirdbit=1;
    a.value=25;

    printf("firstbit = %u\n",a.firstbit);
    printf("secondbit=%u\n",a.secondbit);
    printf("thirdbit=%u\n",a.thirdbit);
    printf("value=%u\n",a.value);

    printf("Size of structure =%u bytes\n",sizeof(a));

    return 0;
}