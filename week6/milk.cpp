#include <iostream>

using namespace std;

int parent[100100];
// list<int> milk[100100]

int findp(int x){
    if(parent[x] == x)
        return x;
    return parent[x] = findp(parent[x]);
}

int main(){
    int n, q, i, x, y;
    char z;

    cin >> n >> q;
    for(i = 1; i <= n; i++){
        parent[i] = i;
    }
    for(i = 0; i < q; i++){
        cin >> z >> x >> y;
        if(z == 'c'){
            parent[findp(x)] = findp(y);
        }
        else if(z == 'q'){
            if(findp(x) == findp(y)){
                cout << "yes" << endl;
            }
            else{
                cout << "no" << endl;
            }
        }
    }
}