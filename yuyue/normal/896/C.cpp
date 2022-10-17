#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
const int mod=1e9+7,M=2e5+10;
int seed,n,m,V;;
inline int read(){
	int ret=seed;
	seed=(seed*7ll+13)%mod;
	return ret;
}
LL fast(LL x,int p,int mod){
	LL ret=1;
	for (;p;p>>=1,x=x*x%mod) if (p&1) ret=ret*x%mod;
	return ret;
}
LL a[M];
set<int> s;
#define Iter set<int>::iterator 
Iter split(int x){
	Iter it=s.lower_bound(x);
	if (it!=s.end() && *it==x) return it;
	it--; a[x]=a[*it];
	return s.insert(x).first;
}
void assign(int l,int r,int x){
	Iter lt=split(l),rt=split(r+1);
	s.erase(lt,rt);
	s.insert(l);
	a[l]=x;
}
void add(int l,int r,int x){
	Iter lt=split(l),rt=split(r+1);
	for (;lt!=rt;lt++) a[*lt]+=x;
}
LL val[M];
int le[M],p[M];
bool cmp(int x,int y){ return val[x]<val[y];}
LL kth(int l,int r,int k){
	Iter lt=split(l),rt=split(r+1);
	int ct=0;
	for (;lt!=rt;){
		Iter nt=lt; nt++;
		val[++ct]=a[*lt];
		p[ct]=ct;
		le[ct]=*nt-*lt;
		lt=nt;
	}
	sort(p+1,p+ct+1,cmp);
	F(i,1,ct){
		if (k<=le[p[i]]) return val[p[i]];
		k-=le[p[i]];
	}
}
LL S(int l,int r,int p,int mod){
	Iter lt=split(l),rt=split(r+1);
	LL ret=0;
	for (;lt!=rt;){
		Iter nt=lt; nt++;
		ret=(ret+fast(a[*lt]%mod,p,mod)*(*nt-*lt))%mod;
		lt=nt;
	}
	return ret;
}
int main(){
	cin>>n>>m>>seed>>V;
	F(i,1,n) a[i]=read()%V+1,s.insert(i); s.insert(n+1);
	F(i,1,m){
		int op=read()%4+1;
		int l=read()%n+1,r=read()%n+1,x,y;
		if (l>r) swap(l,r);
		if (op==3) x=read()%(r-l+1)+1;
		else x=read()%V+1;
		if (op==4) y=read()%V+1;
		if (op==1) add(l,r,x);
		if (op==2) assign(l,r,x);
		if (op==3) cout<<kth(l,r,x)<<"\n";
		if (op==4) cout<<S(l,r,x,y)<<"\n";
	}
	return 0;
}