#include <iostream>
#include <list>

using namespace std;

list<long> l[301000];
list<long>::iterator it1,it2;

long parent[301000];;

int findp(long x){
    if(parent[x] == x)
        return x;
    return parent[x] = findp(parent[x]);
}

int main(){
    long n,i,x,y,tmp,tmp1,tmp2;

    cin >> n;
    for(i = 1;i <= n; i++){
        l[i].push_back(i);
        parent[i] = i;
    }
    for(i = 1;i<n;i++){
        cin >> x >> y;
        if(l[y].size() != 0){
            it1 = l[y].begin();
            it1++;
            l[y].splice(it1,l[x]);
            parent[x] = findp(y);
        }
        else{
            tmp1 = findp(y);
            for(it2 = l[tmp1].begin();it2 != l[tmp1].end();it2++){
                if(*(it2) == y){
                    break;
                }
            }
            it2++;
            l[tmp1].splice(it2,l[x]);
            parent[x] = findp(y);
            // it1 = childe[y];
            // it1++;
            // childe[x] =  it1;
            tmp = tmp1;
        }
    }
    for(it1 = l[tmp].begin(); it1!=l[tmp].end();it1++){
        cout << *(it1) << " ";
    }
    cout << "\n";
}