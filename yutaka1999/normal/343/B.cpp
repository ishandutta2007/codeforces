#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <cstring>
#define SIZE 100005

using namespace std;

stack <char> st;
char str[SIZE];

int main()
{
	scanf("%s",&str);
	int sz=strlen(str);
	for(int i=0;i<sz;i++)
	{
		if(st.empty()||st.top()!=str[i]) st.push(str[i]);
		else st.pop();
	}
	if(st.empty()) puts("Yes");
	else puts("No");
	return 0;
}