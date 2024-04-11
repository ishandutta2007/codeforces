#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,i,j;
string a[N],ass[N];
vector<int>b[N],c[N],lu[N],ru[N],ld[N],rd[N],l[N],r[N],d[N],u[N];
inline void add(int x,int y,int d){
	b[x-d][y-d]++;
	if(y+d+1<m)b[x-d][y+d+1]--;
	if(x+d+1<n)b[x+d+1][y-d]--;
	if(x+d+1<n && y+d+1<m)++b[x+d+1][y+d+1];
}
inline bool ck(int M){
	for(i=0;i<n;++i)memset(&b[i][0],0,m<<2);
	for(i=0;i<n;++i)for(j=0;j<m;++j)if(c[i][j]>=M)add(i,j,M),ass[i][j]='X';else ass[i][j]='.';
	for(i=0;i<n;++i)for(j=1;j<m;++j)b[i][j]+=b[i][j-1];
	for(i=1;i<n;++i)for(j=0;j<m;++j)b[i][j]+=b[i-1][j];
	for(i=0;i<n;++i)for(j=0;j<m;++j)if(!b[i][j] && a[i][j]=='X')return 0;
	return 1;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(i=0;i<n;++i){
		cin>>a[i];
		ass[i].resize(m);
		ld[i].resize(m);
		rd[i].resize(m);
		lu[i].resize(m);
		ru[i].resize(m);
		b[i].resize(m);
		c[i].resize(m);
		l[i].resize(m);
		u[i].resize(m);
		r[i].resize(m);
		d[i].resize(m);
	}
	for(i=0;i<n;++i)for(j=0;j<m;++j){
		l[i][j]=a[i][j]=='X'?(j && a[i][j-1]=='X'?l[i][j-1]+1:0):-1;
		u[i][j]=a[i][j]=='X'?(i && a[i-1][j]=='X'?u[i-1][j]+1:0):-1;
	}
	for(i=n-1;i>=0;--i)for(j=m-1;j>=0;--j){
		r[i][j]=a[i][j]=='X'?(j<m-1 && a[i][j+1]=='X'?r[i][j+1]+1:0):-1;
		d[i][j]=a[i][j]=='X'?(i<n-1 && a[i+1][j]=='X'?d[i+1][j]+1:0):-1;
	}
	for(i=0;i<n;++i)for(j=0;j<m;++j)lu[i][j]=a[i][j]=='X'?(i && j && a[i-1][j]=='X' && a[i][j-1]=='X'?
		min(min(l[i][j],u[i][j]),lu[i-1][j-1]+1):0):-1;
	for(i=n-1;i>=0;--i)for(j=0;j<m;++j)ld[i][j]=a[i][j]=='X'?(i+1<n && j && a[i+1][j]=='X' && a[i][j-1]=='X'?
		min(min(l[i][j],d[i][j]),ld[i+1][j-1]+1):0):-1;
	for(i=0;i<n;++i)for(j=m-1;j>=0;--j)ru[i][j]=a[i][j]=='X'?(i && j+1<m && a[i-1][j]=='X' && a[i][j+1]=='X'?
		min(min(r[i][j],u[i][j]),ru[i-1][j+1]+1):0):-1;
	for(i=n-1;i>=0;--i)for(j=m-1;j>=0;--j)rd[i][j]=a[i][j]=='X'?(i+1<n && j+1<m && a[i+1][j]=='X' && a[i][j+1]=='X'?
		min(min(r[i][j],d[i][j]),rd[i+1][j+1]+1):0):-1;
	for(i=0;i<n;++i)for(j=0;j<m;++j)c[i][j]=min(min(lu[i][j],ld[i][j]),min(ru[i][j],rd[i][j]));
	int L=0,R=min(n,m),M;
	for(;L<R;){
		M=L+R+1>>1;
		if(ck(M))L=M;else R=M-1;
	}
	cout<<L<<'\n';
	ck(L);
	for(i=0;i<n;++i)cout<<ass[i]<<'\n';cout<<endl;
	return 0;
}