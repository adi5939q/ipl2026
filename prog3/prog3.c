#include <stdio.h>

void printbits(int num);
int countsetbits(int num);


int main() {
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);

    printf("\nBinary Representation: ");
    printbits(n);

    printf("\nNumber of 1 bits = %d\n", countsetbits(n));
    
    return 0;
}

void printbits(int num){
    int totalbits = sizeof(int) * 8;
    for(int i=totalbits -1; i>=0; i--){
        int bit = (num >> i)&1;
        printf("%d", bit);
 
    }
    printf("\n");
}

int countsetbits(int num){
    int count = 0;
    while(num!=0){
        if((num&1)==1)
            count++;
        
            num = num>>1;
    }


    return count;
}