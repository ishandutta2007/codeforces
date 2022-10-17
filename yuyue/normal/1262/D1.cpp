#include<bits/stdc++.h>
#define LL long long
#define SZ(x) (int)x.size()-1
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define pb push_back
#define ms(a,b) memset(a,b,sizeof a)
using namespace std;
int read(){
    char ch=getchar(); int w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
const int M=2e5+10;
int a[M],tt[M],t[M];
vector<pair<int,int> > q[M];
vector<int> v[M];
int ct[M];
int n,m,ans[M];
#define lc (x<<1) 
#define rc (x<<1|1)
#define mid (l+r>>1)
int s[M<<3];
void ad(int x,int l,int r,int p){
	if (l==r) return s[x]++,void();
	if (p<=mid) ad(lc,l,mid,p);
	else ad(rc,mid+1,r,p);
	s[x]=s[lc]+s[rc];
}
int qu(int x,int l,int r,int k){
	if (l==r) return l;
	if (s[lc]>=k) return qu(lc,l,mid,k);
	return qu(rc,mid+1,r,k-s[lc]);
}
int main(){
	n=read(); 
	F(i,1,n){
		tt[i]=t[i]=a[i]=read();
	}
	sort(tt+1,tt+n+1);
	int N=unique(tt+1,tt+n+1)-tt-1;
	F(i,1,n){
		int x=lower_bound(tt+1,tt+N+1,a[i])-tt;
		t[i]=a[i]=x;
		v[a[i]].pb(i);
	}
	sort(t+1,t+n+1,greater<int>());
	
	m=read();
	F(i,1,m){
		int x=read(),y=read();
		q[x].pb(make_pair(y,i));
	}
	F(i,1,n){
		int o=v[t[i]][ct[t[i]]]; ct[t[i]]++;
		ad(1,1,n,o);
		F(j,0,SZ(q[i])){
			int oo=q[i][j].first;
			ans[q[i][j].second]=a[qu(1,1,n,oo)];
		}
	}
	F(i,1,m) cout<<tt[ans[i]]<<"\n"; 
    return 0;
}