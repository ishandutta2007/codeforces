#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
bool v[N];
long long T,n,x,y,z,q[N],t,X,A,B,f[N],c[N];
vector<long long>a[N],b[N];
int main()
{
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--&&cin>>n)
	{
		for(int i=1;i<=2*n;i++)
			c[i]=0;
		for(int i=1;i<=2*n;i++)
			a[i].clear(),b[i].clear();
		for(int i=1;i<2*n;i++)
		{
			cin>>x>>y>>z;
			a[x].push_back(y),a[y].push_back(x),b[x].push_back(z),b[y].push_back(z),c[x]++,c[y]++;
		}
		for(int i=1;i<=2*n;i++)
			f[i]=1;
		for(int i=1;i<=2*n;i++)
			if(c[i]==1)
				q[++t]=i;
		for(int i=1;i<=2*n;i++)
			v[i]=false;
		A=B=0;
		while(t)
		{
			X=q[t--],v[X]=true;
			for(int i=0;i<a[X].size();i++)
				if(!v[a[X][i]])
				{
					if(f[X]&1)
						A+=b[X][i];
					B+=b[X][i]*min(f[X],2*n-f[X]);
					f[a[X][i]]+=f[X],c[a[X][i]]--;
					if(c[a[X][i]]==1)
						q[++t]=a[X][i];
				}
		}
		cout<<A<<" "<<B<<'\n';
	}
	return 0;
}