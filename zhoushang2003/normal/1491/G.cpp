#import<bits/stdc++.h>
using namespace std;
const int N=4e6;
int n,a[N],u[N],x,c,A[N],B[N],d;
vector<int>v[N];
void S(int x,int y)
{
	swap(a[x],a[y]),A[++d]=x,B[d]=y;
}
main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		if(!u[i])
		{
			v[++c].push_back(i),u[i]=1,x=a[i];
			while(x!=i)
				v[c].push_back(x),u[x]=1,x=a[x];
		}
	for(int i=1;i<c;i+=2)
	{
		S(v[i][0],v[i+1][0]);
		for(int j=1;j<v[i].size();j++)
			S(v[i][j],v[i+1][0]);
		for(int j=1;j<v[i+1].size();j++)
			S(v[i][0],v[i+1][j]);
		S(v[i][0],v[i+1][0]);
	}
	if(c&1&&v[c].size()>1)
		if(v[c].size()==2)
		{
			for(int i=1;i<=3;i++)
				if(i!=v[c][0]&&i!=v[c][1])
					S(i,v[c][0]),S(i,v[c][1]),S(i,v[c][0]),i=3;
		}
		else
		{
			S(v[c][0],v[c][v[c].size()-1]);
			for(int i=1;i<v[c].size()-2;i++)
				S(v[c][i],v[c][v[c].size()-1]);
			S(v[c][0],v[c][v[c].size()-2]),S(v[c][v[c].size()-2],v[c][v[c].size()-1]),S(v[c][0],v[c][v[c].size()-1]);
		}
	cout<<d<<'\n';
	for(int i=1;i<=d;i++)
		cout<<A[i]<<' '<<B[i]<<'\n';
}