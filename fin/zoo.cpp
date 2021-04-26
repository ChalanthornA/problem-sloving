#include <iostream>

using namespace std;

int zoo[15][15];

int main(){
    int r, c, b, t, count = 0, tmp, i , j, k, st = 0, summ;

    cin >> r >> c >> b >> t;
    for(i = 1; i <= r; i++){
        for(j = 1; j <= c; j++){
            cin >> zoo[i][j];
        }
    }
    tmp = b;
    for(i = 1; i <= r; i++){
        tmp = b;
        for(j = 1; j <= c; j++){
            if(tmp > zoo[i][j]*t){
                tmp -= zoo[i][j] * t;
            }
            else{
                for(k = 1; k <= zoo[i][j]; k++){
                    if(tmp >= t){
                        tmp -= t;
                    }
                    else{
                        tmp = b;
                        count += 1;
                        tmp -= t;
                    }
                }
            }
        }   
        if(tmp != b){
            count += 1;
        }
    }
    cout << count << endl;
}