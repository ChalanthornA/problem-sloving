#include <iostream>

using namespace std;
int line[100100];
int check[100100];
int dp[100100];

int main(){
    int n, i, co, res = 0, j, minn, maxx, minnres, tmp, tmp2, k;
    cin >> n;
    for(i = 1; i <= n; i++){
        cin >> line[i];
    }
    dp[1] = 1<<30;
    for(i = 2; i <= n; i++){
        minn = line[i];
        maxx = line[i];
        minnres = 1<<30;
        for(j = i-1; j >= 0; j--){
            if(i-j > 10){
                break;
            }
            if(i-j == 1){
                continue;
            }
            if(maxx < line[j+1]){
                maxx = line[j+1];
            }
            if(minn > line[j+1]){
                minn = line[j+1];
            }
            tmp = maxx - minn + dp[j];
            if(minnres > tmp){
                minnres = tmp;
            }
        }
        dp[i] = minnres;
        // for(j = 1; j <= n; j++){
        //     cout << dp[j] << " ";
        // }
        // cout << endl;
    }
    cout << dp[n] << endl;
}

// 2 1 1 1 1 1 1 1 1 1 1 2 6 6 6