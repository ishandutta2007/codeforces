#include <bits/stdc++.h>
using namespace std;
const int N=1005;
int n,tot[N];
int main(){
	scanf("%d",&n);
	for (int i=1,x,y;i<n;i++)
		scanf("%d%d",&x,&y),tot[x]++,tot[y]++;
	int ans=0;
	for (int i=1;i<=n;i++)
		if (tot[i]==1)
			ans++;
	printf("%d",ans);
	return 0;
}