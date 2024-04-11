#include<bits/stdc++.h>
using namespace std;
const int N=3e5+1;
bool b;
int n,a[N],A;
string s;
int main()
{
	cin>>s;
	n=s.size();
	for(int i=1;i<=n;i++)
		a[i]=s[i-1]-'0';
	for(int i=1;i<=n;i++)
		for(int j=i;j<=min(i+10,n);j++)
		{
			b=true;
			for(int k=i;k<=j;k++)
				for(int l=k+1;l<=j;l++)
					if(2*l-k<=j&&a[k]==a[l]&&a[l]==a[2*l-k])
						b=false;
			if(b)
				A--;
		}
	cout<<(long long)n*(n+1)/2+A;
	return 0;
}