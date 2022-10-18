#include<bits/stdc++.h>
using namespace std;
const int N=3e6+1,D=1e9+7;
long long T,x,a[N],n,t,A;
string s;
int main()
{
	cin>>T;
	while(T--&&cin>>x>>s)
	{
		for(int i=1;i<=s.size();i++)
			a[i]=s[i-1]-'0';
		n=s.size();
		for(int i=1;i<=x;i++)
		{
			if(n>=x)
				break;
			if(a[i]==1)
				continue;
			t=n;
			for(int j=2;j<=a[i];j++)
				for(int k=i+1;k<=t;k++)
					a[++n]=a[k];
		}
		A=s.size();
		for(int i=1;i<=x;i++)
			t=A-i,(A+=(a[i]-1)*t)%=D;
		cout<<(A+D)%D<<'\n';
	}
	return 0;
}