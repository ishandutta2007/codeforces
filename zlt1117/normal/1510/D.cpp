#include<bits/stdc++.h>
namespace imzzy{
	typedef long long ll;
	#define endl '\n'
	#define rgi register int
	#define fout std::cout
	class fastin{private:int _ch,_f;
	public:inline fastin&operator>>(char&c){c=getchar();return*this;}
	template<typename _Tp>inline fastin&operator>>(_Tp&_x){
	_x=0;while(!isdigit(_ch))_f|=(_ch==45),_ch=getchar();
	while(isdigit(_ch))_x=(_x<<1)+(_x<<3)+(_ch^48),_ch=getchar();
	_f&&(_x=-_x,_f=0);return*this;}fastin(){_ch=_f=0;}
	}fin;
}using namespace imzzy;
// ----------------------------
// #define int ll
using namespace std;
const int mod=1000000007,inf=1201201201;
const int maxn=100004,maxm=500004;

int a[maxn];
long double dp[maxn][10];
int pre[maxn][10],choose[maxn][10];
int ans[maxn],indx;
signed main() {
	int n,d;
	fin>>n>>d;
	for(rgi i=1;i<=n;++i) fin>>a[i];
	for(rgi i=0;i<10;++i) dp[0][i]=-inf;
	dp[0][1]=log2(1);
	for(rgi i=1;i<=n;++i) {
		for(rgi j=0;j<10;++j) dp[i][j]=dp[i-1][j],pre[i][j]=j;
		for(rgi j=0;j<10;++j) if(dp[i-1][j]+log2((long double)a[i])>dp[i][j*a[i]%10]) {
			dp[i][j*a[i]%10]=dp[i-1][j]+log2((long double)a[i]);
			pre[i][j*a[i]%10]=j;
			choose[i][j*a[i]%10]=1;
		}
	}
	// for(rgi i=1;i<=n;++i) {
	// 	for(rgi j=0;j<10;++j) fout<<dp[i][j]<<' ';
	// 	fout<<endl;
	// } fout<<endl;
	// for(rgi i=1;i<=n;++i) {
	// 	for(rgi j=0;j<10;++j) fout<<choose[i][j]<<' ';
	// 	fout<<endl;
	// } fout<<endl;
	// for(rgi i=1;i<=n;++i) {
	// 	for(rgi j=0;j<10;++j) fout<<pre[i][j]<<' ';
	// 	fout<<endl;
	// } fout<<endl;
	for(rgi i=n,t=d;i>0;--i) {
		if(choose[i][t]) ans[++indx]=a[i];
		t=pre[i][t];
	}
	if(indx==0||dp[n][d]<0) return puts("-1"),0;
	fout<<indx<<endl;
	for(rgi i=1;i<=indx;++i) fout<<ans[i]<<' ';
	return 0;
}
// ----------------------------
// by imzzy