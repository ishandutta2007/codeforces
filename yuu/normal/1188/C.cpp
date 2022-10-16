#include <bits/stdc++.h>
using namespace std;
const int base=998244353;
int n, k;
int a[1001];
int first[1002];
int f[1001];
int g[1001];
int main(){
	cin>>n>>k;
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=1; i<=n; i++) first[i]=i;
	sort(a+1, a+n+1);
	int ans=0;
	for(int len=1; len*(k-1)<=100000; len++){///count the number of segment having the minimum atleast len, ans=sum
		for(int j=n; j>=1; j--)	while((first[j]<=n)&&(a[first[j]]-a[j]<len)) first[j]++;
		for(int i=1; i<=n; i++) f[i]=1;
		for(int cnt=1; cnt<k; cnt++){
			for(int i=1; i<=n; i++) if(f[i]){
				g[first[i]]+=f[i];
				while(g[first[i]]>=base) g[first[i]]-=base;
			}
			for(int i=1; i<=n; i++){
				g[i]=g[i]+g[i-1];
				while(g[i]>=base) g[i]-=base;
				f[i]=g[i];
			}
			for(int i=1; i<=n; i++) g[i]=0;
		}
		for(int i=1; i<=n; i++){
			ans+=f[i];
			while(ans>=base) ans-=base;
		}
	}
	cout<<ans<<'\n';
		
}