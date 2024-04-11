#include<bits/stdc++.h>
using namespace std;
const int L=200020;
char ch[L]={};
int l,t[3]={};
int main()
{
	cin>>l>>(ch+1);
	for(int i=1;i<=l;++i)
	{
		if(ch[i]=='A') ++t[0];
		if(ch[i]=='F') ++t[1];
		if(ch[i]=='I') ++t[2];
	}
	if(t[2]>1) puts("0");
	else if(t[2]==1) puts("1");
	else printf("%d\n",t[0]);
}