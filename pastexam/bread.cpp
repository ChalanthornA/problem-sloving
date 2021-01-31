#include <iostream>
#include <map>

using namespace std;

map<long, pair<long, long> > shop;
map<long, pair<long, long> >::iterator it1,it2,it3;

int main(){
    long n,q,i,address,buy,b,min_price,res,y;

    cin >> n >> q;
    for(i = 0; i < n; i++){
        cin >> address >> buy >> b;
        shop[address].first = buy;
        shop[address].second = b;
    }
    for(i = 0; i < q; i++){
        res = 0;
        min_price = 1000001;
        cin >> y;
        it1 = shop.lower_bound(y);
        it3 = it1;
        while(1){
            if(it3 == shop.end() || it3->first > y+5){
                break;
            }
            if(min_price > shop[it3->first].first && shop[it3->first].second > 0){
                it2 = it3;
                min_price = shop[it3->first].first;
            }
            it3++;
        }
        it3 = it1;
        while(1){
            if(it3->first < y-5){
                break;
            }
            if(min_price > shop[it3->first].first && shop[it3->first].second > 0){
                it2 = it3;
                min_price = shop[it3->first].first;
            }
            if(it3 == shop.begin()){
                break;
            }
            it3--;
        }
        if(min_price != 1000001){
            res = min_price;
            shop[it2->first].second -= 1;
        }
        if(shop[it2->first].second == 0){
            shop.erase(it2);
        }
        cout << res << endl;
    }
}