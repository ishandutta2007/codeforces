#include<bits/stdc++.h>
#define LL long long
#define SZ(x) (int)x.size()-1
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define pb push_back
#define ms(a,b) memset(a,b,sizeof a)
#define oo(x) fixed<<setprecision(x)
using namespace std;
int read(){
    char ch=getchar(); int w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
char ch[1111];
int n;
int main(){
	int T=read();
	while (T--){
		LL x;
		cin>>x;
		if (x>14 && x%14>0 && x%14<=6) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}