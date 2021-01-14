#include <iostream>
#include <list>
using namespace std;

list<long>::iterator l[1000100],it1,it2,j;
long color[10001000];

int main(){
    list<long> zuma;
    long m,n,i,tmp1,tmp2,number;

    cin >> n >> m;
    for(i=0;i<n;i++){
        cin >> tmp1;
        zuma.push_back(i+1);
        it1 = zuma.end();
        it1--;
        l[i+1] = it1;
    }
    number = n+1;
    for(i=0;i<m;i++){
        cin >> tmp1 >> tmp2;
        it1 = l[tmp2];
        it2 = zuma.insert(++it1,number+i);
        l[number+i] = it2;
    }
    for(j = zuma.begin();j != zuma.end();j++){
        cout << *(j) << endl;
    }
}