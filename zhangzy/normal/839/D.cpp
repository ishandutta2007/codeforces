#include<bits/stdc++.h>
#define ll long long
#define xxx 1000000
#define mod 1000000007
using namespace std;
int n,b[xxx+233]={0},v[xxx+233],ans=0,c[xxx+233]={0};

void R(int &x,int y){
	x+=y;
	x=(x%mod+mod)%mod;
}

int main(){
	scanf("%d",&n);
	for (int i=1,x;i<=n;i++){
		scanf("%d",&x);b[x]++;
	}
	c[1]=1;
	for (int i=2;i<=xxx;i++){
		c[i]=(c[i-1]<<1)%mod;
		v[i]=i;
	}
	for (int i=2;i<=xxx;i++){
		c[i]=(ll)c[i]*i%mod;
		for (int j=i+i;j<=xxx;j+=i){
			R(b[i],b[j]);
			R(v[j],-v[i]);
		}
	}
	for (int i=2;i<=xxx;i++){
		R(ans,(ll)c[b[i]]*(ll)v[i]%mod);
	}
	printf("%d\n",ans);
}