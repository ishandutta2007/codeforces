#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int sn[30],tn[30];
int rui[30][100005];
int wait[30];
vector <int> ch[30];

int toi(char c) {return c-'A';}
char toc(int c) {return 'A'+c;}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	string s,t;
	cin>>s>>t;
	for(int i=0;i<s.size();i++) sn[toi(s[i])]++;
	for(int i=0;i<t.size();i++) tn[toi(t[i])]++;
	for(int i=s.size()-1;i>=0;i--)
	{
		for(int j=0;j<30;j++)
		{
			rui[j][i]=rui[j][i+1];
		}rui[toi(s[i])][i]++;
	}
	int ret=0;
	for(int i=0;i<30;i++)
	{
		wait[i]=sn[i]-tn[i];
		ret+=abs(wait[i]);
	}
	printf("%d\n",ret/2);
	for(int i=0;i<s.size();i++)
	{
		char ans=s[i];
		int c=toi(s[i]);
		if(wait[c]>0)
		{
			bool up=false;
			for(int j=0;j<c;j++)
			{
				if(wait[j]<0)
				{
					ans=toc(j);
					wait[c]--;wait[j]++;
					up=true;
					break;
				}
			}
			if(!up&&rui[c][i]>wait[c]) ans=s[i];
			else if(!up)
			{
				for(int j=c;j<26;j++)
				{
					if(wait[j]<0)
					{
						ans=toc(j);
						wait[c]--;wait[j]++;
						break;
					}
				}
			}
		}
		printf("%c",ans);
	}printf("\n");
	return 0;
}