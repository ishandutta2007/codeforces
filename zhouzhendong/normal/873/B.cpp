#include <bits/stdc++.h>
using namespace std;
const int N=200005;
char s[N];
int n,a[N],Min[N],Max[N],tot[N];
int main(){
	scanf("%d%s",&n,s+1);
	for (int i=1;i<=n;i++)
		a[i]=s[i]-'0';
	tot[0]=0;
	for (int i=1;i<=n;i++)
		if (a[i]==0)
			tot[i]=tot[i-1]-1;
		else
			tot[i]=tot[i-1]+1;
	for (int i=0;i<N;i++)
		Min[i]=1e9,Max[i]=-1e9;
	for (int i=0;i<=n;i++){
		int v=tot[i]+100000;
		Min[v]=min(Min[v],i);
		Max[v]=max(Max[v],i);
	}
	int ans=0;
	for (int i=0;i<N;i++)
		ans=max(ans,Max[i]-Min[i]);
	printf("%d",ans);
	return 0;
}