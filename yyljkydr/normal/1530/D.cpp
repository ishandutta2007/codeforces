#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T,n,a[N],vis[N],ans,to[N],out[N],in[N],lst[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),out[i]=0,in[i]=0,to[i]=0;
		ans=0;
		for(int i=1;i<=n;i++)
			if(!in[a[i]])
				to[i]=a[i],out[i]=1,in[a[i]]=1,lst[a[i]]=i,ans++;
		vector<int>A,B,c;
		for(int i=1;i<=n;i++)
			if(in[i]&&!out[i])
				A.push_back(i);
			else if(!in[i]&&out[i])
				B.push_back(i);
			else if(!in[i]&&!out[i])
				c.push_back(i);
		for(int i=0;i<A.size();i++)
			to[A[i]]=B[i],lst[B[i]]=A[i];
		if(c.size()!=1)
		{
			for(int i=0;i<c.size();i++)
				to[c[i]]=c[(i+1)%c.size()],lst[c[(i+1)%c.size()]]=c[i];
		}
		else
		{
			int p=a[c[0]];
			to[lst[p]]=c[0];
			to[c[0]]=p;
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)
			printf("%d%c",to[i]," \n"[i==n]);
	}
}