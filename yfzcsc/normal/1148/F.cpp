#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[1001000];
unsigned long long b[1010000];
ll nsum;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%lld%llu",&a[i],&b[i]),nsum+=a[i];
	unsigned long long s=0;
	for(int i=0;i<62;++i){
		ll sum=0;
		for(int j=1;j<=n;++j)if(b[j]<(1ull<<i+1)&&b[j]>=(1ull<<i))
			sum+=a[j];
		if(sum&&(sum>0)==(nsum>0)){
			s|=1ull<<i;
			for(int j=1;j<=n;++j)if(b[j]>>i&1)a[j]=-a[j];
		}
	}
	printf("%llu",s);
}