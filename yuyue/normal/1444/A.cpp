#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline LL read(){
	char ch=getchar(); LL w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
int main(){
	int T=read();
	while (T--){
		LL n=read(),m=read();
		if (n%m!=0){
			cout<<n<<"\n";
			continue;
		}
		vector<int> pr;
		vector<int> ipr;
		for (int i=2;i*i<=m;i++){
			if (m%i==0){
				int o=1;
				while (m%i==0) m/=i,o*=i;
				pr.pb(i);
				ipr.pb(o);
//				cout<<i<<" "<<o<<"   fucl\n"; 
			}
		}
		if (m>1) pr.pb(m),ipr.pb(m);
		LL ans=1;
		F(i,0,SZ(pr)){
			LL tmp=n;
			while (tmp%ipr[i]==0) tmp/=pr[i];
			ans=max(ans,tmp);
		}
		cout<<ans<<"\n";
	}
	return 0;
}