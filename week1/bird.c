#include <stdio.h>

int main(){
    int net[1000],n,i,res;
    long long tree;

    scanf("%d",&n);
    for(i = 0;i<n; i++){
        scanf("%lld",&tree);
        net[i] = tree;
    }
    res = 0;
    for(i = 0;i<n; i++){
        if(i == 0 && net[1]<net[0]){
            res += 1;
        }
        else if(i == n-1 && net[n-1]>net[n-2]){
            res += 1;
        }
        else if(0 < i && i < n-1){
            if(net[i]>net[i-1] && net[i]>net[i+1]){
                res += 1;
            }
        }
    }
    printf("%d\n",res);
}