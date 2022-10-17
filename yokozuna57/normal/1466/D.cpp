#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll a[100010];
ll cnt[100010];

int main(){
	int t;
	scanf("%d",&t);
	for(;t>0;t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%lld",&a[i]);
		for(int i=0;i<n;i++)cnt[i]=0;
		for(int i=0;i<n-1;i++){
			int u,v;
			scanf("%d%d",&u,&v); u--; v--;
			cnt[u]++;
			cnt[v]++;
		}
		ll sum=0;
		for(int i=0;i<n;i++)sum+=a[i];
		printf("%lld",sum);
		vector<int> vec;
		for(int i=0;i<n;i++){
			for(int j=0;j<cnt[i]-1;j++)vec.push_back(a[i]);
		}
		sort(vec.begin(),vec.end());
		reverse(vec.begin(),vec.end());
		for(int i=0;i<n-2;i++){
			sum+=vec[i];
			printf(" %lld",sum);
		}
		printf("\n");
	}
}