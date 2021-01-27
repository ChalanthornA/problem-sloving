#include <iostream>
#include <set>
#include <map>

using namespace std;

long long p[1100],pricemin[1100];

int main(){
    long long n,k,i,j,pricesum = 0,tmp,pricemax,tmp2,res,nobook,minprice = 1100000000,maxbook=0;
    set<long long> price;
    set<long long>::iterator it1,it2,it3;
    map<long long, long long> num;

    cin >> n >> k;
    price.insert(0);
    num[0] = 0;
    for(i = 0; i<n; i++){
        cin >> tmp;
        if(tmp < minprice){
            minprice = tmp;
        }
        p[i+1] = tmp;
    }
    for(i = 1; i <= n; i++){
        pricesum = 0;
        for(j = i; j <= n; j++){
            pricesum += p[j];
            if(j-i+1 > maxbook){
                maxbook = (j-i+1);
            }
            if(pricemin[j-i+1] == 0){
                pricemin[j-i+1] = pricesum;
            }
            else if(pricemin[j-i+1] > pricesum){
                pricemin[j-i+1] = pricesum;
            }
        }
    }
    for(i = 0; i<k; i++){
        cin >> tmp;
        res = 0;
        if(tmp < minprice){
            res = 0;
        }
        else{
            for(j = 1; j<=maxbook; j++){
                if(pricemin[j] == 0){
                    continue;
                }
                else if(pricemin[j] > tmp){
                    continue;
                }
                else{
                    if(pricemin[j] <= tmp){
                        if(j > res){
                            res = j;
                        }
                    }
                    if(res == maxbook){
                        break;
                    }
                }
            }
        }
        cout << res << endl;
    }
}