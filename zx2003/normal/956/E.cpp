#include<bits/stdc++.h>
using namespace std;
const int N=10005;
bitset<N>f,g;
int n,l,r,a[N],b,s[N],su,i,j,asu;
vector<int>c,d;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>l>>r;
	for(i=1;i<=n;++i)cin>>a[i];
	for(i=1;i<=n;++i){
		cin>>b;
		if(b)c.push_back(a[i]),su+=a[i];
			else d.push_back(a[i]);
	}
	sort(c.begin(),c.end());
	f[0]=g[0]=1;
	for(i=0;i<d.size();++i)f|=f<<d[i];
	s[0]=f[0];
	for(i=1;i<N;++i)
		s[i]=s[i-1]+f[i];
	int fl;asu=su;
	for(i=c.size()-1;i>=0;--i){
		if(su<=r-l){
			fl=-1;
			for(j=0;j<=r-su;++j)
				if(g[j] && s[r-su-j]>(l==j?0:s[l-j-1])){
			if(j==asu-su && fl==-1)fl=0;else fl=1;
				}
			if(fl!=-1)break;
		}
		g|=g<<c[i];su-=c[i];
	}
//	for(i=0;i<N;++i)printf("%d ",s[i]);
	if(i==-1){
		if(su<=r-l){
			fl=0;
			for(j=0;j<=r-su;++j)
				if(g[j] && s[r-su-j]>(l<=j?0:s[l-j-1])){
			if(j==asu-su && fl==0)fl=0;else fl=1;
				}
		}
	}
	printf("%d\n",i+1+fl);
	return 0;
}