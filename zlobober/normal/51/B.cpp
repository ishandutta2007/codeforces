#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
using namespace std;

const int N = 10000;

char S[N];
int pt = 0;

stack<int> st;
int ans[N];

int main()
{
	//freopen("b.in", "r", stdin);
	while (!cin.eof())
	{
		cin >> S + pt;
		pt += strlen(S + pt);
	}
	//cout << S;
	memset(ans, 0, sizeof(ans));
	int cur = 0;
	for (int i = 0; i < strlen(S); i++)
	{
		if (S[i] == 'a')
			st.push(cur++);
		else if (S[i] == 'd')
			ans[st.top()]++;
		else if (S[i] == '/')
		{
			if (S[i + 2] == 'a')
				st.pop();
			i += 2;
		}
	}
	sort(ans, ans + cur);
	for (int i = 0; i < cur; i++)
		cout << ans[i] << ' ';
}