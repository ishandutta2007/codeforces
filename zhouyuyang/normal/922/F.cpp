#include<bits/stdc++.h>
#define pa pair<int,int>
#define N 300005
using namespace std;
int d[N],a[N],tot;
bool b[N];
pa c[N];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=1;i<<1<=n;i++)
		for (int j=i<<1;j<=n;j+=i) d[j]++;
	for (int i=1;i<=n;i++) d[i]+=d[i-1];
	if (d[n]<k) return puts("No"),0;
	for (int i=1;i<=n;i++)
		if (d[i]>=k){
			n=i;
			break;
		}
	for (int i=n;i<<1>n;i--)
		c[++tot]=pa(d[i]-d[i-1],i);
	sort(c+1,c+tot+1);
	for (int i=tot,j=d[n]-k;i;i--)
		if (j>=c[i].first)
			j-=c[i].first,b[c[i].second]=1;
	tot=0;
	for (int i=1;i<=n;i++)
		if (!b[i]) a[++tot]=i;
	printf("Yes\n%d\n",tot);
	for (int i=1;i<=tot;i++)
		printf("%d ",a[i]); 
}