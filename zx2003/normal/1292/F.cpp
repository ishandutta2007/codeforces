#include<bits/stdc++.h>
using namespace std;
const int mo=1e9+7;
const int N=65,S=1099;
int n,a[N],m,i,j,k,b[N],cnt[S],f[N][S],g[N],z,c;
bool bb[N];
vector<int>lt;int ss[N];
int gfa(int x){return g[x]==x?x:g[x]=gfa(g[x]);}
inline void add(int&x,const int&y){x+=y-mo;x+=x>>31&mo;}
int main(){
	scanf("%d",&n);for(i=1;i<=n;++i)scanf("%d",a+i);sort(a+1,a+n+1);
	for(i=1;i<=n;++i)if(!b[i]){
		for(c=0,j=i+1;j<=n;++j)c+=a[j]%a[i]==0;
		if(c>1){++m;bb[i]=1;for(j=i+1;j<=n;++j)if(a[j]%a[i]==0)b[j]|=1<<m-1;}
	}else ++z;
	for(i=0;i<1<<m;++i)for(j=1;j<=n;++j)if(b[j] && (b[j]&i)==b[j])++cnt[i];
	for(i=0;i<m;++i)g[i]=i;
	for(i=1;i<=n;++i)for(j=0;j<m;++j)for(k=j+1;k<m;++k)if((b[i]>>j&1) && (b[i]>>k&1))g[gfa(j)]=gfa(k);
	for(i=0;i<m;++i){if(gfa(i)==i)lt.push_back(i);ss[gfa(i)]|=1<<i;}
	f[0][0]=1;
	for(i=0;i<lt.size();++i)for(j=0;j<1<<m;++j)if(f[i][j])for(k=1;k<=n;++k)if(b[k]&ss[lt[i]])add(f[i+1][j|b[k]],f[i][j]);
	for(;i<z;++i)for(j=0;j<1<<m;++j)if(f[i][j]){
		if(i<cnt[j])f[i+1][j]=(f[i+1][j]+1ll*(cnt[j]-i)*f[i][j])%mo;
		for(k=1;k<=n;++k)if(0<(b[k]&j) && (b[k]&j)<b[k])add(f[i+1][j|b[k]],f[i][j]);
	}
	printf("%d\n",f[z][(1<<m)-1]);
	return 0;
}