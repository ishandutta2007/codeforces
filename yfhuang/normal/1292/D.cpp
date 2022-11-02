#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 5005;

int n;
int cnt[maxn];
int divisor[maxn][maxn];
int bigdivisor[maxn];
int freq[maxn];

void preprocess(){
    for(int i = 1;i < maxn;i++){
        for(int j = 2;j < maxn;j++){
            divisor[i][j] = divisor[i - 1][j];
        }
        int tmp = i;
        for(int j = 2;j < maxn;j++){
            while(tmp % j == 0){
                tmp /= j;
                divisor[i][j]++;
            }
        }
    }
}

void solve(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        int val;
        scanf("%d", &val);
        cnt[val]++;
    }
    preprocess();
    long long ans = 0;
    for(int i = 0;i < maxn;i++){
        for(int j = 0;j < maxn;j++){
            if(divisor[i][j]) bigdivisor[i] = j;
            ans += 1LL * divisor[i][j] * cnt[i];
        }
        if(!bigdivisor[i])
            bigdivisor[i] = 1;
    }
    while(true){
        memset(freq, 0, sizeof(freq));
        for(int i = 0;i < maxn;i++){
            freq[bigdivisor[i]] += cnt[i];
        }
        int mx = 1;
        for(int i = 2;i < maxn;i++){
            if(freq[i] > freq[mx]){
                mx = i;
            }
        }
        if(mx == 1) break;
        int num = freq[mx];
        if(2 * num <= n) break;
        ans -= num;
        ans += (n - num);
        for(int i = 0;i < maxn;i++){
            if(bigdivisor[i] != mx) bigdivisor[i] = 1;
            if(bigdivisor[i] == 1) continue;
            divisor[i][mx] -= 1; 
            while(bigdivisor[i] > 1 and divisor[i][bigdivisor[i]] == 0) bigdivisor[i]--;
        }
    }
    cout << ans << endl;
}



int main(){
    solve();
    return 0;
}