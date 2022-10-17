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
bool qry(LL x){
	cout<<"? "<<x<<endl;
	bool tmp;
	cin>>tmp;
	return tmp;
}
LL n;
int main(){
	int T=read();
	while (T--){
		cin>>n;
		LL l=1,r=n-1,delta=0,p0=n;
		bool st=0;
		while (l<=r){
			LL mid=(l+r>>1);
			if (st) delta-=mid;
			else delta+=mid;
			p0=min(n-delta,p0);
			l=mid+1; st^=1;
		}
		qry(p0); LL p1=p0,ans=n;
		l=1; r=n-1; st=0;
		while (l<=r){
			LL mid=(l+r>>1);
			if (st) p1=p0-mid;
			else p1=p0+mid;
			if (qry(p1)) r=mid-1,ans=mid;
			else l=mid+1;
			st^=1;
			p0=p1;
		}
		cout<<"= "<<ans<<endl;
	}
	return 0; 
}