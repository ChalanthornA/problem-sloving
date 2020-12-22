#include <stdio.h>
#include <string.h>

int main(){
    int i=0,j=0,l,k;
    char force[101];

    scanf(" %s",force);
    l = strlen(force);
    for(k=0;k<l;k++){
        if(force[k] == 'N'){
            j+=1;
        }
        else if(force[k] == 'E'){
            i+=1;
        }
        else if(force[k] == 'S'){
            j-=1;
        }
        else if(force[k] == 'W'){
            i-=1;
        }
        else{
            i = 0;
            j = 0;
        }
    }
    printf("%d %d\n",i,j);
}