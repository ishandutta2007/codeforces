#include<bits/stdc++.h>
using namespace std;
const int N=4e5+1;
long long n,w[N],p[N],t,r,A;
vector<int>a,b;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>w[i];
	for(int i=1;i<30;i++)
	{
		for(int j=1;j<=n;j++)
			p[j]=w[j]%(1<<i);
		a.clear(),b.clear();
		for(int j=1;j<=n;j++)
			if(p[j]<(1<<(i-1)))
				a.push_back(p[j]);
			else
				b.push_back(p[j]-(1<<(i-1)));
		sort(a.begin(),a.begin()+a.size()),sort(b.begin(),b.begin()+b.size());
		t=0,r=a.size();
		for(int j=0;j<a.size();j++)
		{
			while(r>0&&a[r-1]+a[j]>=(1<<(i-1)))
				r--;
			t+=a.size()-max(r,(long long)j+1);
		}
		r=b.size();
		for(int j=0;j<b.size();j++)
		{
			while(r>0&&b[r-1]+b[j]>=(1<<(i-1)))
				r--;
			t+=b.size()-max(r,(long long)j+1);
		}
		r=b.size();
		for(int j=0;j<a.size();j++)
		{
			while(r>0&&b[r-1]+a[j]>=(1<<(i-1)))
				r--;
			t+=r;
		}
		t%=2;
		A+=t*(1<<(i-1));
	}
	cout<<A;
	return 0;
}