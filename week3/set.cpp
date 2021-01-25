#include <iostream>
#include <set>

using namespace std;

int main(){
    long long n,m,t1,t2,t3,tmp,maxint = -99999,i,minint = 1000000000;
    set<long long> res;
    set<long long>::iterator it1;

    cin >> n >> m;
    for(i = 0; i<n; i++){
        cin >> t1;
        if(maxint < t1){
            maxint = t1;
        }
        if(minint > t1){
            minint = t1;
        }
        res.insert(t1);
    }
    for(i = 0;i<m;i++){
        cin >> t2;
        if(t2 >= maxint){
            cout << maxint << endl;
        }
        else if(t2 <= minint){
            cout << minint << endl;
        }
        else{
            t3 = *(res.lower_bound(t2));
            if(t2 == t3){
                cout << t2 << endl;;
            }
            else{
                it1 = res.upper_bound(t2);
                it1--;
                t1 = *(it1);
                if((t3-t2) < (t2-t1)){
                    cout << t3 << endl;
                }
                else{
                    cout << t1 << endl;
                }
            }
        }
    }
}