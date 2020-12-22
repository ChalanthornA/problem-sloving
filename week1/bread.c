#include <stdio.h>

int main(){
    int w,h,m,n,res1=0,res2=0,i,knife,j,area;
    int breadx[10000], bready[10000], knifex[10000], knifey[10000];
    
    scanf("%d %d %d %d",&w,&h,&m,&n);
    for(i = 0; i<=m; i++){
        if(i < m){
            scanf("%d",&knife);
            knifex[i] = knife;
        }
        if(i == 0){
            breadx[i] = knife;
        }
        else if(i>0 && i<m){
            breadx[i] = knife-knifex[i-1];
        }
        else if(i == m){
            breadx[i] = w - knife;
        }
    }
    for(i = 0; i<=n; i++){
        if(i < n){
            scanf("%d",&knife);
            knifey[i] = knife;
        }
        if(i == 0){
            bready[i] = knife;
        }
        else if(i>0 && i<n){
            bready[i] = knife-knifey[i-1];
        }
        else if(i == n){
            bready[i] = h - knife;
        }
    }
    for(i = 0; i<=m; i++){
        for(j = 0; j<=n; j++){
            area = breadx[i] * bready[j];
            if(res2 < area){
                if(res1 < area){
                    res2 = res1;
                    res1 = area;
                }
                else{
                    res2 = area;
                }
            }
        }
    }
    printf("%d %d\n",res1,res2);
}
