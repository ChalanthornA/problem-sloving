#include <iostream>
#include <set>

using namespace std;

set<long long> lenght;
set<long long>::iterator it1;
long long l[100100];

int main(){
    long long n, q, i, tmp, j, res;
    scanf("%lld %lld", &n, &q);
    for(i = 1; i <= n; i++){
        scanf("%lld", &l[i]);
    }
    for(i = 1; i <= n; i++){
        tmp = 0;
        for(j = i; j <= n; j++){
            tmp += l[j];
            lenght.insert(tmp);
        }
    }
    for(i = 1; i <= q; i++){
        scanf("%lld", &tmp);
        it1 = lenght.upper_bound(tmp);
        it1--;
        if(tmp == *(it1)){
            printf("Y");
        }
        else{
            printf("N");
        }
    }
    printf("\n");
}