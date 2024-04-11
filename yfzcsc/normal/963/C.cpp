#include<bits/stdc++.h>
#define maxn 201000
using namespace std;
typedef long long ll;
typedef long double ldb;
ll a[maxn],b[maxn],c[maxn],n,all,g,ans;
map<ll,ll>wxh1,wxh2;
int main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;++i){
		scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
		wxh1[a[i]]+=c[i],wxh2[b[i]]+=c[i];
		all+=c[i],g=__gcd(g,c[i]);
	}
	for(int i=1;i<=n;++i)
		if(fabs((ldb)wxh1[a[i]]/(ldb)all-(ldb)c[i]/(ldb)wxh2[b[i]])>1e-16)
			return puts("0"),0;
	for(ll i=1;i*i<=g;i++)if(g%i==0)
		ans+=1+(i*i!=g);
	printf("%lld",ans);
}