#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cassert>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

int n, m;

struct line{
    int x;
    int l, r;
    int len;
    line(int _x=0, int _l=0, int _r=0, int _len=0):x(_x), l(_l), r(_r), len(_len){}
};

vector<line> v, a, b;

bool cmp1(line l1, line l2){
    return l1.x < l2.x;
}

bool cmp3(line l1, line l2){
    return l1.len < l2.len;
}

const int maxn = 1e6 + 5;

int c[maxn];

void add(int p, int v){
    for(int i = p;i < maxn;i += i & -i){
        c[i] += v;
    }
}

int sum(int p){
    int ret = 0;
    for(int i = p;i > 0;i -= i & -i){
        ret += c[i];
    }
    return ret;
}

void add(int l, int r, int v){
    add(l, v);
    add(r + 1, -v); 
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    long long ans = 1;
    for(int i = 1;i <= n;i++){
        int x, l, r;
        cin >> x >> l >> r;
        v.push_back(line(x, l, r, r - l));
        if(l == 0 and r == 1e6)
            ans++;
    }
    for(int i = 1;i <= m;i++){
        int x, l, r;
        cin >> x >> l >> r;
        if(l == 0 and r == 1e6)
            ans++;
        if(l == 0 and r < 1e6){
            a.push_back(line(x, l, r, r - l));
        }else{
            b.push_back(line(x, l, r, r - l));
        }
    }
    sort(v.begin(), v.end(), cmp1);
    memset(c, 0, sizeof(c));
    int now = 0;
    sort(a.begin(), a.end(), cmp3);
    for(auto l : a){
        while(now < n and v[now].x <= l.r){
            add(v[now].l + 1, v[now].r + 1, 1);
            now++;
        }
        ans += sum(l.x + 1);
    }
    memset(c, 0, sizeof(c));
    sort(b.begin(), b.end(), cmp3);
    now = n - 1;
    for(auto l : b){
        while(now >= 0 and v[now].x >= l.l){
            add(v[now].l + 1, v[now].r + 1, 1);
            now--;
        }
        ans += sum(l.x + 1);
    }
    cout << ans << endl;
    return 0;
}