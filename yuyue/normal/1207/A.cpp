#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
int main(){
	int T=read();
	while (T--){
		int bun=read(),be=read(),ch=read();
		int h=read(),c=read();
		int ab=bun/2; int ans=0;
		if (h>c){
			if (ab<=be){
				ans+=h*ab;
			}
			else {
				ans+=h*be;
				ans+=min(ch,(ab-be))*c;
			}
		}
		else {
			if (ab<=ch){
				ans+=c*ab;
			}
			else {
				ans+=c*ch;
				ans+=min((ab-ch),be)*h;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}