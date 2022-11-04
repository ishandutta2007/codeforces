#include<bits/stdc++.h>
using namespace std;
#define N 300005
int n,k,a[N],s[N],l[N],r[N];
vector<int> G[1000005];
long long ans;
int ask(int k,int l,int r){
	return upper_bound(G[k].begin(),G[k].end(),r)-
		   lower_bound(G[k].begin(),G[k].end(),l);
}
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i]=(s[i-1]+a[i])%k;
	}
	for (int i=0;i<=n;i++)
		G[s[i]].push_back(i);
	for (int i=1;i<=n;i++){
		l[i]=i-1;
		for (;l[i]&&a[l[i]]<a[i];)
			l[i]=l[l[i]];
	}
	for (int i=n;i;i--){
		r[i]=i+1;
		for (;r[i]<=n&&a[r[i]]<=a[i];)
			r[i]=r[r[i]];
	}
	for (int i=1;i<=n;i++)
		if (i-l[i]<r[i]-i)
			for (int j=l[i]+1;j<=i;j++)
				ans+=ask((a[i]+s[j-1])%k,i,r[i]-1);
		else
			for (int j=i;j<=r[i]-1;j++)
				ans+=ask((s[j]-a[i]%k+k)%k,l[i],i-1);
	printf("%lld\n",ans-n);
}