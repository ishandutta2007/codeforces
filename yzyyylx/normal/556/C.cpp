#include<bits/stdc++.h>
using namespace std;

int n,m,mx=0,last,ans;

int main()
{
	int i,j,p,q,u,v;
	cin>>n>>m;
	ans=n*2-1-m;
//	cout<<ans;
	for(i=1;i<=m;i++)
	{
		bool z;
		z=false;
		scanf("%d%d",&u,&last);
		if(last==1) z=true;
		q=0;
		for(j=2;j<=u;j++)
		{
			scanf("%d",&v);
			if(v-last==1&&z==true)
			{
//				cout<<endl<<i<<endl;
				last=v;
				q++;
			}
			else last=-1;
		}
		mx=max(mx,q);
	}
	cout<<ans-mx*2;
}