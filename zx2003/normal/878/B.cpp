#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000005;
int a[N],n,k,m,i,x,nn,j,xb,b[N],lst;
pair<int,int> c[N],d[N];
ll solve(int l,int r){
	int i,j,o;
	if(b[l]!=b[r])return 1ll*m*(r-l+1);
	for(i=l;b[i]==b[l] && i<=r;++i);
	for(j=r;b[j]==b[r] && j>=l;--j);
	if(i==r+1)return 1ll*m*(r-l+1)%k;
	o=i-l+r-j;
	if(o%k==0){
		int xx=solve(i,j);
		return xx?xx+k:0;
	}else return 1ll*(m-1)*(o%k)+1ll*(r-l+1-o)*m+o;
}
int main(){
	scanf("%d%d%d",&n,&k,&m);x=1;
	for(i=1;i<=n;++i){
		scanf("%d",a+i);
		if(i==1){
			c[xb=1]=make_pair(a[i],1);continue;
		}
		if(a[i]==c[xb].first){
			++c[xb].second;
			if(c[xb].second==k)c[xb].first=0,--xb,lst-=k;
		}else{
			c[++xb]=make_pair(a[i],1);
		}
	}
	for(j=1;j<=xb;++j)
		for(i=1;i<=c[j].second;++i)b[++nn]=c[j].first;
	cout<<solve(1,nn)<<endl;
	return 0;
}