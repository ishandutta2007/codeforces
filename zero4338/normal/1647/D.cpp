#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
int T;
int x,d;
bool isprime(int x)
{
	for(int i=2;i*i<=x;i++)if(x%i==0)return 0;
	return 1;
}
bool judge(int x,int d)
{
	vector<pair<int,int>>divisor;
	for(int i=2;i*i<=x;i++)
	{
		if(x%i==0)
		{
			divisor.push_back({i,0});
			while(x%i==0)divisor.back().second++,x/=i;
		}
	}
	if(x!=1)divisor.push_back({x,1});
	if(divisor.size()>=2)return 1;
	int cnt=0;
	while(d%divisor[0].first==0)cnt++,d/=divisor[0].first;
	if((divisor[0].second+1)/2>=cnt)return 0;
	return 1;
}
int main()
{
	T=read();
	while(T--)
	{
		x=read();d=read();int cnt=0;
		while(x%d==0)x/=d,cnt++;
		if(cnt==1)puts("NO");
		else if(!isprime(x))puts("YES");
		else if(!isprime(d))
		{
			if(cnt>=4)puts("YES");
			else if(cnt==3)
			{
				x=__gcd(x,d);
				if(judge(x*d,d))puts("YES");
				else puts("NO");
			}
			else puts("NO");
		}
		else puts("NO");
	}
	return 0;
}