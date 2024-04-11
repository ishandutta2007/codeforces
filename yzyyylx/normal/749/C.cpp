#include<iostream>
#include<cstdio>
using namespace std;

int n,a,b,ca,cb;
bool now,cur;
string str[2];

int main()
{
	int i,j;
	cin>>n>>str[0];
	for(i=0;i<str[0].size();i++) str[0][i]=='D'?ca++:cb++;
	cur=1;
	for(;ca&&cb;)
	{
		swap(now,cur);
		str[now]="";
		for(i=0;i<str[cur].size();i++)
		{
			if(str[cur][i]=='D')
			{
				if(a) a--,ca--;
				else b++,str[now]+='D';
			}
			else
			{
				if(b) b--,cb--;
				else a++,str[now]+='R';
			}
		}
	}
	if(ca) puts("D");
	else puts("R");
}