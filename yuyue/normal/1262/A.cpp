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
int main(){
	int T=read();
	while (T--){
		int n=read();
		int l=0,r=1e9;
		F(i,1,n){
			int x=read(),y=read();
			l=max(l,x); r=min(r,y);
		}
		cout<<((r-l)>0 ? 0 : l-r)<<"\n";
	}
    return 0;
}