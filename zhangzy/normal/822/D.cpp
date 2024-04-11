#include<cstdio>
#include<iostream>
#include<cstring>
#define xxx 5000000
#define mod 1000000007
#define ll long long
using namespace std;
ll k,l,r,ans=0;

int np[xxx+233]={0};
void PRI(){
	np[1]=1;
	for (int i=2;i<=xxx;i++){
		if (!np[i]){
			for (int j=i+i;j<=xxx;j+=i){
				np[j]=1;
			}
		}
	}
	return;
}

ll f[xxx+233];
int main(){
	PRI();
	for (int i=1;i<=xxx;i++){
		f[i]=(ll)i*(i-1)/2;
	}
	for (int i=2;i<=xxx;i++){
		if (!np[i]){
			for (int j=i+i;j<=xxx;j+=i){
				f[j]=min(f[j],f[i]+(ll)i*f[j/i]);
			}
		}
	}
	for (int i=1;i<=xxx;i++){
		f[i]%=mod;
	}
	//for (int i=1;i<=21;i++) cout<<f[i]<<' ';
	cin>>k>>l>>r;
	ll t=1;
	for (int i=l;i<=r;i++){
		ans=(ans+t*f[i])%mod;
		t=(t*k%mod+mod)%mod;
	}
	cout<<ans;
}