#include<bits/stdc++.h>
using namespace std;
const int N=1e3+1;
int n,a[N],b[N],c,x,X,Y,l,r;
bool C(int k)
{
	cout<<"? "<<X<<" "<<1<<" "<<X<<" "<<k<<endl;
	fflush(stdout);
	cin>>x;
	if(x&1)
		return false;
	return true;
}
bool D(int k)
{
	cout<<"? "<<1<<" "<<X<<" "<<k<<" "<<X<<endl;
	fflush(stdout);
	cin>>x;
	if(x&1)
		return false;
	return true;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cout<<"? "<<i<<" "<<1<<" "<<i<<" "<<n<<endl;
		fflush(stdout);
		cin>>a[i];
		a[i]&=1;
	}
	for(int i=1;i<=n;i++)
	{
		cout<<"? "<<1<<" "<<i<<" "<<n<<" "<<i<<endl;
		fflush(stdout);
		cin>>b[i];
		b[i]&=1;
	}
	for(int i=1;i<=n;i++)
		c+=a[i]+b[i];
	if(c==4)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(a[i]&&b[j])
				{
					cout<<"? "<<i<<" "<<j<<" "<<i<<" "<<j<<endl;
					fflush(stdout);
					cin>>x;
					if(x==1&&!X)
						X=i,Y=j;
					else if(x==1&&X)
					{
						cout<<"! "<<X<<" "<<Y<<" "<<i<<" "<<j<<endl;
						fflush(stdout);
						return 0;
					}
				}
	}
	for(int i=1;i<=n;i++)
		if(a[i])
		{
			X=i,l=1,r=n;
			while(l<r)
				if(C((l+r)/2))
					l=(l+r)/2+1;
				else
					r=(l+r)/2;
			cout<<"! ";
			for(int j=1;j<=n;j++)
				if(a[j])
					cout<<j<<" "<<l<<" ";
			cout<<endl;
			fflush(stdout);
			return 0;
		}
	for(int i=1;i<=n;i++)
		if(b[i])
		{
			X=i,l=1,r=n;
			while(l<r)
				if(D((l+r)/2))
					l=(l+r)/2+1;
				else
					r=(l+r)/2;
			cout<<"! ";
			for(int j=1;j<=n;j++)
				if(b[j])
					cout<<l<<" "<<j<<" ";
			cout<<endl;
			fflush(stdout);
			return 0;
		}
}