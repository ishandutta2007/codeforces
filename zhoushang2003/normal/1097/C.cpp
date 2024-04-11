#include<iostream>
using namespace std;
const int M=5e5+1;
string s;
int n,x,y,a[M],b[M],A;
int main()
{
	cin>>n;
	while(n--&&cin>>s)
	{
		x=y=0;
		for(int i=0;i<s.size();i++)
			if(s[i]=='(')
				x++;
			else if(s[i]==')'&&x>0)
				x--;
			else
				y++;
		if(x>0&&y>0)
			continue;
		if(x>0)
			a[x]++;
		else if(y>0)
			b[y]++;
		else
			A++;
	}
	A/=2;
	for(int i=1;i<M;i++)
		A+=min(a[i],b[i]);
	cout<<A;
	return 0;
}