#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n;
char s[N];


void solve()
{
    scanf("%d", &n);
    scanf("%s", s);
    vector<string> ans;
    for (int i = 0; i < n; i++)
    {
        if (i && s[i - 1] < s[i])
            break;
        if (!i || s[i] != s[i - 1])
        {
            string t = "";
            for (int j = 0; j <= i; j++)
                t += s[j];
            for (int j = i; j >= 0; j--)
                t += s[j];
            ans.push_back(t);
        }
        if (i + 1 == n || s[i] != s[i + 1])
        {
            string t = "";
            for (int j = 0; j <= i; j++)
                t += s[j];
            for (int j = i; j >= 0; j--)
                t += s[j];
            ans.push_back(t);
        }
    }
    sort(ans.begin(), ans.end());
    string t = ans[0];
    for (auto x : t)
        printf("%c", x);
    printf("\n");
}
int main()
{
    int t = 1;
    scanf("%d", &t);
    while (t--)
        solve();
}