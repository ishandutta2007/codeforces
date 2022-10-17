#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int n,f[N],r;

int x[N],y[N],t[N];

int dis(int a,int b)
{
	return abs(x[a]-x[b])+abs(y[a]-y[b]);
}

int mx;

int main()
{
	x[0]=y[0]=1;
	t[0]=0;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>r>>n;
	for(int i=1;i<=n;i++)
		cin>>t[i]>>x[i]>>y[i];
	mx=-1e9;
	for(int i=1,j=-1;i<=n;i++)
	{
		while(j+1<i&&t[i]-t[j+1]>r*2)
			mx=max(mx,f[++j]);
		f[i]=-1e9;
		f[i]=max(f[i],mx+1);
		for(int k=j+1;k<i;k++)
			if(dis(k,i)<=t[i]-t[k])	
				f[i]=max(f[i],f[k]+1);
	}
	cout<<*max_element(f,f+n+1)<<endl;
}