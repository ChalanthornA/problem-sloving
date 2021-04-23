#include <iostream>
#include <queue>

using namespace std;

typedef struct work{
    long start,end;
    bool operator < (const work & o)const{
        if(end!= o.end)    return end > o.end;
        else    return start > o.start;
    }
}work;

priority_queue<work> office;

int main(){
    long n,i,s,t,res=0,rs = 0,rt = 0;
    work it1,it2;

    cin >> n;
    for(i = 0; i<n; i++){
        work temp;
        cin >> s >> t;
        temp.start = s;
        temp.end = t;
        office.push(temp);
    }
    for(i = 0; i < n; i++){
        it1 = office.top();
        office.pop();
        s = it1.start;
        t = it1.end;
        if(s >= rt){
            rs = s;
            rt = t;
            res += 1;
        }
    }
    cout << res << endl;
}