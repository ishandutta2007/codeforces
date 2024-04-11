#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,mo,w[N],q,l,r,i,a[N],xb;
int phi(int x){
	int ans=x,i=2;
	for(;i*i<=x;++i)
		if(x%i==0){
			ans=ans/i*(i-1);
			for(;x%i==0;x/=i);
		}
	if(x>1)ans=ans/x*(x-1);
	return ans;
}
inline pair<int,int> pow(int x,int y,int mo){
	int ans=1,f1=0,f2=0;
	for(;y;y>>=1,f2|=1ll*x*x>=mo,x=1ll*x*x%mo)if(y&1)f1|=1ll*ans*x>=mo || f2,ans=1ll*ans*x%mo;
	return make_pair(ans,f1);
}
pair<int,int> solve(int l,int r,int d){
	if(w[l]==1)return make_pair(1,0);
	if(l==r)return make_pair(w[l]%a[d],w[l]>=a[d]);
	if(a[d]==2)return make_pair(w[l]&1,1);
	pair<int,int>u=solve(l+1,r,d+1);
	return pow(w[l],u.first+u.second*a[d+1],a[d]);
}
int main(){
	scanf("%d%d",&n,&mo);
	for(i=1;i<=n;++i)scanf("%d",w+i);scanf("%d",&q);
	if(mo==1){
		for(i=1;i<=q;++i)puts("0");return 0;
	}
	for(i=mo;i>1;a[++xb]=i,i=phi(i));
	while(q--){
		scanf("%d%d",&l,&r);
		printf("%d\n",solve(l,r,1).first);
	}
	return 0;
}