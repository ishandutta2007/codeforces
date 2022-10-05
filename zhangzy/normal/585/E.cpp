#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e7, mod=1e9+7;

int n, a[N+3], s[N+3], mu[N+3], pw[N+3];

ll ans;

ll gao(int x){
	if (!x) return 0;
	return (ll)(pw[x]-1)*(n-x)%mod;
}

int main(){
	pw[0]=1;
	for (int i=1;i<=N;++i) pw[i]=pw[i-1]*2%mod;
	cin>>n;
	for (int i=1;i<=n;++i){
		int x; scanf("%d",&x);
		++a[x];
	}
	for (int i=1;i<=N;++i){
		for (int j=i;j<=N;j+=i)
			s[i]+=a[j];
	}
	for (int i=1;i<=N;++i){
		mu[i]=(i==1)-mu[i];
		if (mu[i])
			for (int j=i+i;j<=N;j+=i)
				mu[j]+=mu[i];
	}
	for (int i=2;i<=N;++i)
		if (mu[i]){
			ans-=mu[i]*gao(s[i]);
		}
	cout<<(ans%mod+mod)%mod<<endl;
}