#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n,k;
ll c[500010];

int main(){
	scanf("%lld%lld",&n,&k);
	for(int i=0;i<n;i++)scanf("%lld",&c[i]);
	sort(c,c+n);
	reverse(c,c+n);
	
	ll ret=0;
	int t=n;
	ll sum=0;
	for(int i=0;i<n;i++){
		if(sum+c[i]<0){
			t=i;
			break;
		}
		ret+=sum;
		sum+=c[i];
	}
	//cout<<t<<" "<<ret<<" "<<sum<<endl;
	ret+=sum*((n-t+k)/(k+1));
	//cout<<ret<<endl;
	for(int i=t;i<n;i++){
		ret+=c[i]*((n-1-i)/(k+1));
	}
	cout<<ret<<endl;
}