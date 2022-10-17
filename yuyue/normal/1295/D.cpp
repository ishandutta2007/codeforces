#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
LL ans=0;
vector<LL> v; 
LL calc(LL x,LL d){
	return x/d;
}		LL a,m;

void dfs(int x,LL mul,int op){
	if (x==SZ(v)+1){
		ans+=op*(calc(a+m-1,mul)-calc(a-1,mul));
		return ;	
	}
	dfs(x+1,mul,op);
	dfs(x+1,mul*v[x],-op);
}
int main(){
	int T=read();
	while (T--){
		cin>>a>>m;
		LL d=__gcd(a,m);
		a/=d; m/=d;
		v.clear(); ans=0;
		LL t=m;
		for (LL i=2;i*i<=t;i++){
			if (t%i==0){
				v.pb(i);
				while (t%i==0) t/=i;
			}
		}
		if (t>1) v.pb(t);
		dfs(0,1,1);
		cout<<ans<<"\n";
	}
	return 0;
}