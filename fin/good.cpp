#include <iostream>
#include <math.h>

using namespace std;

long long table[220][220];
double res[220][220];

int main(){
    long long n, m, i, j, k, l, tmp, count;
    double minn = 1<<30,re,ss;
    scanf("%d %d",&n,&m);
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            scanf("%d",&table[i][j]);
        }
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            count = 0;
            ss = 0;
            tmp = table[i][j];
            for(k = 1; k <= n; k++){
                ss += abs(tmp - table[k][j]);
                count++;
            }
            for(k = 1; k <= m; k++){
                ss += abs(tmp - table[i][k]);
                count++;
            }
            re = ss/(count-2);
            res[i][j] = re;


        }
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
           if(minn > res[i][j]){
                minn = res[i][j];
                k = i;
                l = j;
            } 
        }
    }
    printf("%d\n",table[k][l]);
}