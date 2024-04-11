#import<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,A[N],v,x,y;
vector<int>a[N],b[N];
void D(int x,int f,int p)
{
	for(int i=0;i<a[x].size();i++)
		if((y=a[x][i])!=f)
			A[b[x][i]]=p,D(y,x,5-p),p=5-p;
}
main()
{
	for(cin>>n;cin>>n;)
	{
		for(int i=1;i<=n;i++)
			a[i].clear(),b[i].clear();
		for(int i=1;i<n;i++)
			cin>>x>>y,a[x].push_back(y),a[y].push_back(x),b[x].push_back(i),b[y].push_back(i);
		v=0;
		for(int i=1;i<=n;i++)
			if(a[i].size()>2)
				v=1;
		if(v)
		{
			puts("-1");
			continue;
		}
		D(1,0,2);
		for(int i=1;i<n;i++)
			cout<<A[i]<<' ';
		puts("");
	}
}