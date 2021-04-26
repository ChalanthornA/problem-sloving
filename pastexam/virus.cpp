#include <iostream>
#include <list>

using namespace std;

list<long long> dna;
list<long long>::iterator it1, it2;

int main(){
    long long n, m, i, tmp, command, virus;
    scanf("%lld %lld", &n, &m);
    for(i = 0; i < n; i++){
        cin >> tmp;
        dna.push_back(tmp);
    }
    it1 = dna.begin();
    for(i = 0; i < m; i++){
        scanf("%lld", &command);
        if(command == 1){
            it1 = dna.begin();
        }
        else if(command == 2){
            it1++;
            if(it1 == dna.end()){
                it1 = dna.begin();
            }
        }
        else if(command == 3){
            scanf("%lld", &virus);
            dna.insert(it1, virus);
        }
        else if(command == 4){
            scanf("%lld", &virus);
            it2 = it1;
            it2++;
            dna.insert(it2, virus);
        }
    }
    for(it1 = dna.begin(); it1 != dna.end(); it1++){
        printf("%lld\n", *it1);
    }
}