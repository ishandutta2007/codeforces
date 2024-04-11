#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
int n,x,p[N][2],A[N];
vector<int>a[N];
void D(int k,int t)
{
	if(A[k])
		return;
	A[k]=t;
	for(int i=0;i<a[k].size();i++)
		D(a[k][i],3-t);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=0;j<2;j++)
		{
			cin>>x;
			if(p[x][j])
				a[i].push_back(p[x][j]),a[p[x][j]].push_back(i),p[x][j]=0;
			else
				p[x][j]=i;
		}
	for(int i=1;i<=n;i++)
		D(i,1);
	for(int i=1;i<=n;i++)
		if(A[i]==1)
			cout<<'b';
		else
			cout<<'r';
	return 0;
}