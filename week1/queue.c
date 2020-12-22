#include <stdio.h>

int main(){
    long long n,hight[100000],h,max = 0,i;
    int l,cus[100000],p;
    scanf("%lld %d",&n,&l);
    for(i = 0;i<n; i++){
        scanf("%lld",&h);
        hight[i] = h;
    }
    for(i = 0;i<l; i++){
        scanf("%d",&p);
        cus[p-1] = 1;
    }
    for(i=0;i<n;i++){
        if(cus[i] == 1){
            if(hight[i]>max){
                max = hight[i];
                printf("0\n");
            }
            else if(hight[i]<=max){
                printf("%lld\n",max+1-hight[i]);
            }
        }
        else if(max < hight[i]){
            max = hight[i];
        }
    }
    return 0;
}