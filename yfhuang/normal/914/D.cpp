#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int n;

const int maxn = 5e5 + 5;

int a[maxn];
int g[maxn << 2];

int gcd(int a,int b){
	if(b == 0) return a;
	return gcd(b,a % b);
}

void pushup(int o){
	g[o] = gcd(g[o << 1],g[(o << 1) | 1]);
}

#define lson o << 1,l,mid
#define rson (o << 1)|1,mid + 1,r

void build(int o,int l,int r){
	if(l == r){
		g[o] = a[l];	
		return;
	}
	int mid = (l + r) / 2;
	build(lson);
	build(rson);
	pushup(o);
}

int query(int o,int l,int r,int ql,int qr){
	if(ql <= l && r <= qr){
		return g[o];
	}
	int mid = (l + r) / 2;
	if(qr <= mid) return query(lson,ql,qr);
	if(ql > mid) return query(rson,ql,qr);
	return gcd(query(lson,ql,qr),query(rson,ql,qr));
}

void update(int o,int l,int r,int p,int v){
	if(l == r){
		g[o] = v;
		return;
	}
	int mid = (l + r) / 2;
	if(p <= mid) update(lson,p,v);
	else update(rson,p,v);
	pushup(o);
}

int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		scanf("%d",a + i);
	}
	build(1,1,n);
	int q;
	scanf("%d",&q);
	for(int i = 1;i <= q;i++){
		int type;
		scanf("%d",&type);
		if(type == 1){
			int l,r,x;
			scanf("%d%d%d",&l,&r,&x);
			if(query(1,1,n,l,r) % x == 0){
				printf("YES\n");
				continue;
			}
			int L = l,R = r + 1;
			while(L < R){
				int mid = (L + R) / 2;
				if(query(1,1,n,l,mid) % x == 0){
					L = mid + 1;
				}else R = mid;
			}
			if(R >= r) {printf("YES\n");continue;}
			else{
				if(query(1,1,n,R + 1,r) % x == 0){
					printf("YES\n");continue;
				}
			}
			printf("NO\n");
		}else{
			int p,v;
			scanf("%d%d",&p,&v);
			update(1,1,n,p,v);
		}
	}
	return 0;
}