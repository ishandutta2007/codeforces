#include<bits/stdc++.h>
using namespace std;
const int L=110;
char ch[L]={};
int n;
int main()
{	
	gets(ch+1);
	n=strlen(ch+1);
	for(int i=1;i<=n;++i)
		if(ch[i]=='0' || ch[i]=='8')
		{
			puts("YES");
			putchar(ch[i]);
			putchar('\n');
			return 0;
		}
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			if(((ch[i]-'0')*10+(ch[j]-'0'))%8==0)
			{
				puts("YES");
				putchar(ch[i]);
				putchar(ch[j]);
				putchar('\n');
				return 0;
			}
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			for(int k=j+1;k<=n;++k)
				if(((ch[i]-'0')*100+(ch[j]-'0')*10+(ch[k]-'0'))%8==0)
				{
					puts("YES");
					putchar(ch[i]);
					putchar(ch[j]);
					putchar(ch[k]);
					putchar('\n');
					return 0;
				}
	puts("NO");
	return 0;
}