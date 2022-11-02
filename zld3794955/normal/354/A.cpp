#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n,l,r,w[N]={},Ql,Qr;
int main()
{	
	scanf("%d%d%d%d%d",&n,&l,&r,&Ql,&Qr);
	for(int i=1;i<=n;++i)
		scanf("%d",&w[i]);
	int S=accumulate(w+1,w+n+1,0),s=0,ans=0x7fffffff;
	for(int i=0;i<=n;++i)
	{
		ans=min(ans,s*l+(S-s)*r+max(0,(n-i)-i-1)*Qr+max(0,i-(n-i)-1)*Ql);
		s+=w[i+1];
	}
	printf("%d\n",ans);
	return 0;
}