#include <stdio.h>
#include <math.h>

int main(){
    int a,b,c,n,i,thing,pa=0,pb=0,pc=0,noi;

    scanf("%d %d %d",&a,&b,&c);
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&thing);
        if(thing == 1){
            pa += a;
        }
        else if(thing == 2){
            pb += b;
        }
        else if(thing == 3){
            pc += c;
        }
    }
    if(pa<pb){
        noi = pa;
    }
    else{
        noi = pb;
    }
    if(pc < noi){
        noi = pc;
    }
    printf("%d\n",noi);
}