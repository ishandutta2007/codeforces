#include<bits/stdc++.h>
using namespace std;
int main()
{
	char ch[110]={};
	gets(ch+1);
	int l=strlen(ch+1);
	set<char> s;
	for(int i=1;i<=l;++i)
		s.insert(ch[i]);
	puts(s.size()%2 ? "IGNORE HIM!" : "CHAT WITH HER!");
}