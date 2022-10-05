#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N=101000;
int ch[N][2], cntr, rt, sz[N];
ll lk[N], lb[N], val[N];

#define lc ch[x][0]
#define rc ch[x][1]

void U(int x){
	sz[x]=sz[lc]+sz[rc]+1;
}
void PT(int x,ll k,ll b){
	val[x]+=sz[lc]*k+b;
	lk[x]+=k;
	lb[x]+=b;
}
void D(int x){
	if (lk[x]||lb[x]){
		int sl=sz[lc];
		if (lc) PT(lc,lk[x],lb[x]);
		if (rc) PT(rc,lk[x],lb[x]+(sl+1)*lk[x]);
		lk[x]=lb[x]=0;
	}
}
void mg(int &x,int l,int r){
	if (!l||!r){
		x=l+r; return;
	}
	D(l); D(r);
	if ((rand()+0.5)/(RAND_MAX+1)<(double)sz[l]/(sz[l]+sz[r])){
		x=l; mg(rc,rc,r);	
	}else{
		x=r; mg(lc,l,lc);
	}
	U(x);
}
void spl(int &l,int &r,int x,int s){
	if (!x){
		l=r=0; return;
	}
	D(x);
	int sl=sz[lc]+1;
	if (s>=sl){
		l=x; spl(ch[l][1],r,rc,s-sl); U(l);
	}else{
		r=x; spl(l,ch[r][0],lc,s); U(r);
	}
}
void add(int p,ll v){
	int x=++cntr; sz[x]=1; val[x]=v;
	int a, b; spl(a,b,rt,p-1);
	mg(rt,a,x); mg(rt,rt,b);
}
ll que(int p,int x=rt){
	int sl=sz[lc];
	if (p==sl+1) return val[x];
	D(x);
	if (p<=sl) return que(p,lc);
	else return que(p-sl-1,rc);
}

int n;

int main(){
	srand(time(0));
	add(1,0);
	cin>>n;
	for (;n--;){
		ll t; cin>>t;
		int l=1, r=cntr-1, anp=cntr;
		while (l<=r){
			int mid=l+r>>1;
			if (que(mid)+mid*t>que(mid+1)){
				anp=mid; r=mid-1;
			}else{
				l=mid+1;
			}
		}
		ll org=que(anp);
		{
			int a, b; spl(a,b,rt,anp-1);
			PT(b,t,anp*t);
			mg(rt,a,b);
		}
		add(anp,org);
	}
	ll ans=0;
	for (int i=1;i<=cntr;++i)
		ans=max(ans,que(i));
	cout<<ans<<endl;
}