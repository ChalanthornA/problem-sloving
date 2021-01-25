#include <iostream>
#include <set>
#include <map>

using namespace std;

int main(){
    long n,k,i,tmp,stackprice = 0,tmp2,j,maxbook,fir;
    set<long, greater<long> > price;
    map<long, long> number;

    cin >> n >> k;
    for(i = 0; i<n;i++){
        cin >> tmp;
        if(i == 0){
            fir = tmp;
        }
        stackprice += tmp;
        price.insert(stackprice);
        number[stackprice] = i+1;
    }
    for(i = 0; i<k; i++){
        cin >> tmp;
        if(tmp < fir){
            cout << 0 << endl;
        }
        else{
            tmp2 = *(price.lower_bound(tmp));
            maxbook = number[tmp2];
            cout << maxbook << endl;
        }
    }
}