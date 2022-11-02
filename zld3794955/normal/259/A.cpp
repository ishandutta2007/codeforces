#include<bits/stdc++.h>
using namespace std;
int main()
{
	char ch[20]={};
	for(int i=1;i<=8;++i)
	{
		gets(ch+1);
		for(int j=1;j<8;++j)
			if(ch[j]==ch[j+1])
			{
				puts("NO");
				return 0;
			}
	}
	puts("YES");
	return 0;
}