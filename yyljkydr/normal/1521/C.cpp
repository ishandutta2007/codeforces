#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

long long T;

int n,a[N];

int query(int t,int x,int y,int v)
{
	cout<<"? "<<t<<" "<<x<<" "<<y<<" "<<v<<endl;
	int r;
	cin>>r;
	return r;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		int vp=0;
		for(int i=1;i<n;i+=2)
		{
			int x=query(2,i,i+1,1);
			if(x==1)
			{
				vp=i;
				break;
			}
			else if(x==2)
			{
				int y=query(2,i+1,i,1);
				if(y==1)
				{
					vp=i+1;
					break;
				}
			}
		}
		if(!vp)
			vp=n;
		a[vp]=1;
		for(int i=1;i<=n;i++)
			if(i!=vp)
				a[i]=query(1,vp,i,n-1);
		cout<<"! ";
		for(int i=1;i<=n;i++)
			cout<<a[i]<<" \n"[i==n];
		cout<<endl;
	}
}