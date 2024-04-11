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
		scanf("%s",ch+1); n=strlen(ch+1);
		int so=0,s0=0,sd=0;
		F(i,1,n){
			if (ch[i]=='0') s0++;
			int o=ch[i]-'0';
			if (o&1) ;
			else so++;
			sd+=o;
		}
		if (s0 && (so-1)>0 && sd%3==0) puts("red");
		else puts("cyan");
	}
	return 0;
}