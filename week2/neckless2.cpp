#include <iostream>
#include <list>

using namespace std;

list<long> l[300001];
list<long>::iterator it1,it2,parent[300001],childe[300001];

int main(){
    long n,i,x,y,tmp,tmp1,tmp2;

    cin >> n;
    for(i = 1;i <= n; i++){
        l[i].push_back(i);

    }
    for(i = 1;i<n;i++){
        cin >> x >> y;
        if(l[y].size() != 0){
            it1 = l[y].begin();
            it1++;
            l[y].splice(it1,l[x]);
            parent[x] = l[y].begin();
            it1 = l[y].begin();
            it1++;
            childe[x] =  it1;
            tmp = y;
        }
        else{
            it1 = parent[y];
            it2 = childe[y];
            tmp1 = *(it1);
            it2++;
            l[tmp1].splice(it2,l[x]);
            parent[x] = parent[y];
            it1 = childe[y];
            it1++;
            childe[x] =  it1;
            tmp = tmp1;
        }
    }
    for(it1 = l[tmp].begin(); it1!=l[tmp].end();it1++){
        cout << *(it1) << " ";
    }
    cout << "\n";
}