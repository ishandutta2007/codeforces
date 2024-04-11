#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define SIZE 100005

using namespace std;

int sum[26];
int sp[26];
char str[SIZE],p[SIZE];

bool ok()
{
	for(int i=0;i<26;i++)
	{
		if(sum[i]>sp[i])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	scanf("%s",&str);
	scanf("%s",&p);
	int sz=strlen(p);
	for(int i=0;i<sz;i++) sp[p[i]-'a']++;
	int len=strlen(str);
	if(len<sz)
	{
		puts("0");
		return 0;
	}
	for(int i=0;i<sz;i++) sum[str[i]-'a']++;
	int ret=0;
	ret+=ok();
	for(int i=sz;i<len;i++)
	{
		if(str[i]!='?') sum[str[i]-'a']++;
		if(str[i-sz]!='?') sum[str[i-sz]-'a']--;
		ret+=ok();
	}
	printf("%d\n",ret);
	return 0;
}