#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#define SIZE 100005

using namespace std;

char str[SIZE];

int main()
{
	scanf("%s",&str);
	string S=str;
	string T="heidi";
	int now=0;
	for(int i=0;i<S.size();i++)
	{
		if(now<T.size()&&T[now]==S[i]) now++;
	}
	if(now==T.size()) puts("YES");
	else puts("NO");
	return 0;
}