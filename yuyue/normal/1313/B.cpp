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

int main(){
//	freopen("in.txt","r",stdin);
	int T=read();
	while (T--){
		int n=read(),x=read(),y=read();
		int mx=min(x-1,n-y)+min(y-1,n-x),mi=min((x+y<=n ? 1 : x+y-n+1),n);
		if (x-1>n-y){
			mx+=x-1-(n-y);
		}
		cout<<mi<<" "<<mx+1<<"\n";
	}
	return 0;
}