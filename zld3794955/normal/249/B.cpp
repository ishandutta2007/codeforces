#include<bits/stdc++.h>
using namespace std;
const int N=500050;
int n,t,th=0;
char ch[N]={};
bool check(int k)
{
	int end=0;
	for(int i=1,a=0,b=0;i<=n && !end;++i)
	{
		a+=(ch[i]=='S');
		b+=(ch[i]=='H');
		if(b==th && a+k>=b)
			end=i;
	}
	if(!end)
		return false;
	int mins=end*2-1,s=0,last=0,h=0;
	for(int i=1;i<=end;++i)
	{
		++s;
		if(ch[i]=='H')
		{
			if(!k && !h)
			{
				last=i;
				mins=min(mins,s+(end-i)*2);
				++h;
			}
			else
				!h ? --k : ++h;
		}
		if(ch[i]=='S' && (++k)==h)
		{
			s+=(i-last)*2;
			last=k=h=0;
		}
	}
	return min(mins,s)<=t;
}
int main()
{
	scanf("%d%d\n%s",&n,&t,ch+1);
	for(int i=1;i<=n;++i)
		th+=ch[i]=='H';
	int l=0,r=th+1;
	for(int mid=(l+r)>>1; l!=r; mid=(l+r)>>1)
		check(mid) ? r=mid : l=mid+1;
	printf("%d\n",r==th+1 ? -1 : l);
	return 0;
}