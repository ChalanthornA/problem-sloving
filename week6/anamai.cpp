#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef struct for_graph{
    int vertex;
}for_graph;

typedef struct in_heap{
    int vertex;
    double dist;
    bool operator < (const in_heap & o)const{
        if(dist!= o.dist)    return vertex > o.vertex;
        else    return dist > o.dist;
    }
}in_heap;

int visited[100100], anamai[100100][2];
double short_dist[100100];

priority_queue<in_heap> heap;
vector<for_graph> graph[100100];

int main(){
    int n, m, i, a, b, k, h, count = 0, j;
    double val, distance;
    for_graph temp;
    in_heap temp2,temp3;

    cin >> n >> m >> k >> h;
    for(i = 1; i <= k; i++){
        cin >> anamai[i][0];
    }
    for(i = 1; i <= k; i++){
        cin >> anamai[i][1];
    }
    for(i = 1; i <= n; i++){
        short_dist[i] = 1<<30;
    }
    for(i = 0; i < m; i++){
        cin >> a >> b ;
        temp.vertex = b;
        graph[a].push_back(temp);
        temp.vertex = a;
        graph[b].push_back(temp);
    }
    for(j = 1; j <= k; j++){
        if(anamai[j][1] == 0){
            val = 1;
        } 
        else{
            val = 0.5;
        }
        temp2.vertex = anamai[j][0]; //เพิ่มจุดเริ่ม
        temp2.dist = 0;
        heap.push(temp2);
        short_dist[anamai[j][0]] = 0;
        while(!heap.empty()){
            temp3 = heap.top();
            // cout << "this" << temp3.vertex << endl;
            heap.pop();
            visited[temp3.vertex] = 1;
            for(i = 0; i < graph[temp3.vertex].size(); i++){
                distance = temp3.dist;
                temp = graph[temp3.vertex][i];
                if(visited[temp.vertex]){
                    continue;
                }
                // cout << temp.vertex<< endl;
                // cout << distance << " ";
                distance += val;
                // cout << distance << endl;
                if(distance <= short_dist[temp.vertex]){
                    short_dist[temp.vertex] = distance;
                    temp2.dist = distance;
                    // cout << temp2.dist << "hihi" << endl;
                    temp2.vertex = temp.vertex;
                    heap.push(temp2);
                }
            }
            // for(i = 1; i <= n; i++){
            //     cout << short_dist[i] << " ";
            // }
            // cout << endl;
        }
        for(i = 1; i <= n; i++){
            visited[i] = 0;
        }
    }
    for(i = 1; i <= n; i++){
        if(short_dist[i] <= h){
            count += 1;
        }
    }
    cout << count << endl;
}

/*
7 7 2 1
4 2 
0 1 
1 2 
7 1 
1 3 
3 4 
4 5 
6 5 
3 6

7 6 1 2 
2 
0
1 2 
2 3 
3 4 
4 5 
5 6 
6 7


10 9 2 2 
9 1
1 0
1 2
2 3
3 4 
5 4 
5 6 
6 7 
7 8 
9 8 
9 10
*/