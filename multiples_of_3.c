//project eular exercise
//to find the sum of the multiples of 3 and 5 less than 1000
//author harisu 

#include<stdio.h>
#include<stdlib.h>

int main(){
    int sum,mult3,mult5;
    int i;
    for(i=0;i<1000;i++){
        if(i%3==0||i%5==0){
        sum+=i;
        printf("%d  ",i);
        }

    }
     printf("\nsum is %d",sum);
return 0;
}
