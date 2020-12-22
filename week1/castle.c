#include <stdio.h>
#include <math.h>

int main(){
    long n,i = 1,number = 3,time = 0;
    scanf("%ld",&n);
    while(1){
        if(n <= i){
            break;
        }
        i+=number;
        number += 2;
        time += 1;
    }
    if(time % 2 == 0){
        if(n%2 == 0){
            printf("%ld\n",(2*time)-1);
        }
        else{
            printf("%ld\n",2*time);
        }
    }
    else{
        if(n%2 == 0){
            printf("%ld\n",(2*time));
        }
        else{
            printf("%ld\n",(2*time)-1);
        }
    }
}