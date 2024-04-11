#include<bits/stdc++.h>
using namespace std;
const int N=1e3+1,M=2e3+1;
bool v[M],p[M];
int n,m,c[M],q[M],t,C,A[M];
string s[N];
vector<int>a[M],b[M];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(s[i][j-1]=='>')
				a[j+n].push_back(i),c[i]++;
			else if(s[i][j-1]=='<')
				a[i].push_back(j+n),c[j+n]++;
			else
				b[j+n].push_back(i),b[i].push_back(j+n);
	while(true)
	{
		t=0,memset(p,false,sizeof(p));
		for(int i=1;i<=n+m;i++)
			if(c[i]>0||v[i])
				q[t++]=i,p[i]=true;
		for(int i=0;i<t;i++)
			for(int j=0;j<b[q[i]].size();j++)
				if(!p[b[q[i]][j]]&&!v[b[q[i]][j]])
					q[t++]=b[q[i]][j],p[b[q[i]][j]]=true;
		if(t==n+m)
			break;
		C++;
		for(int i=1;i<=n+m;i++)
			if(!p[i])
			{
				A[i]=C,v[i]=true;
				for(int j=0;j<a[i].size();j++)
					c[a[i][j]]--;
			}
	}
	C=0;
	for(int i=1;i<=n+m;i++)
		if(!v[i])
			C++;
	if(C)
	{
		cout<<"No";
		return 0;
	}
	cout<<"Yes"<<endl;
	for(int i=1;i<=n;i++)
		cout<<A[i]<<" ";
	cout<<endl;
	for(int i=1;i<=m;i++)
		cout<<A[i+n]<<" ";
	return 0;
}