#include<iostream>
using namespace std;
int q,n,k,A;
int main()
{
	cin>>q;
	while(q--&&cin>>n)
	{
		for(int i=1;i<26;i++)
			if(n&1<<i)
				k=i;
		if(n!=(1<<k+1)-1)
			cout<<(1<<k+1)-1<<endl;
		else
		{
			A=1;
			for(int i=2;i*i<=n;i++)
				if(n%i==0)
					A=n/i,i=1e4;
			cout<<A<<endl;
		}
	}
	return 0;
}