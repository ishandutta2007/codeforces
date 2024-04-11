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
const int M=50;
LL dp[M][2][2];
LL calc(int x,int y){
	if (x<0 || y<0) return 0;
	ms(dp,0);
	dp[31][1][1]=1;
	DF(i,31,1){
		bool o0=x>>(i-1)&1;
		bool o1=y>>(i-1)&1;
		F(ii,0,1){
			F(jj,0,1){
				dp[i-1][(!o0 && ii)][(!o1 && jj)]+=dp[i][ii][jj];
				if (!ii || o0) dp[i-1][ii][(!o1 && jj)]+=dp[i][ii][jj];
				if (!jj || o1) dp[i-1][(!o0 && ii)][jj]+=dp[i][ii][jj];
			}
		}
	}
//	cout<<dp[0][0][0]+dp[0][1][0]+dp[0][0][1]<<"   GG\n";
	return dp[0][0][0]+dp[0][1][0]+dp[0][0][1]+dp[0][1][1];
}
LL gg(int l,int r){
	return calc(r,r)+calc(l-1,l-1)-2ll*calc(l-1,r);
}
int main(){
	int T=read();
	while (T--){
		int l=read(),r=read();
		cout<<gg(l,r)<<"\n";
	}
    return 0;
}