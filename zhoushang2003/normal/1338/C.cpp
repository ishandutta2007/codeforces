#include<bits/stdc++.h>
using namespace std;
long long T,n,x,A,B,t;
int main()
{
	cin>>T;
	while(T--&&cin>>n)
	{
		if(n<=3)
		{
			cout<<n<<'\n';
			continue;
		}
		x=1;
		while(3*x<n)
			n-=3*x,x*=4;
		t=(n-1)/3+1,A=x+(n-1)/3,B=2*x;
		while(x>1)
		{
			x/=4;
			if(x<t&&t<=2*x)
				B+=2*x;
			else if(2*x<t&&t<=3*x)
				B+=3*x;
			else if(3*x<t)
				B+=x;
			t=(t-1)%x+1;
		}
		if(n%3==1)
			cout<<A<<'\n';
		else if(n%3==2)
			cout<<B<<'\n';
		else
			cout<<(A^B)<<'\n';
	}
	return 0;
}