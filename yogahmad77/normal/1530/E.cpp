#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define reset(a, b) memset(a, b, sizeof a);
#define ALL(x) x.begin(), x.end()

template <typename T>
void cetak(T t)
{
    cout << t << ')' << endl;
}
template <typename T, typename... V>
void cetak(T t, V... v)
{
    cout << t;
    if (sizeof...(v))
        cout << ", ";
    cetak(v...);
}

#define debug(x...)               \
    cout << '(' << #x << ") = ("; \
    cetak(x)
#define sz(x) (int)(x.size())
#define lt(x) (int)(x.length())
typedef int (*func)(int, int);

const int mx = 1e5 + 10;
const int MOD = 1e9 + 7;

int kmp(const string &P)
{
    vector<int> pi(P.size(), 0);
    for (int i = 1, k = 0; i < P.size(); ++i)
    {
        while (k && P[k] != P[i])
            k = pi[k - 1];
        if (P[k] == P[i])
            ++k;
        pi[i] = k;
    }
    int ans = 0;
    for (int i = 1; i < P.size(); i++)
    {
        ans = max(ans, pi[i]);
    }
    return ans;
}

char cc(int a)
{
    return 'a' + a;
}

string cara_1(vector<int> cnt)
{
    vector<int> apa;
    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] > 0)
        {
            apa.push_back(i);
        }
    }

    if (sz(apa) == 2)
    {
        string ret = "";
        ret += cc(apa[0]);
        for (int i = 0; i < cnt[apa[1]]; i++)
        {
            ret += cc(apa[1]);
        }
        for (int i = 1; i < cnt[apa[0]]; i++)
        {
            ret += cc(apa[0]);
        }
        return ret;
    }

    string ret = "";
    ret += cc(apa[0]);
    ret += cc(apa[1]);

    for (int i = 1; i < cnt[apa[0]]; i++)
    {
        ret += cc(apa[0]);
    }
    ret += cc(apa[2]);

    for (int i = 1; i < cnt[apa[1]]; i++)
    {
        ret += cc(apa[1]);
    }

    for (int i = 1; i < cnt[apa[2]]; i++)
    {
        ret += cc(apa[2]);
    }

    for (int x = 3; x < sz(apa); x++)
    {
        for (int i = 0; i < cnt[apa[x]]; i++)
        {
            ret += cc(apa[x]);
        }
    }

    return ret;
}

string cara_2(int mini, int apa, vector<int> cnt)
{

    vector<char> bukan;
    string ret = "";
    for (int i = 0; i < 26; i++)
    {
        if (i == apa)
            continue;
        char xx = cc(i);
        for (int j = 0; j < cnt[i]; j++)
        {
            bukan.push_back(xx);
        }
    }
    char x = cc(apa);
    int idx = 0;

    ret += x;
    ret += x;
    for (int i = 2; i < mini; i++)
    {
        ret += bukan[idx++];
        ret += x;
    }

    while (idx < sz(bukan))
    {
        ret += bukan[idx++];
    }
    return ret;
}

void solve(int tc)
{
    vector<int> cnt(26, 0);
    int n;
    string ss;
    cin >> ss;
    n = sz(ss);
    int tot = 0;

    for (auto i : ss)
    {
        if (cnt[i - 'a'] == 0)
            tot += 1;
        cnt[i - 'a'] += 1;
    }

    if (tot == 1)
    {
        cout << ss << '\n';
        return;
    }

    int mini = 1e9;
    int apa = 0;

    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] == 0)
            continue;
        int sisa = n - cnt[i];
        if (cnt[i] <= sisa + 2)
        {
            mini = cnt[i];
            apa = i;
            break;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] == 1)
        {
            mini = 1;
            apa = i;
            break;
        }
    }

    if (mini == 1)
    {
        char x = cc(apa);
        cout << x;
        for (int i = 0; i < 26; i++)
        {
            if (i == apa)
                continue;

            for (int j = 0; j < cnt[i]; j++)
            {
                cout << cc(i);
            }
        }
        cout << '\n';
        return;
    }

    auto ans = cara_1(cnt);
    ans = min(ans, cara_2(mini, apa, cnt));
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    int tc = 0;
    while (t--)
    {
        solve(++tc);
    }
}