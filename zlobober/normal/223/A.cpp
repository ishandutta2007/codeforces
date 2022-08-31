#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>
#include <string>
#include <list>
using namespace std;

const int N = 200500;
char buf[N];

list<pair<bool, int> > L;

inline bool match(char a, char b)
{
    return (a == '[' && b == ']') || (a == '(' && b == ')');
}

/*struct info
{
    int l, r;
};

void call(list<pair<int, int> >::iterator it)
{
    list<pair<int, int> >::iterator th = it;
    if (
}*/

stack<pair<int, char> > S;
int cnt[N];

int main()
{
    gets(buf);

    int n = strlen(buf);
    for (int i = 0; i < n; i++)
        cnt[i + 1] = cnt[i] + (buf[i] == '[');
    pair<int, pair<int, int> > ans(0, make_pair(0, 0));
    S.push(make_pair(-1, 0));
    for (int i = 0; i <= n; i++)
    {
        if (buf[i] == '(' || buf[i] == '[')
            S.push(make_pair(i, buf[i]));
        else
        {
            if (!S.empty() && match(S.top().second, buf[i]))
            {
                S.pop();
                int l = S.top().first + 1;
                int r = i;
                ans = max(ans, make_pair(cnt[r + 1] - cnt[l], make_pair(l, r + 1)));
            }
            else
            {
                int l = S.top().first + 1;
                int r = i - 1;
                while (!S.empty())
                    S.pop();
                S.push(make_pair(i, 0));
                ans = max(ans, make_pair(cnt[r + 1] - cnt[l], make_pair(l, r + 1)));
            }
        }
    }
    printf("%d\n%s", ans.first, string(buf + ans.second.first, buf + ans.second.second).c_str());
    //printf("%d\n", ans.first);
}