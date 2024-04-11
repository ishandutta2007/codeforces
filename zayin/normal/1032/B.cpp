#include<bits/stdc++.h>
#define maxn 105
using namespace std;

int n;
char s[maxn];

int main()
{
	scanf("%s",s);
	n=strlen(s);
	for (int r=1;r<=5;++r)
	{
		int c=(n-1)/r+1;
		if (c>20)	continue;
		cout<<r<<" "<<c<<endl;
		if (r*c==n)
			for (int i=0;i<r;++i)
			{
				for (int j=0;j<c;++j)
					putchar(s[i*c+j]);
				putchar('\n');
			}
		else
		{
			int p=0;
			for (int i=0;i<r;++i)
			{
				int f=i<(n%r);
				if (f)
					putchar(s[p++]);
				else
					putchar('*');
				for (int j=1;j<c;++j)
					putchar(s[p++]);
				putchar('\n');
			}
		}
		break;
	}
	return 0;
}