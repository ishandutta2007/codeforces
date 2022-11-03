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

void solve(int tc)
{
    int n;
    cin >> n;
    vector<vector<int>> ve;
    stack<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (ve.empty())
        {
            assert(x == 1);
            ve.push_back({1});
            st.push({1});
        }
        else if (x == 1)
        {
            auto xx = ve.back();
            xx.push_back(1);
            ve.push_back(xx);
            st.push(xx);
        }
        else
        {
            while (!st.empty())
            {
                if (st.top().back() == x - 1)
                {
                    auto xx = st.top();
                    st.pop();
                    xx.pop_back();
                    xx.push_back(x);
                    st.push(xx);
                    ve.push_back(xx);
                    break;
                }
                st.pop();
            }
        }
        auto xx = ve.back();
        for (int j = 0; j < sz(xx); j++)
        {
            if (j > 0)
                cout << '.';
            cout << xx[j];
        }
        cout << '\n';
    }
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