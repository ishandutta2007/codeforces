#include<iostream>
#include<vector>
using namespace std;
const int N=3e5+1;
const long long P=998244353;
bool v[N],f[N];
int T,n,m,x,y,q[N],s,t,X;
long long A;
vector<int>a[N];
int main()
{
	cin>>T;
	while(T--&&cin>>n>>m)
	{
		while(m--&&cin>>x>>y)
			a[x].push_back(y),a[y].push_back(x);
		for(int i=1;i<=n;i++)
			v[i]=false;
		A=1;
		for(int i=1;i<=n;i++)
			if(!v[i])
			{
				x=y=1,s=t=0,q[t++]=i,v[i]=true;
				while(s<t)
				{
					X=q[s++];
					for(int i=0;i<a[X].size();i++)
						if(!v[a[X][i]])
							v[a[X][i]]=true,f[a[X][i]]=!f[X],q[t++]=a[X][i];
				}
				for(int i=0;i<t;i++)
					for(int j=0;j<a[q[i]].size();j++)
						if(f[q[i]]==f[a[q[i]][j]])
							x=y=0;
				for(int i=0;i<t;i++)
					if(!f[q[i]])
						(x*=2)%=P;
					else
						(y*=2)%=P;
				(A*=x+y)%=P;
			}
		cout<<A<<endl;
		for(int i=1;i<=n;i++)
			a[i].clear();
	}
	return 0;
}