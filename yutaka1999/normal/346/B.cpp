#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#define SIZE 105
#define ALP 26

using namespace std;

char s1[SIZE],s2[SIZE],vr[SIZE];
string dp[SIZE][SIZE][SIZE];
int nxt[SIZE][ALP];

void ch(string &s,string &t)
{
	if(s.size()<t.size()) s=t;
}
int main()
{
	scanf("%s",&s1);
	scanf("%s",&s2);
	scanf("%s",&vr);
	int z1=strlen(s1),z2=strlen(s2),z3=strlen(vr);
	for(int i=0;i<z3;i++)
	{
		for(int j=0;j<ALP;j++)
		{
			string s="";
			for(int k=0;k<i;k++) s+=vr[k];
			s+='A'+j;
			nxt[i][j]=0;
			for(int k=1;k<=i+1;k++)
			{
				bool ok=true;
				for(int p=0;p<k;p++) if(s[i+1-k+p]!=vr[p]) ok=false;
				if(ok) nxt[i][j]=k;
			}
		}
	}
	string ret="";
	for(int i=0;i<=z1;i++)
	{
		for(int j=0;j<=z2;j++)
		{
			for(int k=0;k<z3;k++)
			{
				if(i==z1&&j==z2) ch(ret,dp[i][j][k]);
				if(i+1<=z1) ch(dp[i+1][j][k],dp[i][j][k]);
				if(j+1<=z2) ch(dp[i][j+1][k],dp[i][j][k]);
				if(i<z1&&j<z2&&s1[i]==s2[j])
				{
					if(nxt[k][s1[i]-'A']!=z3)
					{
						string s=dp[i][j][k];s+=s1[i];
						ch(dp[i+1][j+1][nxt[k][s1[i]-'A']],s);
					}
				}
			}
		}
	}
	if(ret!="") printf("%s\n",ret.c_str());
	else puts("0");
	return 0;
}