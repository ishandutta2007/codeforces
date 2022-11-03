#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <bitset>
#include <vector>
using namespace std;
int N,S;
const int maxn = 1e5 + 5;

struct pizza{
    int s,a,b;
    bool operator < (const pizza & rhs) const{
        return a - b > rhs.a - rhs.b;
    }
}p[maxn];

long long pre[maxn],suf[maxn];
long long pre1[maxn],suf1[maxn];

int main(){
    cin >> N >> S;
    long long sum = 0;
    for(int i = 1;i <= N;i++){
        scanf("%d%d%d",&p[i].s,&p[i].a,&p[i].b);
        sum += p[i].s;
    }
    long long m = (sum + S - 1) / S;
    sort(p + 1,p + 1 + N);
    for(int i = 1;i <= N;i++){
        pre[i] = pre[i - 1] + p[i].s;
        pre1[i] = pre1[i - 1] + p[i].s * 1LL * p[i].a;
    }
    for(int i = N;i > 0;i--){
        suf[i] = suf[i + 1] + p[i].s;
        suf1[i] = suf1[i + 1] + p[i].s * 1LL * p[i].b;
    }
    long long ans = 0;
    for(int i = 1;i <= N;i++){
        long long k1 = (pre[i - 1] + S - 1) / S;
        long long k2 = (suf[i + 1] + S - 1) / S;
        long long k3 = k1 * S - pre[i - 1];
        long long k4 = k2 * S - suf[i + 1];
        long long k5 = (max(0LL,p[i].s - k3 - k4) + S - 1) / S;
        if(k5 + k1 + k2 > m) continue;
        long long k6 = k5 * S + k3;
        long long k7 = k5 * S + k4;
        long long tmp = max(min(1LL * p[i].s,k6) * p[i].a + max(0LL,p[i].s - k6) * p[i].b,min(1LL * p[i].s,k7) * p[i].b + max(0LL,p[i].s - k7) * p[i].a);
        ans = max(ans,pre1[i - 1] + tmp + suf1[i + 1]);
    }
    cout << ans << endl;
    return 0;
}