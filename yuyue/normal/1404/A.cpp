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
const int M=3e5+10;
char ch[M];
int f[M];
void work(){
	int n=read(),k=read();
	scanf("%s",ch);
	F(i,0,n) f[i]=-1;
	F(i,0,n-1){
		int o=i%k;
		if (ch[i]=='?') continue;
		if (f[o]!=-1 && f[o]!=ch[i]-'0'){
//			cout<<o<<"   gg \n";
			cout<<"NO\n";
			return ;
		}
		f[o]=ch[i]-'0';
	}
	int c0=0,c1=0;
	F(i,0,k-1){
		if (f[i]==0) c0++;
		if (f[i]==1) c1++;
	}
//	cout<<c0<<" "<<c1<<"   hh \n";
	if (c0<=k/2 && c1<=k/2) cout<<"YES\n";
	else cout<<"NO\n";
}
int main(){
	int T=read();
	while (T--) work();
	return 0;
}