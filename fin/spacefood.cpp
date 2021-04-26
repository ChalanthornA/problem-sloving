#include <iostream>

using namespace std;



int main(){
    int n, m, k, food = 0, tmp, res = 0, i;
    cin >> n >> m >> k;
    for(i = 1; i <= n; i++){
        if(res == -1){
            continue;
        }
        cin >> tmp;
        food += tmp;
        if(food >= k){
            food -= k;
        }
        else{
            if(food < m){
                res = -1;
            }
            else{
                food = 0;
                res += 1;
            }
        }
    }
    cout << res << endl;
}