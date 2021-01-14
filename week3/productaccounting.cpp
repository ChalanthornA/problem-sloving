#include <iostream>
#include <list>

using namespace std;

list<long>::iterator setit[2000000000],it1;
long setpro[2000000000];

int main(){
    list<long> pro;
    long m,act,i,a,b;

    cin >> m;
    for(i=0;i<m;i++){
        cin >> act;
        if(act == 1){
            cin >> a >> b;
            pro.push_back(b);
            it1 = pro.end();
            it1--;
            setit[a] = it1;
            setpro[a] = 1;
        }
        else if(act == 2){
            cin >> a;
            if(setpro[a] == 1){
                it1 = setit[a];
                cout << *(it1) << endl;
            }
            else{
                cout << 0 << endl;
            }
        }
    }
}