#include <iostream>
#include <map>

using namespace std;

//long long ans[100100];

long long setproduct[100100];

int main(){
    map<long long,long long> pro;
    map<long long, long long>::iterator it1;
    long long m,act,i,a,b,tmp,tmp2;

    cin >> m;
    for(i=0;i<m;i++){
        cin >> act;
        if(act == 1){
            cin >> a >> b;
            if(pro[a] <= 0)
              pro[a] = i+1;
            setproduct[pro[a]] += b;
        }
        else if(act == 2){
            cin >> a;
            tmp = pro[a];
            if(tmp == 0){
                cout << 0 << endl;
            }
            else{
                cout << setproduct[tmp] << endl;
            }
        }
        else if(act == 3){
            cin >> a >> b;
            tmp = pro[a];
            tmp2 = setproduct[tmp];
            if(tmp2 < b){
                cout << tmp2 << endl;
                setproduct[tmp] = 0;
            }
            else{
                tmp2 -= b;
                setproduct[tmp] = tmp2;
                cout << b << endl;
            }
        }
    }
}