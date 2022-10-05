#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m,k,a[101000],g,c[101000],l,x,ans,all;

int main(){
	cin>>n>>k>>m;
	for (int o=n;o--;){
		cin>>x;
		if (x==a[g]&&g){
			c[g]++;
		}else{
			a[++g]=x;
			c[g]=1;
		}
		if (c[g]==k) g--;
	}
	for (int i=1;i<=g;i++) all+=c[i];
	for (l=1;l*2<=g;l++){
		if (a[l]!=a[g+1-l]) break;
		if (c[l]=(c[l]+c[g+1-l])%k){
			c[g+1-l]=0;
			break;
		}
	}
		
	if (l*2<=g){
		for (int i=l;i<=g+1-l;i++) ans+=c[i];
		ans=ans*(m-1)+all;
	}else if (c[l]*m%k){
		ans=all-c[l]+c[l]*m%k;
	}
	cout<<ans;
}