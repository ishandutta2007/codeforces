#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#define SIZE 100005
#define MOD 1000000007

using namespace std;
typedef long long int ll;

ll nxt[12],vl[12];
char str[SIZE],gen[SIZE];
vector <string> vs;
int st[SIZE];

int main()
{
	scanf("%s",&gen);
	int len=strlen(gen);
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		scanf("\n");
		char c;
		scanf("%c",&c);
		scanf("%s",&str);
		st[i]=c-'0';
		string s="";
		int l=strlen(str);
		for(int j=2;j<l;j++) s+=str[j];
		vs.push_back(s);
	}
	for(int i=0;i<10;i++)
	{
		nxt[i]=10;
		vl[i]=i;
	}
	for(int i=q-1;i>=0;i--)
	{
		string s=vs[i];
		ll nt=1,v=0;
		for(int j=((int) s.size())-1;j>=0;j--)
		{
			int d=s[j]-'0';
			v+=nt*vl[d]%MOD;
			nt*=nxt[d];
			v%=MOD;
			nt%=MOD;
		}
		nxt[st[i]]=nt;
		vl[st[i]]=v;
	}
	ll v=0,nt=1;
	for(int j=len-1;j>=0;j--)
	{
		int d=gen[j]-'0';
		v+=nt*vl[d]%MOD;
		nt*=nxt[d];
		v%=MOD;
		nt%=MOD;
	}
	printf("%I64d\n",v);
	return 0;
}