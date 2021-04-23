#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef struct for_graph{
    int vertex;
    int weight;
}for_graph;

typedef struct in_heap{
    int vertex,dist;
    bool operator < (const in_heap & o)const{
        if(dist!= o.dist)    return dist > o.dist;
        else    return vertex > o.vertex;
    }
}in_heap;

int short_dist[100100], visited[100100],people[100100];
priority_queue<in_heap> heap;
vector<for_graph> graph[100100];

int main(){
    int n, m, i, a, b, w, distance, l, res = 0;
    for_graph temp;
    in_heap temp2,temp3;

    cin >> n >> m >> l;
    for(i = 1; i <= n; i++){
        cin >> people[i];
        short_dist[i] = 1<<30;
    }
    for(i = 0; i < m; i++){
        cin >> a >> b >> w;
        temp.vertex = b;
        temp.weight = w;
        graph[a].push_back(temp);
        temp.vertex = a;
        graph[b].push_back(temp);
    }
    temp2.vertex = 1; //เพิ่มจุดเริ่ม
    temp2.dist = 0;
    heap.push(temp2);
    short_dist[1] = 0;
    while(!heap.empty()){
        temp3 = heap.top();
        heap.pop();
        visited[temp3.vertex] = 1;
        for(i = 0; i < graph[temp3.vertex].size(); i++){
            distance = temp3.dist;
            temp = graph[temp3.vertex][i];
            if(visited[temp.vertex]){
                continue;
            }
            distance += temp.weight;
            if(distance <= short_dist[temp.vertex]){
                short_dist[temp.vertex] = distance;
                temp2.dist = distance;
                temp2.vertex = temp.vertex;
                heap.push(temp2);
            }
        }
    }
    for(i = 0; i <= n; i++){
        if(people[i] * short_dist[i] < l * short_dist[i]){
            res += people[i] * short_dist[i];
        }
        else{
            res += l * short_dist[i];
        }
    }
    cout << res << endl;
}