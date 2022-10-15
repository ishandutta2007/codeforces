#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=55,maxm=2500005;
int n;
int a[maxn];
bool f[maxn>>1][maxm];int pre[maxn>>1][maxm];
int main()
{
	generate_n(a+1,2*(n=read()),read);
	sort(a+1,a+2*n+1);
	f[0][0]=1;
	int sum=accumulate(a+3,a+2*n+1,0);
	for(int i=3;i<=2*n;i++)
		for(int j=min(n,i);j>=1;j--)
			for(int k=a[i];k<=sum;k++)
				if(!f[j][k]&&f[j-1][k-a[i]])
				{
					f[j][k]=1;
					pre[j][k]=i;
				}
	int mi=-1;
	for(int i=0;i<=sum;i++)
		if(f[n-1][i]&&(mi==-1||(max(i,sum-i)<max(mi,sum-mi))))mi=i;
	vector<int>l1,l2;
	l2.push_back(2);
	int now=n-1;
	while(now)
	{
		assert(pre[now][mi]);
		l2.push_back(pre[now][mi]);
		mi-=a[pre[now][mi]];
		now--;
	}
	for(int i=1;i<=2*n;i++)if(find(l2.begin(),l2.end(),i)==l2.end())l1.push_back(i);
	sort(l1.begin(),l1.end());
	sort(l2.begin(),l2.end(),greater<int>());
	for(int &i:l1)printf("%d ",a[i]);putchar('\n');
	for(int &i:l2)printf("%d ",a[i]);putchar('\n');
	return 0;
}