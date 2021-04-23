#include <iostream>

using namespace std;

long long temp[100100], arr[100100];

long long merge(long long arr[], long long temp[], long long left, long long mid, long long right){
    long long inver = 0;
    long long i, j, k;
    i = left;
    j = mid;
    k = left;

    while((i <= mid - 1) && (j <= right)){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
            inver += (mid - i);
        }
    }
    while(i <= mid - 1){
        temp[k++] = arr[i++];
    }
    while (j <= right){
        temp[k++] = arr[j++];
    }
    for (i = left; i <= right; i++){
        arr[i] = temp[i];
    }
    return inver;
}


long long _mergeSort(long long arr[], long long temp[], long long left, long long right){
    long long mid, inver = 0;
    if(right > left){
        mid = (right+left)/2;
        inver += _mergeSort(arr, temp, left, mid);
        inver += _mergeSort(arr, temp, mid+1, right);
        inver += merge(arr, temp, left, mid+1, right);
    }
    return inver;
}


int main(){
    long long n, i, tmp, res;
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> tmp;
        arr[i] = tmp;
    }
    res = _mergeSort(arr, temp, 0, n-1);
    cout << res << endl;
}