#include <bits/stdc++.h>
using namespace std;
const int N=10005;
int n,q,dp[N];
struct Query{
	int L,R,x;
}Q[N];
bool cmp(Query a,Query b){
	return a.R<b.R;
}
int main(){
	scanf("%d%d",&n,&q);
	for (int i=1;i<=q;i++)
		scanf("%d%d%d",&Q[i].L,&Q[i].R,&Q[i].x);
	sort(Q+1,Q+q+1,cmp);
	memset(dp,0,sizeof dp);
	for (int i=1;i<=q;i++){
		int L=Q[i].L,R=Q[i].R,x=Q[i].x;
		for (int j=n;j>x;j--)
			if (dp[j-x]>=L)
				dp[j]=max(dp[j],dp[j-x]);
		dp[x]=max(dp[x],R);
	}
	int tot=0;
	for (int i=1;i<=n;i++)
		if (dp[i])
			tot++;
	printf("%d\n",tot);
	for (int i=1;i<=n;i++)
		if (dp[i])
			printf("%d ",i);
	return 0;
}