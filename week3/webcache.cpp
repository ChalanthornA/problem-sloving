#include <iostream>
#include <list>

using namespace std;

long long status[1001000];

int main(){
    long long n,m,i,tmp,res=0;
    list<long long> cache;

    cin >> n >> m;
    for(i = 0; i < m; i++){
        cin >> tmp;
        if(cache.size() < n){
            if(status[tmp] != 1){
                res += 1;
                cache.push_back(tmp);
                status[tmp] = 1;
            }
        }
        else{
            if(status[tmp] != 1){
                res += 1;
                status[tmp] = 1;
                status[*(cache.begin())] = 0;
                cache.erase(cache.begin());
                cache.push_back(tmp);
            }
        }
    }
    cout << res << endl;
}