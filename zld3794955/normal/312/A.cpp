#include<bits/stdc++.h>
using namespace std;
int main()
{
	char ch[110]={};
	int T;
	gets(ch+1);
	sscanf(ch+1,"%d",&T);
	while(T--)
	{
		gets(ch+1);
		int l=strlen(ch+1);
		bool f1=ch[1]=='m' && ch[2]=='i' && ch[3]=='a' && ch[4]=='o' && ch[5]=='.';
		bool f2=ch[l-4]=='l' && ch[l-3]=='a' && ch[l-2]=='l' && ch[l-1]=='a' && ch[l]=='.';
		puts(f1^f2 ? f1 ? "Rainbow's" : "Freda's" : "OMG>.< I don't know!");
	}
	return 0;
}