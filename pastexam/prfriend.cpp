#include <iostream>
#include <math.h>

using namespace std;

int prime[200010];

int main(){
    int l, r, i, past = 0, count = 0, tmp, j;

    for(i=2; i <= sqrt(200000); i++){
        if(prime[i] == 0){
            for(j=i*i; j <= 200000; j += i){
                prime[j] = 1;
            }
        }
    }
    cin >> l >> r;
    for(i = l; i <= r; i++){
        if(i == 1){
            continue;
        }
        if(prime[i] == 0){
            if(past == 0){
                past = i;
            }
            else{
                if(abs(i - past) == 2){
                    count += 1;
                    // cout << i << " " << past << endl;
                }
                past = i;
            }
        }
    }
    cout << count << endl;
}