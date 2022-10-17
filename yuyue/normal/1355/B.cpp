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
const int M=3e5+10;
int n,a[M];
int main(){
	int T=read();
	while (T--){
		n=read();
		F(i,1,n) a[i]=read(); sort(a+1,a+n+1);
		int pos=1,ans=0,lst=1;
		while (1){
			while (pos<=n && pos-lst+1<a[pos]) pos++;
			if (pos>n) break;
			ans++; lst=pos+1; pos++;
		}
		cout<<ans<<'\n';
	}
    return 0;
}