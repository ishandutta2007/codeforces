#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>

using namespace std;

const int maxn = 200005;
const int maxa = maxn * 50;
int n,q;
int p[maxn];
int root[maxn],data[maxa],ls[maxa],rs[maxa],tot_tree;

void build(int &root,int l,int r){
    root = ++tot_tree;
    data[root] = 0;
    if(l == r){
        return;
    }
    int mid = (l + r) / 2;
    build(ls[root],l,mid);
    build(rs[root],mid + 1,r);
}

void pushup(int root){
    data[root] = data[ls[root]] + data[rs[root]];
}

void update(int last,int &root,int l,int r,int p){
    root = ++tot_tree;
    ls[root] = ls[last];
    rs[root] = rs[last];
    data[root] = data[last];
    if(l == r){
        data[root]++;
        return;
    }
    int mid = (l + r) / 2;
    if(p <= mid) update(ls[last],ls[root],l,mid,p);
    else update(rs[last],rs[root],mid + 1,r,p);
    pushup(root);
}

int query(int last,int root,int l,int r,int ql,int qr){
    if(ql > qr) return 0;
    if(ql <= l && r <= qr) return data[root] - data[last];
    int mid = (l + r) / 2;
    int ans = 0;
    if(ql <= mid) ans += query(ls[last],ls[root],l,mid,ql,qr);
    if(qr > mid) ans += query(rs[last],rs[root],mid + 1,r,ql,qr);
    return ans;
}

int main(){
    tot_tree = 0;
    cin >> n >> q;
    for(int i = 1;i <= n;i++){
        scanf("%d",&p[i]);
    }
    build(root[0],1,n);
    for(int i = 1;i <= n;i++){
        update(root[i - 1],root[i],1,n,p[i]);
    }
    for(int i = 1;i <= q;i++){
        int num[9] = {0};
        int l,d,r,u;
        scanf("%d%d%d%d",&l,&d,&r,&u);
        if(l > 1){
            num[0] = query(root[0],root[l - 1],1,n,1,d - 1);
            num[3] = query(root[0],root[l - 1],1,n,d,u);
            num[6] = query(root[0],root[l - 1],1,n,u + 1,n);
        }
        num[1] = query(root[l - 1],root[r],1,n,1,d - 1);
        num[4] = query(root[l - 1],root[r],1,n,d,u);
        num[7] = query(root[l - 1],root[r],1,n,u + 1,n);
        if(r < n){
            num[2] = query(root[r],root[n],1,n,1,d - 1);
            num[5] = query(root[r],root[n],1,n,d,u);
            num[8] = query(root[r],root[n],1,n,u + 1,n);
        }
        long long ans = 0;
        long long sum = 0;
        for(int i = 0;i < 9;i++) sum += num[i];
        ans += 1LL * num[0] * (num[4] + num[5] + num[7] + num[8]);
        ans += 1LL * num[2] * (num[3] + num[4] + num[6] + num[7]);
        ans += 1LL * num[6] * (num[1] + num[2] + num[4] + num[5]);
        ans += 1LL * num[8] * (num[0] + num[1] + num[3] + num[4]);
        ans += 1LL * num[1] * (sum - num[0] - num[1] - num[2]);
        ans += 1LL * num[3] * (sum - num[0] - num[3] - num[6]);
        ans += 1LL * num[5] * (sum - num[2] - num[5] - num[8]);
        ans += 1LL * num[7] * (sum - num[6] - num[7] - num[8]);
        ans += 1LL * num[4] * (sum - num[4]);
        ans += 1LL * num[4] * (num[4] - 1);
        ans /= 2;
        printf("%lld\n",ans);
    }
    return 0;
}