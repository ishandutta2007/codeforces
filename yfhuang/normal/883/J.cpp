#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 1e5 + 5;

int n,m;

int a[maxn],b[maxn],p[maxn];
int t[maxn];
pair<int,int> s[maxn]; int top;

typedef long long LL;

LL sum[maxn];
LL c[maxn];

LL minv[maxn << 2];
LL lazy[maxn << 2];
#define lson o * 2,l,mid
#define rson o * 2 + 1,mid + 1,r

void pushup(int o){
	minv[o] = min(minv[o * 2],minv[o * 2 + 1]);
}
void build(int o,int l,int r){
    if(l == r){
        minv[o] = sum[l];
       	return;
    }
	int mid = (l + r) / 2;
	build(lson);
	build(rson);
	pushup(o);
}

void pushdown(int o){
	if(lazy[o]){
		lazy[o * 2] += lazy[o];
		lazy[o * 2 + 1] += lazy[o];
		minv[o * 2] += lazy[o];
		minv[o * 2 + 1] += lazy[o];
		lazy[o] = 0;
	}
}

void update(int o,int l,int r,int ql,int qr,int d){
	if(ql <= l && r <= qr){
		minv[o] += d;
		lazy[o] += d;
		return;
	}
	int mid = (l + r) / 2;
	pushdown(o);
	if(ql <= mid)update(lson,ql,qr,d);
	if(qr > mid)update(rson,ql,qr,d);
	pushup(o);
}

LL query(int o,int l,int r,int ql,int qr){
	if(ql <= l && r <= qr){
		return minv[o];
	}
	int mid = (l + r) / 2;
	pushdown(o);
	LL ret = 1e18;
	if(ql <= mid) ret = min(ret,query(lson,ql,qr));
	if(qr > mid) ret = min(ret,query(rson,ql,qr));
	return ret;
}

pair<int,int> d[maxn];
int main(){
	cin >> n >> m;
	sum[0] = 0;
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		sum[i] = sum[i - 1] + a[i];
	}
	top = 0;
	for(int i = 1;i <= n;i++){
		while(top > 0 && s[top].first <= a[i]) top--;
		s[++top] = make_pair(a[i],i);
	}
	reverse(s + 1,s + 1 + top);
	for(int i = 1;i <= m;i++){
		scanf("%d",&b[i]);
		int id = lower_bound(s + 1,s + 1 + top,make_pair(b[i],0)) - s;
		if(id <= top)t[i] = s[id].second;
		else t[i] = n + 1;
	}
	for(int i = 1;i <= m;i++){
		scanf("%d",&p[i]);
		d[i] = make_pair(p[i],t[i]);
	}
    sort(d + 1,d + 1 + m);
	int ans = 0;
	build(1,1,n);
	for(int i = 1;i <= m;i++){
        if(d[i].second > n) continue;
        if(query(1,1,n,d[i].second,n) >= d[i].first){
			ans++;
			update(1,1,n,d[i].second,n,-d[i].first);
		}
	}
	cout << ans << endl;
	return 0;
}