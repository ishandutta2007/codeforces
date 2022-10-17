#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define N 500100
#define M 998244353
using namespace std;

int T,n,num[N];

int main()
{
	int i,j,t,p,q,ip,iq,it;
	cin>>T;
	while(T--)
	{
		scanf("%d",&n);
		p=q=INF,t=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&num[i]);
			if(num[i]>t)
			{
				t=num[i];
				it=i;
			}
			if(num[i]<p)
			{
				q=p,iq=ip;
				p=num[i],ip=i;
			}
			else if(num[i]<q)
			{
				q=num[i];
				iq=i;
			}
//			cout<<" "<<i<<" "<<ip<<" "<<iq<<" "<<it<<endl;
		}
		if(p+q>t) puts("-1");
		else printf("%d %d %d\n",min(min(ip,iq),it),ip+iq+it-min(min(ip,iq),it)-max(max(ip,iq),it),max(max(ip,iq),it));
	}
}