#include<iostream>
#include<algorithm>
using namespace std;
const int N=2e5;
int n,a[N],s[N],c,x,y,A;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n),s[0]=1;
	for(int i=1;i<n;i++)
		if(a[i]!=a[i-1])
			s[++c]++;
		else
			s[c]++;
	c++;
	sort(s,s+c);
	for(int i=0;i<c;i++)
		for(int j=1;j<=s[i];j++)
		{
			x=j,y=x;
			for(int k=i+1;k<c;k++)
				if(2*x<=s[k])
					x*=2,y+=x;
				else
					break;
			A=max(A,y);
		}
	cout<<A;
	return 0;
}