#include <iostream>

using namespace std;

int dp[5010][5010][2], food[5000];

int main(){
    int n, k, i, j, w, minn = 9999999, tmp1, tmp2;
    cin >> n >> k;
    for(i = 1; i <= n; i++){
        cin >> food[i];
    }
    for(i = 0; i <= n; i++){
        for(j = 0; j <= n; j++){
            if(i == 0 && j == 0){
                dp[i][j][0] = 0;
                dp[i][j][1] = k;
            }
            else if(i+j > n){
                dp[i][j][0] = -100;
                dp[i][j][1] = -100;
            }
            else if(i == 0 && j != 0){
                dp[i][j][0] = dp[i][j-1][0] + food[j];
                dp[i][j][1] = k;
            }
            else if(i != 0 && j == 0){
                if(dp[i-1][j][1] < food[i]){
                    dp[i][j][0] = dp[i-1][j][0] + food[i];
                    dp[i][j][1] = k;
                }
                else{
                    dp[i][j][0] = dp[i-1][j][0];
                    dp[i][j][1] = dp[i-1][j][1] - food[i];
                }
            }
            else{
                if(dp[i-1][j][1] - food[i+j] < 0){
                    dp[i][j][0] = dp[i-1][j][0] + food[i+j];
                    dp[i][j][1] = k;
                    cout<< "h";
                }
                else{
                    tmp1 = dp[i-1][j][0];
                    tmp2 = dp[i][j-1][0] + food[i+j];
                    if(tmp1 < tmp2){
                        dp[i][j][0] = tmp1;
                        dp[i][j][1] = dp[i-1][j][1] - food[i+j];
                    }
                    else{
                        dp[i][j][0] = tmp2;
                        dp[i][j][1] = k;
                    }
                }
            }
            cout << "[" << dp[i][j][0] << "," << dp[i][j][1] << "]";
            if(i+j == n){
                if(minn > dp[i][j][0]){
                    minn = dp[i][j][0];
                    // cout << i << j << endl;
                }
            }
        }
        cout << endl;
    }
    cout << minn << endl;
}