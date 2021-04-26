#include <iostream>
#include <vector>

using namespace std;

vector<int> ans[1010], temp1, temp2;
vector<int>::iterator it1;
int dp[1010], num[1010];

int main(){
    int n, i, j, tmp, maxx, k, result;
    cin >> n;
    for(i = 1; i <= n; i++){
        cin >> num[i];
    }
    dp[1] = 1;
    ans[1].push_back(num[1]);
    for(i = 2; i <= n; i++){
        maxx = -100;
        tmp = -1;
        for(j = i-1; j > 0; j--){
            it1 = ans[j].end();
            it1--;
            if(*(it1) < num[i]){
                if(maxx < dp[j]+1){
                    maxx = dp[j]+1;
                    tmp = j;
                }
            }
        }
        if(maxx == -100){
            ans[i].push_back(num[i]);
            dp[i] = 1;
        }
        else{
            ans[i] = ans[tmp];
            ans[i].push_back(num[i]);
            dp[i] = maxx;
        } 
    }
    maxx = -100;
    for(i = 1; i <= n; i++){
        if(maxx < dp[i]){
            maxx = dp[i];
            result = i;
        }
    }
    cout << dp[result] << endl;
    for(it1 = ans[result].begin(); it1 != ans[result].end(); it1++){
        cout << *(it1) << " ";
    };
    cout << endl;
}