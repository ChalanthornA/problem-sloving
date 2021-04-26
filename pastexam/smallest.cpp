#include <iostream>

using namespace std;

long long p[200010][2];

int main(){
    long long n, m, minn = 1<<30, i, command, tmp, s, e, mid;
    p[0][1] = 1<<30;
    scanf("%lld %lld", &n, &m);
    for(i = 1; i <= n; i++){
        scanf("%lld", &p[i][0]);
        if(minn > p[i][0]){
            minn = p[i][0];
        }
        p[i][1] = minn;
    }
    for(i = 1; i <= m; i++){
        scanf("%lld %lld", &command, &tmp);
        if(command == 1){
            printf("%lld\n", p[tmp][1]);
        }
        else{
            s = 0;
            e = n+1;
            while(s < e){
                mid = (s+e)/2;
                if(tmp <= p[mid][1]){
                    s = mid+1;
                }
                else{
                    e = mid;
                }
            }
            if(tmp >= p[s][1]){
                printf("%lld\n", s-1);
            }
            else{
                printf("%lld\n", s);
            }
        }
    }
}

/*
5 8 
100 
240 
80 
90 
75 
1 1
2 95
1 4
2 80 
2 50 
1 5 
2 120 
2 100
*/