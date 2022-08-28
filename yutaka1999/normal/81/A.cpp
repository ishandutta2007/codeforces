#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <cstring>
#include <vector>
#define SIZE 200005

using namespace std;
typedef pair <int,int> P;

char str[SIZE];
vector <int> vec;

int main()
{
	scanf("%s",&str);
	int sz=strlen(str);
	stack <P> st;
	for(int i=0;i<sz;i++)
	{
		int a=str[i]-'a';
		if(st.empty()||st.top().first!=a) st.push(P(a,1));
		else st.pop();
	}
	while(!st.empty())
	{
		vec.push_back(st.top().first);
		st.pop();
	}
	for(int i=((int) vec.size())-1;i>=0;i--)
	{
		printf("%c",'a'+vec[i]);
	}
	puts("");
	return 0;
}