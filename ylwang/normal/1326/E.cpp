#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define QWQ cout<<"QwQ"<<endl;
#define ll long long
#include <vector>
#include <queue>
#include <stack>
#include <map>
#define ls now<<1
#define rs now<<1|1
using namespace std;
const int N=301010;
const int qwq=1203030;
const int inf=0x3f3f3f3f;

int n;
int ans;
int a[N],wei[N];
int tree[qwq],tag[qwq];

inline int read() {
    int sum = 0, f = 1; char c = getchar();
    while(c<'0' || c>'9') { if(c=='-') f = -1; c = getchar(); }
    while(c>='0'&&c<='9') { sum = sum * 10 + c - '0'; c = getchar(); }
    return sum * f;
}

inline void pushdown(int now) {
    if(tag[now]==0) return ;
    tag[ls] += tag[now]; tag[rs] += tag[now];
    tree[ls] += tag[now]; tree[rs] += tag[now];
    tag[now] = 0;
}

void insert(int now,int l,int r,int x,int y,int g) {
    if(x<=l && r<=y) { tree[now] += g; tag[now] += g; return ; }
    pushdown(now);
    int mid = l+r >> 1;
    if(x<=mid) insert(ls, l, mid, x, y, g);
    if(y>mid)  insert(rs, mid+1, r, x, y, g);
    tree[now] = max(tree[ls],tree[rs]);
}

int main() {
    int x;
    n = read();
    for(int i=1;i<=n;i++) a[i] = read(), wei[ a[i] ] = i;
    ans = n; cout<<ans<<" ";
    insert(1, 1, n, 1, wei[n], 1);
    for(int i=1;i<n;i++) {
        x = read();
        insert(1, 1, n, 1, x, -1);
        while(tree[1]<=0) {
            ans--;
            insert(1, 1, n, 1, wei[ans], 1);
        }
        cout<<ans<<" ";
    }
    return 0;
}