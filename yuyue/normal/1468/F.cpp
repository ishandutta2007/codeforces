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
const int M=1e5+10;
int a[M],b[M],X[M],Y[M];
int n;
LL ag[M];
const long double Pi=(long double)acos(-1.0);
map<pair<int,int>,int> mp;
void work(){
	n=read(); mp.clear();
	LL GG=(LL)((long double)Pi*1e11);
	LL ans=0;
	F(i,1,n){
		a[i]=read();
		b[i]=read();
		X[i]=read();
		Y[i]=read();
		X[i]-=a[i];
		Y[i]-=b[i];
		int d=abs(__gcd(X[i],Y[i]));
		X[i]/=d; Y[i]/=d;
		ans+=mp[make_pair(-X[i],-Y[i])];
		mp[make_pair(X[i],Y[i])]++;
//		cout<<X[i]<<" "<<Y[i]<<"  dd\n";
	}
	cout<<ans<<"\n";
}
int main(){
	int T=read();
	while (T--){
		work();
	}
	return 0; 
}