#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF=1000000000000L+10;

#define mp make_pair
#define fr first
#define sc second

int n,m,k; ll s;
ll a[200010],b[200010];
ll t[200010],c[200010];

pair<ll,ll> min_a[200010],min_b[200010];

int main(){
	scanf("%d%d%d%lld",&n,&m,&k,&s);
	for(int i=0;i<n;i++)scanf("%lld",&a[i]);
	for(int i=0;i<n;i++)scanf("%lld",&b[i]);
	for(int i=0;i<m;i++)scanf("%lld%lld",&t[i],&c[i]);
	
	vector<pair<ll,ll>> vec[2];
	for(int i=0;i<m;i++){
		vec[t[i]-1].push_back(mp(c[i],i));
	}
	for(int i=0;i<2;i++){
		sort(vec[i].begin(),vec[i].end());
		vec[i].push_back(mp(INF,-1));
	}
	min_a[0]=mp(a[0],0);
	min_b[0]=mp(b[0],0);
	for(int i=1;i<n;i++){
		min_a[i]=min(min_a[i-1],mp(a[i],(ll)i));
		min_b[i]=min(min_b[i-1],mp(b[i],(ll)i));
	}
	
	int l=0,r=n;
	while(1){
		if(l==r){
			if(l==n){
				puts("-1");
				return 0;
			}
			else {
				printf("%d\n",l+1);
			}
		}
		int med=(l+r)/2;
		ll sum=0;
		int u=0,v=0;
		for(int i=0;i<k;i++){
			if(min_a[med].fr*vec[0][u].fr<=min_b[med].fr*vec[1][v].fr){
				if(l==r)printf("%lld %lld\n",vec[0][u].sc+1,min_a[med].sc+1);
				sum+=min_a[med].fr*vec[0][u++].fr;
			}
			else {
				if(l==r)printf("%lld %lld\n",vec[1][v].sc+1,min_b[med].sc+1);
				sum+=min_b[med].fr*vec[1][v++].fr;
			}
		}
		if(l==r)break;
		if(sum<=s)r=med;
		else l=med+1;
	}
}