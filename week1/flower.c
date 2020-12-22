#include <stdio.h>

int main(){
    long l,n,st = 0,i=0,j=0,res = 1,tmp=0,end = 1,nub,start = 0;

    scanf("%ld %ld",&l,&n);
    while(1){
        if(tmp == 0){
            start += l;
            i = start-1;
            j = 0;
            tmp = 1;
            nub = l;
        }
        // printf("%ld %ld\n",i,j);
        if(i-1<-1){
            tmp = 0;
            res += 1;
            end = j+1;
            continue;
        }
        if(j < end){
            st += l;
        }
        if(j >= end){
            nub -= 1;
            st += nub;
        }
        // printf("st is %ld\n",st);
        i-=1;
        j+=1;
        if(st >= n){
            break;
        }
    }
    printf("%ld\n",res);
}