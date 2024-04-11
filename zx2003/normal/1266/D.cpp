#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,m,u,v,d,i,j;
vector<vector<ll>>ans;
vector<int>A,B;
ll a[N],x;
int main(){
	scanf("%d%d",&n,&m);
	for(;m--;)scanf("%d%d%d",&u,&v,&d),a[u]-=d,a[v]+=d;
	for(i=1;i<=n;++i)if(a[i]>0)A.push_back(i);else if(a[i]<0)B.push_back(i);
	for(i=j=0;i<A.size();){
		u=A[i];v=B[j];
		ans.push_back({v,u,x=min(abs(a[u]),abs(a[v]))});
		a[u]-=x;a[v]+=x;i+=!a[u];j+=!a[v];
	}
	printf("%d\n",(int)ans.size());
	for(auto u:ans)printf("%lld %lld %lld\n",u[0],u[1],u[2]);
	return 0;
}