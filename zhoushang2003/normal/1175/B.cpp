#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
bool v[N];
long long l,A,p=1,q[N],t,x;
string s;
int main()
{
	cin>>l;
	while(l--&&cin>>s)
		if(s[0]=='a')
		{
			A+=p;
			if(A>=(1ll<<32))
			{
				cout<<"OVERFLOW!!!";
				return 0;
			}
		}
		else if(s[0]=='f'&&cin>>x)
		{
			q[++t]=x;
			if(p<(1ll<<32))
				p*=x,v[t]=true;
		}
		else
		{
			if(v[t])
				v[t]=false,p/=q[t];
			t--;
		}
	cout<<A;
	return 0;
}