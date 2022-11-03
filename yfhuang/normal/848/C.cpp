#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
using namespace std;

const int maxn = 100000 + 5;

int a[maxn];set<int> s[maxn];
int n,m;
int rt[maxn];
long long sz[maxn * 100];
int tot;
int ch[maxn * 100][2];

#define lson ch[rt][0]
#define rson ch[rt][1]

set<int> ::iterator it;

void add(int &rt,int l,int r,int p,int x){
	if(!rt) rt = ++tot;
	if(l == r){
		sz[rt] += x;
		return;
	}
	int mid = (l + r) / 2;
	if(p <= mid) add(lson,l,mid,p,x);
	else add(rson,mid + 1,r,p,x);
	sz[rt] = sz[lson] + sz[rson];
}

long long sum(int rt,int l,int r,int p){
	if(!rt) return 0;
	if(r < p) return 0;
	if(l >= p) return sz[rt];
	int mid = (l + r) / 2;
	return sum(lson,l,mid,p) + sum(rson,mid + 1,r,p);
}

void add(int r,int l,int val){
	if(r > n) return;
	if(l == 0) return;
	for(int i = r;i <= n;i += i & -i){
		add(rt[i],1,n,l,val);
	}
}

long long sum(int l,int r){
	long long ret = 0;
	for(int i = r;i > 0;i -= i & -i){
		ret += sum(rt[i],1,n,l);
	}
	return ret;
}

int main(){
	while(cin >> n >> m){
		for(int i = 1;i <= n;i++){
			scanf("%d",a + i);
		}
		for(int i = 1;i <= n;i++){
			s[i].insert(n + 1);
		}
		for(int i = n;i >= 1;i--){
			add(*s[a[i]].begin(),i,*s[a[i]].begin() - i);
			s[a[i]].insert(i);
		}
		for(int i = 1;i <= n;i++){
			s[i].insert(0);
		}
		for(int i = 1;i <= m;i++){
			int type;
			scanf("%d",&type);
			if(type == 1){
				int p,x;
				scanf("%d%d",&p,&x);
				int u,v;
				it = s[a[p]].lower_bound(p);
				it--;u = *it;
				it++,it++;v = *it;
				add(v,p,p - v);add(p,u,u - p);
				add(v,u,v - u);
				s[a[p]].erase(p);
				a[p] = x;
				it = s[a[p]].lower_bound(p);
				v = *it,it--,u = *it;
				add(p,u,p - u);add(v,p,v - p);
				add(v,u,u - v);
				s[a[p]].insert(p);
			}else{
				int l,r;
				scanf("%d%d",&l,&r);
				printf("%lld\n",sum(l,r));
			}
		}
	}	
	return 0;
}