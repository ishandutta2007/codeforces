#include<bits/stdc++.h>
#define ld long double
using namespace std;

int k,b,n,ans;
ld an;
map<ld,bool>P;

int main()
{
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&k,&b);
		if(k==0) continue;
		an=(ld)b/k;
		if(P[an]==false)
		{
			P[an]=true;
			ans++;
		}
	}
	cout<<ans;
}