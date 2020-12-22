#include <stdio.h>
#include <math.h>

int main(){
    int l,i,j,res;
    long n;
    scanf("%d %ld",&l,&n);
    res = l;
    for(i=1; i<=l; i++){
        if(n>=pow(i,2)){
            n -= pow(i,2);
            res -= 1;
        }
        else{
            break;
        }
    }
    printf("%d\n",res);
}