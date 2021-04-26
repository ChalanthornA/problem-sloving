#include <iostream>
#include <math.h>

using namespace std;

double dis(int a, int b, int x, int y){
    return sqrt(pow((y-b), 2) + pow((x-a), 2));
}

int main(){
    double n, a, b, r, i, x, y, res = 0;
    
    cin >> n >> a >> b >> r;
    for(i = 0; i < n; i++){
        cin >> x >> y;
        if(dis(a, b, x, y) <= r){
            res += 1;
        }
    }
    cout << res << endl;
}