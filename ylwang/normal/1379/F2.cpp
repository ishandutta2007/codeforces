#include <bits/stdc++.h>
using namespace std;
template<class t> inline t read(t &x){
	char c=getchar();bool f=0;x=0;
	while(!isdigit(c)) f|=c=='-',c=getchar();
	while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
	if(f) x=-x;return x;
}
template<class t,class ...A> inline void read(t &x,A &...a){
	read(x);read(a...);
}
template<class t> inline void write(t x){
	if(x<0) putchar('-'),write(-x);
	else{if(x>9) write(x/10);putchar('0'+x%10);}
}

#define pii pair<int,int>
#define x first
#define y second

const int N=2e5+5;
int n,m,q,mi[N<<2],ma[N<<2];
map<pii,bool> mp;
bool fl[N<<2];
set<int> lset[N],rset[N]; //lset:LrsetR

void pushup(int x){
	ma[x]=max(ma[x<<1],ma[x<<1|1]);
	mi[x]=min(mi[x<<1],mi[x<<1|1]);
	fl[x]=fl[x<<1]|fl[x<<1|1]|(ma[x<<1|1]>=mi[x<<1]); //
}

void build(int x,int l,int r){
	if(l==r){
		ma[x]=0;mi[x]=m+1;
		return ;
	}
	int mid=l+r>>1;
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
	pushup(x);
}

void up(int x,int l,int r,int p){
	if(l==r){
		ma[x]=rset[l].size()?*rset[l].rbegin():0; //
		mi[x]=lset[l].size()?*lset[l].begin():m+1; //
		fl[x]=ma[x]>=mi[x];
		return ;
	}
	int mid=l+r>>1;
	if(p<=mid) up(x<<1,l,mid,p);
	else up(x<<1|1,mid+1,r,p);
	pushup(x);
}

void doit(){
	int x,y;
	read(x,y);x++;y++;
	if(mp[pii(x,y)]){ //map
		if(y&1) rset[x>>1].erase(y>>1); //+1
		else lset[x>>1].erase(y>>1);
	}
	else{
		if(y&1) rset[x>>1].insert(y>>1);
		else lset[x>>1].insert(y>>1);
	}
	mp[pii(x,y)]^=1;
	up(1,1,n,x>>1);
	puts(fl[1]?"NO":"YES"); //fl=1
}

signed main(){
	read(n,m,q);
	build(1,1,n);
	while(q--) doit();
}