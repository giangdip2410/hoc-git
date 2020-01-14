/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>
#include<math.h>
int reverse(int n){
    int no = n;
    int digit = 0;
    while (no != 0 ){
        no = no/10;
        digit++;
    }
    int *a = malloc(digit * sizeof(int));
    a[0] = n % 10;
    int check = a[0];
    for (int i = 1 ; i < digit; i++){
        a[i] = (int)((n - check)/pow(10,i)) % 10;
        check += (a[i] * pow(10,i));
    }
    for (int i = 0; i < digit/2; i++){
        int x = a[i];
        a[i] = a[digit-1-i];
        a[digit-1-i] = x;
    }
    int reverse = 0;
    for ( int i = 0; i < digit; i++){
        reverse += a[i] * pow(10,i);
    }
    return reverse;
    
    
}
int main()
{
    int i,j,k,count=0;
    scanf("%d %d %d",&i, &j,&k);
    for (int n = i ; n <j+1; n++){
        if( (int)(n- reverse(n)) % k == 0)
            count++;
    }
    printf("%d", count);

}
