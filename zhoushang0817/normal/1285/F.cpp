#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
long long u[N],n,x,v[N],A,q[N],t,s,c[N];
vector<int>a[N];
void U(int x,int t)
{
	for(int i=0;i<a[x].size();i++)
		c[a[x][i]]+=t;
}
int main()
{
	for(int i=1;i<N;i++)
	{
		for(int j=i;j<N;j+=i)
			a[j].push_back(i);
		if(i==1)
			u[i]=1;
		else if((i/a[i][1])%a[i][1]==0)
			u[i]=0;
		else
			u[i]=-u[i/a[i][1]];
	}
	cin>>n;
	while(n--&&cin>>x)
		v[x]=1,A=max(A,x);
	for(int i=1;i<N;i++)
	{
		for(long long j=(N-1)/i;j>0;j--)
		{
			if(!v[i*j])
				continue;
			for(int k=0;k<a[j].size();k++)
				s+=u[a[j][k]]*c[a[j][k]];
			while(s)
			{
				if(__gcd(j,q[t])==1)
					A=max(A,i*j*q[t]),s--;
				U(q[t--],-1);
			}
			q[++t]=j,U(j,1);
		}
		while(t)
			U(q[t--],-1);
	}
	cout<<A;
	return 0;
}