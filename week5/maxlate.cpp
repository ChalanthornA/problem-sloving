#include <iostream>
#include <queue>

using namespace std;

typedef struct work{
    long long deadline,time_finish;
    bool operator < (const work & o)const{
        if(deadline != o.deadline)    return deadline > o.deadline;
        else    return time_finish > o.time_finish;
    }
}work;

priority_queue<work> office;

int main(){
    long long n, d, c, res = 0, i, dl, day = 0, time, tmp;
    work it1;
    cin >> n;
    for(i = 0; i < n; i++){
        work temp;
        cin >> d >> c;
        temp.deadline = d;
        temp.time_finish = c;
        office.push(temp);
    }
    while(!office.empty()){
        it1 = office.top();
        office.pop();
        dl = it1.deadline;
        time = it1.time_finish;
        // cout << dl << endl;
        day += time;
        if(day - dl > 10){
            tmp = 1000*(day - dl - 10);
            if(tmp > res){
                res = tmp;
            }
        }
    }
    cout << res << endl;
    return 0;
}