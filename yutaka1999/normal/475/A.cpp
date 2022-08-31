#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int in[20][20];

int main()
{
	int k;
	scanf("%d",&k);
	memset(in,0,sizeof(in));
	int now=0,t=0;
	while(k>0)
	{
		if(t==2&&now>0)
		{
			t++;
			continue;
		}
		k--;
		//printf("%d %d\n",t,now);
		in[t][now]=1;
		t++;
		if(t==4)
		{
			t=0;
			now++;
		}
	}
	for(int i=0;i<26;i++)
	{
		if(i==0||i==25) printf("+");
		else printf("-");
	}puts("");
	for(int i=0;i<27;i++)
	{
		if(i==0) printf("|");
		else if(i==23) printf("|");
		else if(i==24) printf("D");
		else if(i==25) printf("|");//(
		else if(i==26) printf(")");
		else
		{
			if(i%2==0) printf(".");
			else if(in[0][(i-1)/2]==1) printf("O");
			else printf("#");
		}
	}
	puts("");
	for(int i=0;i<26;i++)
	{
		if(i==0) printf("|");
		else if(i==23) printf("|");
		else if(i==24) printf(".");
		else if(i==25) printf("|");
		else
		{
			if(i%2==0) printf(".");
			else if(in[1][(i-1)/2]==1) printf("O");
			else printf("#");
		}
	}
	puts("");
	for(int i=0;i<26;i++)
	{
		if(i==0) printf("|");
		else if(i==25) printf("|");
		else if(i==1)
		{
			if(in[2][0]==1) printf("O");
			else printf("#");
		}
		else printf(".");
	}
	puts("");
	for(int i=0;i<27;i++)
	{
		if(i==0) printf("|");
		else if(i==23) printf("|");//(
		else if(i==24) printf(".");
		else if(i==25) printf("|");
		else if(i==26) printf(")");
		else
		{
			if(i%2==0) printf(".");
			else if(in[3][(i-1)/2]==1) printf("O");
			else printf("#");
		}
}puts("");
	for(int i=0;i<26;i++)
	{
		if(i==0||i==25) printf("+");
		else printf("-");
	}puts("");
	return 0;
}