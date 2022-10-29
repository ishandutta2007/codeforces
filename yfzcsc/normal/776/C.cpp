#include<bits/stdc++.h>
using namespace std;
int n,k;
long long a[100100];
long long ans=0;
map<long long,int>st;
int main(){
	st[0]++;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	for(int i=1;i<=n;++i){
		a[i]+=a[i-1];
		for(long long j=1;j<=(1ll<<59)&&j>=-(1ll<<59);j*=k){
			ans+=st[a[i]-j];
			if(k==1)break;
			else if(j==-1&&k==-1)break;
		}
		st[a[i]]++;
	}
	
	printf("%lld",ans);
}