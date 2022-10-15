#include<bits/stdc++.h>
using namespace std;
#define re register ll
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
typedef long long ll;
#define I inline void
#define IN inline ll
#define C(x,y) memset(x,y,sizeof(x))
#define STS system("pause")
template<class D>I read(D &res){
	res=0;register D g=1;register char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')g=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		res=(res<<3)+(res<<1)+(ch^48);
		ch=getchar();
	}
	res*=g;
}
map<ll,ll>mp,mt;
ll n,m,p;
ll a[202000],ans;
I ck(ll x){
	if(x<=1ll)return;
	if(mp[x])return;
	mp[x]=1ll;
	static ll s,now;s=now=0;
	F(i,1,n){
		if(a[i]<x){
			s+=(x-a[i]);continue;
		}
		now=a[i]%x;s+=min(now,x-now);
	}
	//if(ans>s)cout<<"!"<<x<<endl;
	ans=min(ans,s);
}
I chk(ll x){
	re now=x;
	F(i,2ll,sqrt(x)){
		if(now==1ll)return;
		if((now%i)==0ll){
			ck(i);
			while((now%i)==0ll)now/=i;
		}
	}
	if(now>1ll)ck(now);
}
int main(){
	read(n);
	F(i,1,n)read(a[i]);
	F(i,1,10)random_shuffle(a+1,a+1+n);
	ans=n;
	ck(2ll);p=1;m=min(n,20ll);
	while(m--&&p<=n){
		while(p<=n&&mt[a[p]])p++;
		if(p<=n)mt[a[p]]=1,chk(a[p]),chk(a[p]-1),chk(a[p]+1);
	}
	cout<<ans;
	return 0;
}