#include<bits/stdc++.h>
#define maxn 5050
using namespace std;

int n,m;
int L[maxn],R[maxn];

int sum[maxn],cnt1[maxn];

int main()	{
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;++i)
		scanf("%d%d",L+i,R+i);
	int ans=0;
	for (int i=0;i<m;++i)	{
		int tot=0;
		for (int i=0;i<=n;++i)	sum[i]=0;
		for (int j=0;j<m;++j)
			if (i!=j)
				++sum[L[j]],--sum[R[j]+1];
		for (int i=1;i<=n;++i)	{
			sum[i]+=sum[i-1];
			if (sum[i])	++tot;
		}
//		for (int i=1;i<=n;++i)	cout<<sum[i]<<" "; cout<<endl;
		for (int i=1;i<=n;++i)	cnt1[i]=cnt1[i-1]+(sum[i]==1);
		for (int j=0;j<m;++j)
			if (i!=j)
				ans=max(ans,tot-(cnt1[R[j]]-cnt1[L[j]-1]));
	}
	printf("%d\n",ans);
	return 0;
}