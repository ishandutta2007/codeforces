#include<bits/stdc++.h>
using namespace std;

string a,b;

int T;

int main()
{
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		cin>>a>>b;
		int s=0;
		int last=0;
		int ok=1;
		for(int i=0;i<n;i++)
		{
			s+=a[i]-'0'?1:-1;
			if(!s)
			{
				int same=a[last]==b[last];
				for(int j=last+1;j<=i;j++)
					ok&=(a[j]==b[j])==same;
				last=i+1;
			}
		}
		if(s)
		{
			for(int j=last;j<n;j++)
				ok&=(a[j]==b[j]);
		}
		puts(ok?"YES":"NO");
	}
}