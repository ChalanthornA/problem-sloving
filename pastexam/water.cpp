#include <iostream>

using namespace std;

int day[1010];

int main(){
    int n, i, j, res = 0, money;
    cin >> n;
    day[0] = 0;
    for(i = 1; i <= n; i++){
        cin >> day[i];
    }
    j = 0;
    for(i = 1; i <= n; i++){
        if(day[j] - day[i] > 10){
            money = (day[j] - day[i])*10;
            if(money > 700){
                money = 700;
            }
            res += money;
        }
        j++;
    }
    cout << res << endl;
}