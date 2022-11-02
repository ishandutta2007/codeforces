#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int n;
const int maxn = 5e5 + 5;
pair<int, int> a[maxn];
typedef long long LL;
LL c[2][maxn];

void add(int type, int p, LL v){
    for(int i = p;i < maxn;i += i & -i){
        c[type][i] += v;
    }
}

LL sum(int type, int p){
    LL ret = 0;
    for(int i = p;i > 0;i -= i & -i){
        ret += c[type][i];
    }    
    return ret;
}

const LL mod = 1e9 + 7;

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d", &a[i].first);
        a[i].second = i;
    }
    sort(a + 1, a + 1 + n);
    LL ans = 0;
    for(int i = 1;i <= n;i++){
        int v = a[i].first;
        int p = a[i].second;
        add(0, p, p);
        add(1, p, n - p + 1);
        LL num = sum(0, p) * (n - p + 1);
        //cout << num << endl;
        num += (sum(1, maxn - 1) - sum(1, p)) * p; 
        //num /= 2;
        num %= mod;
        ans = (ans + num * v) % mod;
    }
    cout << ans << endl;
    return 0;
}