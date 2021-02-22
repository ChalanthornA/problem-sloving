#include <iostream>
#include <queue>
 
using namespace std;
 
struct thing
{
    int a;
    int b;
    bool operator<(const thing& rhs) const
    {
        return a < rhs.a;
    }
};

// typedef struct A{
//     int val,idx,ti;
//     bool operator < (const A& o)const{
//         if(val != o.val){
//             return val < o.val;
//         }
//         else if(ti != o.ti){
//             return ti < o.ti;
//         }
//     }
// }A;

int main(){
    priority_queue<thing> q;
    thing stuff = {42, 1},stuff2 = {44,2},ostuff;
    q.push(stuff);
    q.push(stuff2);
    stuff.a = 4242;
    stuff.b = 3;
    q.push(stuff);
    ostuff = q.top();
    q.pop();
    cout << ostuff.a << " " << ostuff.b << endl
}