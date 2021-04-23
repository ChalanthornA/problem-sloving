#include <iostream>
#include <queue>

using namespace std;

typedef struct in_heap{
    int vs, ve, weight;
    bool operator < (const in_heap & o)const{
        if(weight!= o.weight)    return weight > o.weight;
        else    return vs > o.vs;
    }
}in_heap;

priority_queue<in_heap> graph;
int parent[100100];

int findp(int x){
    if(parent[x] == x)
        return x;
    return parent[x] = findp(parent[x]);
}

int main(){
    int n, m, a, b, w, res = 0, i, s;
    in_heap tmp;

    cin >> n >> m;
    for(i = 1; i <= n; i++){
        parent[i] = i;
    }
    for(i = 0; i < m; i++){
        cin >> a >> b >> w >> s;
        if(s == 0){
            tmp.weight = w;
        }
        else{
            tmp.weight = 0;
        }
        tmp.ve = b;
        tmp.vs = a;
        graph.push(tmp);
    }
    while(!graph.empty()){
        tmp = graph.top();
        graph.pop();
        if(findp(tmp.vs) != findp(tmp.ve)){
            res += tmp.weight;
            parent[findp(tmp.vs)] = findp(tmp.ve);
        }
    }
    cout << res << endl;
}