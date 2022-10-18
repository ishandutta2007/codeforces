#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
bool v;
long long q,a,b,m,t,k,x,r[N],s;
int main()
{
	cin>>q;
	while(q--&&cin>>a>>b>>m)
	{
		if(a==b)
		{
			cout<<1<<" "<<a<<'\n';
			continue;
		}
		t=k=1;
		v=false;
		while(t*a<b)
			if(t*(a+1)<=b&&b<=t*(a+m))
			{
				x=b-t*(a+1);
				m--;
				for(int i=1;i<=k;i++)
					t=(t+1)/2,r[i]=min(m,x/t),x-=r[i]*t,r[i]++;
				cout<<k+1<<" "<<a<<" ";
				s=a;
				for(int i=1;i<=k;i++)
				{
					a=s+r[i],s+=a;
					cout<<a<<" ";
				}
				cout<<'\n';
				v=true;
				break;
			}
			else
				t*=2,k++;
		if(!v)
			cout<<-1<<'\n';
	}
	return 0;
}