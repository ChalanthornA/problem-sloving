#include <stdio.h>
#include <string.h>

int main(){
    int n,i,num1,res=0;
    char oper;

    scanf("%d",&n);
    for(i = 0;i<n;i++){
        if(i >= 1){
            scanf(" %c",&oper);
        }
        scanf("%d",&num1);
        if(i >= 1){
            if(oper == '+'){
                res += num1;
            }
            else if(oper == '-'){
                res -= num1;
            }
        }
        else{
            res = num1;
        }
    }
    printf("%d\n",res);
}