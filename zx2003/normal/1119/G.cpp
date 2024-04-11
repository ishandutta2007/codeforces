#include<bits/stdc++.h>
using namespace std;
typedef vector<int>V;
const int N=1e6+5;
int n,m,xb,i,j,h[N],s[N],hs[N],x,y,a[N];
V out[N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(i=1;i<=m;++i){
		cin>>h[i];
		for(j=1;j<=h[i]/n;++j)out[++xb]=V(m,i);
		h[i]%=n;hs[i]=(hs[i-1]+h[i])%n;
		a[i]=hs[i];
	}
	a[m]=n;sort(a+1,a+m+1);
	for(i=1;i<=m;++i)s[i]=a[i]-a[i-1];
	for(i=1,j=0;i<=m;++i)for(;h[i]>0;){
		if(j==0)out[++xb].resize(m);
		++j;out[xb][j-1]=i;h[i]-=s[j];if(j==m)j=0;
	}
	if(j)for(;j<=m;++j)out[xb][j-1]=m;
	printf("%d\n",xb);for(i=1;i<=m;++i)printf("%d%c",s[i],i==m?'\n':' ');
	for(i=1;i<=xb;++i){for(int x:out[i])printf("%d ",x);puts("");}
	return 0;
}