#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const int m = 1000100;
long long int pre1[m],pre2[m];
int open[m],close[m];
long long int inv[m];
long long int fac[m];

long long int C(int N,int K){
	if(K<0||K>N)	return 0;
	return fac[N]*inv[K]%mod*inv[N-K]%mod;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin>>s;
	int n=s.size();
	s.insert(0," ");
	fac[0]=inv[0]=inv[1]=fac[1]=1;
	for(int i=2;i<m;i++)
		fac[i]=fac[i-1]*i%mod;
	for(int i=2;i<m;i++)
		inv[i]=(mod-mod/i*inv[mod%i]%mod)%mod;
	for(int i=2;i<m;i++)
		inv[i]=inv[i]*inv[i-1]%mod;
	int q=0;
	for(int i=1;i<=n;i++){
		q+=s[i]=='?';
		open[i]=open[i-1]+(s[i]=='(')+(s[i]=='?');
	}
	for(int i=0;i<=q;i++){
		pre1[i]=C(q,i);
		if(i)	pre1[i]=(pre1[i]+pre1[i-1])%mod;
	}
	if(q){
		for(int i=0;i<q;i++){
			pre2[i]=C(q-1,i);
			if(i)	pre2[i]=(pre2[i]+pre2[i-1])%mod;
		}
	}
	for(int i=n;i>=1;i--)
		close[i]=close[i+1]+(s[i]==')');
	long long int ans=0;
	for(int i=1;i<=n;i++){
		int d=open[i]-close[i+1];
		if(s[i]=='(')
			if(d<=q)
				ans+=pre1[min(q,q-d)];
		if(s[i]=='?')
			if(d<=q-1)
				ans+=pre2[min(q-1-d,q-1)];
	}
	cout<<ans%mod<<endl;
}