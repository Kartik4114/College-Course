#include<stdio.h>
#include<math.h>

 int main(){

    int bit1,bit2;

    printf("Enter bit1 : ");
    scanf("%d",&bit1);

    printf("Enter bit2 : ");
    scanf("%d",&bit2);


    // AND GATE
    int and_gate = bit1 & bit2;
    printf("Output of AND gate is : %d ",and_gate);

    // NAND GATE
    printf("\nOutput of NAND gate is : %d ",abs(1-and_gate));

    // OR GATE
    int or_gate = bit1 | bit2;
    printf("\nOutput of OR gate is : %d ",or_gate);

    // NOR GATE
    printf("\nOutput of NOR gate is : %d ",abs(1-or_gate));

    // NOT GATE
    printf("\nOutput of NOT gate is : %d ",abs(1-bit1));

    // XOR gate
    int xor_gate=bit1^bit2;
    printf("\nOutput of XOR gate is : %d ",xor_gate);



    return 0;
}