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
const int M=3003,mod=1e9+7; 
int f[M][M],n,m;
char ch[M];
bool mp[M][M];
LL dp(int x,int y,int s,int t){
	ms(f,0); f[x][y]=1;
	F(i,x,s){
		F(j,y,t){
			if (mp[i][j]) continue;
			if (i>x && !mp[i-1][j]) f[i][j]=(f[i][j]+f[i-1][j])%mod; 
			if (j>y && !mp[i][j-1]) f[i][j]=(f[i][j]+f[i][j-1])%mod; 
		}
	}
//	cout<<"( "<<x<<" , "<<y<<" ) -> "<<"( "<<s<<" , "<<t<<" )\n";
//	cout<<f[2][1]<<"\n";
	return f[s][t]; 
}
int main(){
	n=read(); m=read();
	F(i,1,n){
		scanf("%s",ch+1);
		F(j,1,m){
			if (ch[j]=='#') mp[i][j]=1;
		}
	}
	cout<<(1ll*dp(2,1,n,m-1)*dp(1,2,n-1,m)%mod+mod-dp(1,2,n,m-1)*dp(2,1,n-1,m)%mod)%mod<<"\n";
	return 0;
}