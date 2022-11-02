#include<iostream>
#include<cstdio>
#include<cctype>
#include<cstring>
using namespace std;
const int L=110;
int main()
{
	char ch[L]={};
	gets(ch+1);
	int l=strlen(ch+1);
	if(l<5)
		puts("Too weak");
	else
	{
		int s=0;
		for(int i=1;i<=l;++i)
		{
			if(isdigit(ch[i]))
				s|=1;
			if(islower(ch[i]))
				s|=2;
			if(isupper(ch[i]))
				s|=4;
		}
		if(s!=7)
			puts("Too weak");
		else
			puts("Correct");
	}
	return 0;
}