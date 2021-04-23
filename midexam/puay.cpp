#include <iostream>

using namespace std;

int person[1010];

int main(){
    int n,i,l,j,a,b,k;

    cin >> n;
    for(i = 1; i <= n; i++){
        cin >> l;
        for(j = 0; j < l;j++){
            cin >> a >> b;
            person[i] += a;
            for(k = 1; k < b; k++){
                person[i+k] += a;
            }
        }
    }
    for(i = 1; i <= n; i++){
        cout << person[i] << endl;
    }
}