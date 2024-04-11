#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#define SIZE 500005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

char S[SIZE],T[SIZE];
int KMP[SIZE];

int main()
{
	scanf("%s",&S);
	scanf("%s",&T);
	int n=strlen(S),m=strlen(T);
	for(int i=0;i<m;i++)
	{
		if(i==0) KMP[i]=-1;
		else
		{
			int now=KMP[i-1];
			while(1)
			{
				if(T[now+1]==T[i])
				{
					now++;
					break;
				}
				else if(now==-1) break;
				now=KMP[now];
			}
			KMP[i]=now;
		}
	}
	int s0=0,s1=0,t0=0,t1=0;
	int z0=0,z1=0;
	for(int i=0;i<n;i++)
	{
		if(S[i]=='0') s0++;
		else s1++;
	}
	for(int i=0;i<m;i++)
	{
		if(T[i]=='0') t0++;
		else t1++;
	}
	string Z="";
	for(int i=KMP[m-1]+1;i<m;i++)
	{
		Z+=T[i];
		if(T[i]=='0') z0++;
		else z1++;
	}
	string ret="";
	if(s0>=t0&&s1>=t1)
	{
		ret+=T;
		s0-=t0,s1-=t1;
		int c=n;
		if(z0>0) c=min(c,s0/z0);
		if(z1>0) c=min(c,s1/z1);
		for(int i=0;i<c;i++) ret+=Z;
		s0-=c*z0,s1-=c*z1;
	}
	//printf("%d %d %s\n",s0,s1,ret.c_str());
	for(int i=0;i<s0;i++) ret+="0";
	for(int i=0;i<s1;i++) ret+="1";
	printf("%s\n",ret.c_str());
	return 0;
}