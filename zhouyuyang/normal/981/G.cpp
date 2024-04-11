#include<bits/stdc++.h>
#define ll long long
#define mo 998244353
using namespace std;
const int N=525000;
ll atg[N],mtg[N];
int sz[N],s[N];
void pushup(int k){
	s[k]=(s[k*2]+s[k*2+1])%mo;
}
void chg(int k,ll v1,ll v2){
	s[k]=(s[k]*v1+sz[k]*v2)%mo;
	mtg[k]=mtg[k]*v1%mo;
	atg[k]=(atg[k]*v1+v2)%mo;
}
void pushdown(int k){
	if (atg[k]==0&&mtg[k]==1) return;
	chg(k*2,mtg[k],atg[k]);
	chg(k*2+1,mtg[k],atg[k]);
	atg[k]=0; mtg[k]=1;
}
void build(int k,int l,int r){
	mtg[k]=1; sz[k]=r-l+1;
	if (l==r) return;
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
}
void change(int k,int l,int r,int x,int y,int v1,int v2){
	if (x>y) return;
	if (x==l&&r==y){
		chg(k,v1,v2);
		return;
	}
	pushdown(k);
	int mid=(l+r)/2;
	if (y<=mid) change(k*2,l,mid,x,y,v1,v2);
	else if (x>mid) change(k*2+1,mid+1,r,x,y,v1,v2);
	else change(k*2,l,mid,x,mid,v1,v2),
		 change(k*2+1,mid+1,r,mid+1,y,v1,v2);
	pushup(k);
}
int ask(int k,int l,int r,int x,int y){
	if (y<l||x>r) return 0;
	if (x==l&&y==r) return s[k];
	pushdown(k);
	int mid=(l+r)/2;
	if (y<=mid) return ask(k*2,l,mid,x,y);
	if (x>mid) return ask(k*2+1,mid+1,r,x,y);
	return (ask(k*2,l,mid,x,mid)+ask(k*2+1,mid+1,r,mid+1,y))%mo;
}
#define pa pair<int,int>
#define se second
#define fi first
int n,q;
set<pa> emp[N];
void split(int x,int l){
	set<pa>::iterator it;
	it=emp[x].lower_bound(pa(l,l));
	if (it==emp[x].begin()) return;
	it--; pa p=*it;
	if (p.se>=l){
		emp[x].erase(p);
		emp[x].insert(pa(p.fi,l-1));
		emp[x].insert(pa(l,p.se));
	}
}
int main(){
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++)
		emp[i].insert(pa(1,n));
	build(1,1,n);
	while (q--){
		int tp,l,r,x;
		scanf("%d%d%d",&tp,&l,&r);
		if (tp==1){
			scanf("%d",&x);
			change(1,1,n,l,r,2,0);
			split(x,l); split(x,r+1);
			for (;;){
				set<pa >::iterator it;
				it=emp[x].lower_bound(pa(l,l));
				if (it==emp[x].end()||it->fi>r) break;
				change(1,1,n,it->fi,it->se,(mo+1)/2,1);
				emp[x].erase(it);
			}
		}
		else
			printf("%d\n",ask(1,1,n,l,r));
	}
}