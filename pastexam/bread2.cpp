#include <iostream>
#include <map>

using namespace std;

int infor[100100][3];
map<int, int> shop;

int main(){
    long n,q,i,address,buy,b,min_price,res,y,j,tmp,minps;

    cin >> n >> q;
    for(i = 1; i <= n; i++){
        cin >> address >> buy >> b;
        shop[address] = i;
        infor[i][0] = buy;
        infor[i][1] = b;
    }
    for(i = 0; i < q; i++){
        minps = 0;
        cin >> y;
        res = 0;
        min_price = 1000001;
        tmp = y;
        for(j = 0;j <=5; j++){
            if(infor[shop[tmp]][1] > 0 && min_price > infor[shop[tmp]][0]){
                min_price = infor[shop[tmp]][0];
                minps = shop[tmp];
            }
            tmp++;
        }
        tmp = y;
        for(j = 0;j <= 5; j++){
            if(infor[shop[tmp]][1] > 0 && min_price > infor[shop[tmp]][0]){
                min_price = infor[shop[tmp]][0];
                minps = shop[tmp];
            }
            if(tmp == 1){
                break;
            }
            tmp--;
        }
        if(min_price != 1000001){
            res = min_price;
            infor[minps][1]--;
        }
        cout << res << endl;
    }   
}