#include <stdio.h>

int min(int a, int b){
    if(a<b){
        return a;
    }
    return b;
}

int main(){
    int hw,hb,bw,bb,x,y,res = 0,res2,i,tmp1=0,tmp2=0,hww,hbb,bww,bbb;

    scanf("%d %d %d %d",&hw,&hb,&bw,&bb);
    scanf("%d %d",&x,&y);
    for(i = 0; i<x; i++){
        if(min(hw,bw)==0 && min(hb,bb) == 0){
            break;
        }
        if(i == x-2){
            x = x-res;
            break;
            // res2 = res;
            // hww = hw;
            // hbb = hb;
            // bww = bw;
            // bbb = bb;
            // for(i = 0;i<y;i++){
            //     if(min(hww,bbb) == 0 && min(hbb,bww) == 0){
            //         break;
            //     }
            //     if(min(hbb,bww)>min(hww,bbb)){
            //         hbb -= 1;
            //         bww -= 1;
            //         res2 += 1;
            //     }
            //     else{
            //         hww -= 1;
            //         bbb -= 1;
            //         res2 += 1;
            //     }
            // }
        }
        if(min(hw,bw) > min(hb,bb)){
            hw -= 1;
            bw -= 1;
            res+=1;
        }
        else{
            hb -= 1;
            bb -= 1;
            res += 1;
        }
    }
    for(i=0;i<y;i++){
        if(min(hw,bb) == 0 && min(hb,bw) == 0){
            break;
        }
        if(min(hb,bw)>min(hw,bb)){
            hb -= 1;
            bw -= 1;
            res += 1;
        }
        else{
            hw -= 1;
            bb -= 1;
            res += 1;
        }
    }
    // if(res > res2){
    //     printf("%d\n",res);
    // }
    // else{
    //     printf("%d\n",res2);
    // }
    for(i = 0; i<x; i++){
        if(min(hw,bw)==0 && min(hb,bb) == 0){
            break;
        }
        if(min(hw,bw) > min(hb,bb)){
            hw -= 1;
            bw -= 1;
            res+=1;
        }
        else{
            hb -= 1;
            bb -= 1;
            res += 1;
        }
    }
    printf("%d\n",res);
}