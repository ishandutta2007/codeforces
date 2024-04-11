#include <bits/stdc++.h>
#define fst first
#define sec second
#define mp make_pair
using namespace std;
typedef long long ll;

int n;
double ans[100001];
ll x[100001],k[100001];

int main() {
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>ans[i];
	for(int i=1;i<=n;i++){
		ll a;cin>>a;
		ans[i]=a-ans[i];
	}
	for(int i=2;i<=n;i++)
		cin>>x[i]>>k[i];
	
	for(int i=n;i>1;i--){
		if(ans[i]>0)
			ans[x[i]]+=k[i]*ans[i];
		else ans[x[i]]+=ans[i];
		ans[i]=0;
	}
	cout<<(ans[1]<0.5?"YES":"NO");
	return 0;
}