#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <string>
#define SIZE 100005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

char str[SIZE];

int main()
{
	scanf("%s",&str);
	string NO=":(";//)
	int n=strlen(str);
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(str[i]!='a') cnt++;
	}
	if(cnt%2==1)
	{
		printf("%s\n",NO.c_str());
		return 0;
	}
	cnt/=2;
	for(int i=0;i<cnt;i++)
	{
		if(str[n-i-1]=='a')
		{
			printf("%s\n",NO.c_str());
			return 0;
		}
	}
	string S="";
	for(int i=0;i<n;i++)
	{
		if(str[i]!='a')
		{
			S+=str[i];
		}
	}
	for(int i=0;i<cnt;i++)
	{
		if(S[i]!=S[i+cnt])
		{
			printf("%s\n",NO.c_str());
			return 0;
		}
	}
	for(int i=0;i<n-cnt;i++) printf("%c",str[i]);
	puts("");
	return 0;
}