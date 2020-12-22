#include <stdio.h>

int main(){
    int n,price=0,i,p;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&p);
        if(p<=0){
            continue;
        }
        price += p;
    }
    printf("%d\n",price);
}