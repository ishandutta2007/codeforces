#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,m1=998244353,m2=99844853;
typedef pair<int,int>pii;
inline pii operator+(const pii&a,const pii&b){return pii((a.first+b.first)%m1,(a.second+b.second)%m2);}
inline pii operator*(const pii&a,const pii&b){return pii(1ll*a.first*b.first%m1,1ll*a.second*b.second%m2);}
const pii E(0,0);
string s[N];
vector<pii>f1[N],f2[N];
int n,m,i,j;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;++i)cin>>s[i];
	for(i=0;i<=n+1;++i)f1[i].resize(m+2),f2[i].resize(m+2);
	for(i=1;i<=n;++i)for(j=1;j<=m;++j)f1[i][j]=i==1 && j==1?pii(1,1):(s[i][j-1]=='#'?E:f1[i-1][j]+f1[i][j-1]);
	if(f1[n][m]==E){cout<<"0\n";return 0;}
	for(i=n;i;--i)for(j=m;j;--j)f2[i][j]=i==n && j==m?pii(1,1):(s[i][j-1]=='#'?E:f2[i+1][j]+f2[i][j+1]);
	for(i=1;i<=n;++i)for(j=1;j<=m;++j)if((i!=1 || j!=1) && (i!=n || j!=m))
		{if(f1[i][j]*f2[i][j]==f1[n][m]){
			cout<<"1\n";return 0;}}
	cout<<"2\n";
	return 0;
}