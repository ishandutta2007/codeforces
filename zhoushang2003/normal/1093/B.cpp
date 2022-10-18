#include<iostream>
#include<algorithm>
using namespace std;
const int N=1000;
bool v;
int t,n,a[N],x,y;
string s;
int main()
{
	cin>>t;
	while(t--&&cin>>s)
	{
		n=s.size();
		for(int i=0;i<n;i++)
			a[i]=s[i];
		sort(a,a+n);
		x=0,y=n-1;
		v=false;
		while(x<y)
			if(a[x++]!=a[y--])
				v=true;
		if(!v)
			cout<<-1<<endl;
		else
		{
			for(int i=0;i<n;i++)
				cout<<char(a[i]);
			cout<<endl;
		}
	}
	return 0;
}