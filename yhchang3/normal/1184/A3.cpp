#include<bits/stdc++.h>
using namespace std;

bool isprime[4000001];

vector<int> pt,poly[101];

long long int ex(long long int a,long long int b,int mod){
	a%=mod;
	long long int res=1;
	while(b){
		if(b&1)
			res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}


long long int findroot(int p,int mod){
	while(true){
		long long int x=rand()%(mod-1)+1;
		x=ex(x,(mod-1)/p,mod);
		if(x!=1)	return x;
	}
}

bool valid(int p,long long int t,int mod){
	long long int res=0,r=1;
	if(t==1||t==mod-1)	return false;
	for(int i=0;i<p;i++){
		res=(res+r*poly[p][i])%mod;
		r=r*t%mod;
	}
	return res==0;
}

void test(int p,int mod){
	long long int r=findroot(p,mod),t=1;
	for(int i=0;i<p;i++){
		t=t*r%mod;
		if(valid(p,t,mod)){
			cout<<mod<<' '<<t<<endl;
			exit(0);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie();
	int n,m;
	cin>>n>>m;
	string w1,w2;
	cin>>w1>>w2;
	for(int i=2;i<=4000000;i++)
		isprime[i]=true;
	for(long long int i=2;i<=4000000;i++)
		if(isprime[i])
			for(long long int j=i*i;j<=4000000;j+=i)
				isprime[j]=false;
	for(int i=2;i<=100;i++)
		if(isprime[i])
			pt.emplace_back(i);
	for(int it:pt){
		poly[it].resize(it);
		for(int j=0;j<n;j++)
			poly[it][j%it]+=w1[j]-w2[j];
	}
	for(int mod=max(10000,m);;mod++){
		if(!isprime[mod])	continue;
		for(int it:pt)
			if((mod-1)%it==0){
				test(it,mod);
			}
	}
}