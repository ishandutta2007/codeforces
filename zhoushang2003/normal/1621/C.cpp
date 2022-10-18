#import<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,x,y,v[N],p[N],f;
int Q(int x)
{
	cout<<'?'<<' '<<x<<'\n';
	cin>>y;
	return y;
}
main()
{
	for(cin>>n;cin>>n;)
	{
		memset(v,0,sizeof(v));
		for(int i=1;i<=n;i++)
			if(!v[i])
			{
				while(Q(i)!=i);
				v[i]=1,p[i]=f=Q(i);
				while(y!=i)
					v[f]=1,p[f]=Q(i),f=y;
			}
		cout<<'!'<<' ';
		for(int i=1;i<=n;i++)
			cout<<p[i]<<' ';
		puts("");
	}
}