#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn = 2005;

long long dp[maxn][maxn];

int n,k,p;
int a[maxn];
int b[maxn];

bool check(int x){
    //cout << x << endl;
    int j = 1;
    for(int i = 1;i <= n;i++){
        if(j > k) return false;
        while(abs(a[i] - b[j]) + abs(b[j] - p) > x){
            j++;
            if(j > k) return false;
        }
        j++;
    }
    return true;
}
int main(){
    cin >> n >> k >> p;
    for(int i = 1;i <= n;i++){
        scanf("%d",a + i);
    }
    sort(a + 1,a + 1 + n);
    for(int i = 1;i <= k;i++){
        scanf("%d",b + i);
    }
    sort(b + 1,b + 1 + k);
    long long l = 0,r = 2e9;
    while(l < r){
        long mid = (l + r) / 2;
        if(check((int)mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
    return 0;
}