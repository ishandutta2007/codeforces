#include <bits/stdc++.h>
using namespace std;

int getw(int x){
    int ans = 0;
    while (x){
        ans += x & 1;
        x >>= 1;
    }
    return ans;
}

long long power(int x){
    long long ans = 1;
    while (x--){
        ans *= 2;
    }
    return ans;
}

int main(){
    int T;
    scanf("%d",&T);
    while (T--){
        int n;
        scanf("%d",&n);
        cout << power(getw(n)) << endl;
    }
    return 0;
}