#include<bits/stdc++.h>
using namespace std;

const int maxq = 300010,maxn = 1000010;
int t[maxq],d[maxq];
long long int val[maxn<<2];
long long int BIT[maxn];
void add(int x,int d){
	for(int i=x;i<=1000000;i+=i&-i)
		BIT[i]+=d;
}
long long int ask(int x){
	long long int res = 0;
	for(int i=x;i;i-=i&-i)
		res+=BIT[i];
	return res;
}
#define ls idx<<1
#define rs idx<<1|1
void build(int idx,int l,int r){
	if(l==r){
		val[idx]=l;
		return;
	}
	int mid = (l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	val[idx] = max(val[ls] + ask(r)-ask(mid),val[rs]);
}
void modify(int idx,int l,int r,int p,int d){
	if(l==r){
		if(d==0)	val[idx]=p;
		else	val[idx] = p+d;
		return;
	}
	int mid = (l+r)>>1;
	if(p<=mid)	modify(ls,l,mid,p,d);
	else modify(rs,mid+1,r,p,d);
	val[idx] = max(val[ls] + ask(r)-ask(mid),val[rs]);
}

long long int query(int idx,int l,int r,int L,int R){
	if(L>r||l>R)	return -1000000000000000000LL;	
	if(L<=l&&r<=R)	return val[idx];
	int mid = (l+r)>>1;
	long long int lres = query(ls,l,mid,L,R);
	long long int rres = query(rs,mid+1,r,L,R);
	long long int res=rres;
	if(min(R,r)>mid)
		res = max(res,lres+ask(min(R,r))-ask(mid));
	else
		res = max(res,lres);
	return res;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin>>q;
	build(1,1,1000000);
	for(int i=1;i<=q;i++){
		char op;
		cin>>op;
		int x;
		if(op=='?'){
			cin>>x;
			cout<<query(1,1,1000000,1,x)-x<<'\n';
		}
		else if(op=='+'){
			cin>>t[i]>>d[i];
			add(t[i],d[i]);
			modify(1,1,1000000,t[i],d[i]);
		}
		else{
			cin>>x;
			add(t[x],-d[x]);
			modify(1,1,1000000,t[x],0);
		}
	}
}