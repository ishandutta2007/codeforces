#include<bits/stdc++.h>
using namespace std;
int n,p,k,a;
long long ans;
unordered_map<int,int>mp;
int main(){
	scanf("%d%d%d",&n,&p,&k);
	for(;n--;)scanf("%d",&a),++mp[(1ll*a*a%p*a%p+p-k)*a%p];
	for(auto u:mp)ans+=1ll*u.second*(u.second-1)>>1;
	printf("%lld\n",ans);
	return 0;
}