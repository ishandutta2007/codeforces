#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,n,x,y,l,r=1e18;
string s;
bool C(long long k)
{
	a=b=0,a+=k/n*x,b+=k/n*y;
	for(int i=0;i<k%n;i++)
		if(s[i]=='U')
			b++;
		else if(s[i]=='D')
			b--;
		else if(s[i]=='L')
			a--;
		else
			a++;
	if(k>=abs(c-a)+abs(d-b))
		return true;
	return false;
}
int main()
{
	cin>>a>>b>>c>>d>>n>>s;
	c-=a,d-=b;
	for(int i=0;i<n;i++)
		if(s[i]=='U')
			y++;
		else if(s[i]=='D')
			y--;
		else if(s[i]=='L')
			x--;
		else
			x++;
	while(l<r)
		if(C((l+r)/2))
			r=(l+r)/2;
		else
			l=(l+r)/2+1;
	if(C(l))
		cout<<l;
	else
		cout<<-1;
	return 0;
}