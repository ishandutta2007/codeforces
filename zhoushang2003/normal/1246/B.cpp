#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
vector<int>a,B;
long long n,m,w[N],b[N],C[N],A;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		a.clear(),B.clear();
		for(int j=2;j*j<=w[i];j++)
			if(w[i]%j==0)
			{
				a.push_back(j),B.push_back(0);
				while(w[i]%j==0)
					w[i]/=j,B[B.size()-1]++;
				B[B.size()-1]%=m;
			}
		if(w[i]>1)
			a.push_back(w[i]),B.push_back(1);
		w[i]=b[i]=1;
		for(int j=0;j<a.size();j++)
			for(int k=1;k<=B[j];k++)
				w[i]*=a[j];
		for(int j=0;j<a.size();j++)
		{
			for(int k=1;k<=(m-B[j])%m;k++)
			{
				b[i]*=a[j];
				if(b[i]>=N)
					break;
			}
			if(b[i]>=N)
				break;
		}
		C[w[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]>=N)
			continue;
		if(w[i]==b[i])
			A+=C[b[i]]-1;
		else
			A+=C[b[i]];
	}
	cout<<A/2;
	return 0;
}