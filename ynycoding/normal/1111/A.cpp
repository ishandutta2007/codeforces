#include <cstdio>
#include <cstring>
#define MAXN 1002
char s[MAXN], t[MAXN];
bool is(char c) { return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'; }
int main()
{
	scanf("%s%s", s, t);
	if(strlen(s)!=strlen(t)) return puts("No"), 0;
	for(int i=0; s[i]; ++i)
	{
		if(is(s[i])^is(t[i])) {  puts("No");  return 0;}
	}
	puts("Yes");
	return 0;
}