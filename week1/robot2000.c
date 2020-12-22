#include <stdio.h>
#include <string.h>

int main(){
    int i=0,j=0,l,k;
    char force[101],tid[6] = "NESW",tang;

    scanf(" %s",force);
    l = strlen(force);
    tang = 'N';
    for(k=0;k<l;k++){
        if(force[k] == tang){
            printf("F");
        }
        else if(force[k] == 'Z'){
            printf("Z");
            tang = 'N';
            i = 0;
        }
        else{
            while(1){
                printf("R");
                if(i == 3){
                    i = -1;
                }
                i+=1;
                //printf("%c\n",tid[i]);
                //printf("%d\n",i);
                if(tid[i] == force[k]){
                    tang = force[k];
                    printf("F");
                    break;
                }
            }
        }
    }
    printf("\n");
}