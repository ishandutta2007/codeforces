#include<bits/stdc++.h>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const int N=100100;
const int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
char ch[N]={};
int main()
{
	gets(ch+1);
	int l=strlen(ch+1);
	map<int,int> bucket;
	for(int i=3;i<=l-7;++i)
		if(ch[i]=='-' && ch[i+3]=='-')
		{
			bool flag=isdigit(ch[i-2]);
			flag&=isdigit(ch[i-1]);
			flag&=isdigit(ch[i+1]);
			flag&=isdigit(ch[i+2]);
			flag&=isdigit(ch[i+4]);
			flag&=isdigit(ch[i+5]);
			flag&=isdigit(ch[i+6]);
			flag&=isdigit(ch[i+7]);
			if(!flag)
				continue;
			int d=(ch[i-2]-'0')*10+ch[i-1]-'0';
			int m=(ch[i+1]-'0')*10+ch[i+2]-'0';
			int y=(((ch[i+4]-'0')*10+(ch[i+5]-'0'))*10+ch[i+6]-'0')*10+ch[i+7]-'0';
			if(2013<=y && y<=2015 && 1<=m && m<=12 && 1<=d && d<=month[m])
				++bucket[d*1000000+m*10000+y];
		}
	int d1=0,m1=0,y1=0,t=0;
	for(auto p:bucket)
		if(p.second>t)
			d1=p.first/1000000,m1=p.first%1000000/10000,y1=p.first%10000,t=p.second;
	printf("%02d-%02d-%d\n",d1,m1,y1);
	return 0;
}