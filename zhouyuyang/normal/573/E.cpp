#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[111111];
int v[111111];
ll s[111111];
int n;
int main(){
    ll r=0,t=0;
    scanf("%d\n",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		r+=1ll*a[i]*i; v[i]=1;
		s[i]=s[i-1]+a[i];
	}
	for(int i=0;i<10;i++){
		int k=1; ll t=0;
		for(int j=1;j<=n;j++){
			if (v[j]&&1ll*a[j]*k+s[n]-s[j]<0) v[j]=0;
			if (!v[j]&&1ll*a[j]*k+s[n]-s[j]>=0) v[j]=1;
			if (v[j]){
                s[j]=s[j-1]+a[j];
                t+=1LL*a[j]*k; k++;
			}
			else s[j]=s[j-1];
		}
        r=max(r,t);
	}
	printf("%lld",r);
}