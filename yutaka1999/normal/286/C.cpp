#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#define SIZE 1000005

using namespace std;

vector <int> vx;
int in[SIZE];
bool mn[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&in[i]);
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int a;
		scanf("%d",&a);a--;
		mn[a]=true;
	}
	stack <int> st;
	for(int i=n-1;i>=0;i--)
	{
		if(mn[i]||st.empty()||st.top()!=in[i])
		{
			mn[i]=true;
			st.push(in[i]);
		}
		else st.pop();
	}
	if(!st.empty())
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	for(int i=0;i<n;i++)
	{
		if(i!=0) printf(" ");
		printf("%d",mn[i]?-in[i]:in[i]);
	}puts("");
	return 0;
}