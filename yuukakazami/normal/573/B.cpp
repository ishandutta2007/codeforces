#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define fora(i,a,b) for(int i=a;i<b;++i)
int n;
int a[123456];
int L[123456],R[123456];

int main(){
	cin>>n;
	rep(i,n) scanf("%d",a+i);
	L[0]=1; fora(i,1,n) L[i] = min(a[i],L[i-1]+1);
	R[n-1]=1; for(int i=n-2;i>=0;--i) R[i] = min(a[i],R[i+1]+1);
	int ans = 0;
	rep(i,n) ans = max(ans,min(L[i],R[i]));
	cout<<ans<<endl;
}