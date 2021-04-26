#include <iostream>

using namespace std;

typedef struct cont
{
    int no, score;
}contest;

int check[5];
contest people[5];

int main(){
    int n, i, maxx = -100, tmp, round = 1, res1, j, res2, res3, res4, tmp1 = 0, tmp2 = 0;
    cin >> n;
    for(i = 1; i <= 4; i++){
        maxx = -100;
        for(j = 1; j <= n; j++){
            cin >> tmp;
            if(tmp > maxx){
                people[i].no = j+(n*(i-1));
                people[i].score = tmp;
                maxx = tmp;
            }
        }
    }
    if(people[1].score > people[2].score){
        res3 = people[2].no;
        check[2] = 1;
    }
    else{
        res3 = people[1].no;
        check[1] = 1;
    }
    if(people[3].score > people[4].score){
        res4 = people[4].no;
        check[4] = 1;
    }
    else{
        res4 = people[3].no;
        check[3] = 1;
    }
    for(i = 1; i <= 4; i++){
        if(check[i] == 1){
            continue;
        }
        else{
            if(tmp1 == 0){
                tmp1 = i;
            }
            else{
                tmp2 = i;
            }
        }
    }
    if(people[tmp1].score > people[tmp2].score){
        res1 = people[tmp1].no;
        res2 = people[tmp2].no;
    }
    else{
        res1 = people[tmp2].no;
        res2 = people[tmp1].no;
    }
    printf("%d %d %d %d\n", res1, res2, res3, res4);
}

/*
3
1
2
5
40
25
39
21
29
27
10
20
15
*/