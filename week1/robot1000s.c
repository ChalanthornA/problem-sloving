#include <stdio.h>
#include <string.h>

int main(){
    int n=0,e=0,s=0,w=0,l,i,emp,m=0;
    char force[101];

    scanf(" %s",force);
    scanf("%d",&emp);
    l = strlen(force);
    for(i=0;i<l;i++){
        if(force[i] == 'N'){
            n += 1;
        }
        else if(force[i] == 'E'){
            e += 1;
        }
        else if(force[i] == 'S'){
            s += 1;
        }
        else if(force[i] == 'W'){
            w += 1;
        }
    }
    for(i=0;i<emp;i++){
        m=0;
        while(1){
            m+=1;
            if(n == m){
                n-=1;
                break;
            }
            else if(e == m){
                e -= 1;
                break;
            }
            else if(s == m){
                s -= 1;
                break;
            }
            else if(w == m){
                w -= 1;
                break;
            }
        }
    }
    if(n>s){
        n -= s;
        s = 0;
    }
    else if(n == s){
        n = 0;
        s = 0;
    }
    else{
        s -= n;
        n = 0;
    }
    if(e>w){
        e -= w;
        w = 0;
    }
    else if(w == s){
        w = 0;
        s = 0;
    }
    else{
        w -= e;
        e = 0;
    }
    printf("%d\n",(n+e+s+w)*2);
}