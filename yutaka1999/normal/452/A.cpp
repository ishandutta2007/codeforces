#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

string str[8]={"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
char in[10];

int main()
{
	int n;
	scanf("%d",&n);
	scanf("%s",&in);
	string s=in;
	for(int i=0;i<8;i++)
	{
		if(s.size()==str[i].size())
		{
			bool ok=true;
			for(int j=0;j<s.size();j++)
			{
				if(s[j]!='.'&&s[j]!=str[i][j])
				{
					ok=false;
					break;
				}
			}
			if(ok)
			{
				printf("%s\n",str[i].c_str());
				return 0;
			}
		}
	}
	return 0;
}