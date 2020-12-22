#include <stdio.h>

int main(){
    int l,n,range[201][3],i,j,max=0,st,end,sf=0;

    scanf("%d %d",&l,&n);
    for(i=1;i<=n;i++){
        scanf("%d %d",&st,&end);
        range[i][0] = st;
        range[i][1] = end;
    }
    for(i = 1; i<=l;i++){
        sf = 0;
        for(j=1; j<=n;j++){
            if(i<range[j][0] || i>=range[j][1]){
                continue;
            }
            sf += 1;
        }
        if(max<sf){
            max = sf;
        }
    }
    printf("%d\n",max);
}