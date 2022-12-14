#include<bits/stdc++.h>
using namespace std;


long long int ans=-1;

long long int fac[21];

long long int C(int n,int k){
	if(n<k)	return 0;
	return fac[n]/fac[n-k]/fac[k];
}
int cnt[20];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	fac[0]=1;
	for(int i=1;i<=20;i++)
		fac[i]=fac[i-1]*i;
	while(T--){
		long long int x;
		cin>>x;
		int d=2;
		for(int i=0;i<=19;i++)
			cnt[i]=0;
		int m=0;
		ans=-1;
		while(x){
			cnt[x%d]++;
			m=max(m,int(x%d));
			x/=d;
			d++;
		}
		d--;
		long long int tmp=1;
		int use=0;
		for(int i=m;i>=1;i--){
			tmp*=C(d-i-use,cnt[i]);
			use+=cnt[i];
		}
		ans+=tmp;
		tmp=1;
		use=1;
		for(int i=m;i>=1;i--){
			tmp*=C(d-i-use,cnt[i]);
			use+=cnt[i];
		}
		ans-=tmp;
		cout<<ans<<endl;
	}
}