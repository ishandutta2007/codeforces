#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int n, h;
const int maxn = 1e3 + 5;

int a[maxn];
int b[maxn];
bool check(int k){
    for(int i = 1;i <= k;i++){
        b[i] = a[i];
    } 
    sort(b + 1, b + 1 + k);
    long long total = 0;
    if(k & 1){
        for(int i = 1;i <= k;i += 2){
            total += b[i];
        }
    }else{
        for(int i = 2;i <= k;i += 2){
            total += b[i];
        }
    }
    return total <= h;
}
int main(){
    cin >> n >> h;
    for(int i = 1;i <= n;i++){
        scanf("%d", &a[i]);
    }
    int l = 0, r = n;
    while(l < r){
        int mid = (l + r + 1) / 2;
        if(check(mid)){
            l = mid;
        }else{
            r = mid - 1;
        }
    }
    cout << l << endl;
    return 0;
}