#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#define pii pair<int, int>
#define piii pair<int, pii>
#define pll pair<long long, long long>
#define plll pair<long long, pll>
#define tiii tuple<int, int, int>
#define tiiii tuple<int, int, int, int>
#define ff first
#define ss second
#define ee ss.ff
#define rr ss.ss
#define DEBUG
const int INF = (int)1e9 + 7;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        string s; cin >> s;
        int n = s.size();
        string t(n, ' ');
        int A[n];
        for(int i = 0; i < n; ++i) A[i] = s[i] - 'a';

        int C[26]{};
        for(int i = 0; i < n; ++i) ++C[s[i] - 'a'];

        int mn = n + 1, mni = -1;
        for(int i = 0; i < 26; ++i) if(mn > C[i] && C[i]) mn = C[i], mni = i;

        if(mn == n)
        {
            cout << s << '\n';
        }
        else if(mn == 1)
        {
            for(int i = 0; i < n; ++i) if(A[i] == mni)
            {
                swap(A[0], A[i]);
                break;
            }
            sort(A + 1, A + n);
            for(int i = 0; i < n; ++i) cout << char(A[i] + 'a');
            cout << '\n';
        }
        else
        {
            int a = -1, b = -1, c = -1;
            for(int i = 0; i < 26; ++i) if(C[i]) { a = i; break; }
            for(int i = 0; i < 26; ++i) if(C[i] && i != a) { b = i; break; }
            for(int i = 0; i < 26; ++i) if(C[i] && i != a && i != b) { c = i; break; }

            if(C[a] <= n / 2 + 1)
            {
                t[0] = t[1] = 'a' + a;
                for(int i = 2; i < C[a]; ++i) t[i * 2 - 1] = 'a' + a;

                int pt = 0;
                for(int i = 0; i < 26; ++i) if(i != a)
                {
                    for(int j = 0; j < C[i]; ++j)
                    {
                        while(t[pt] != ' ') ++pt;
                        t[pt++] = 'a' + i;
                    }
                }
            }

            else if(c != -1)
            {
                t[0] = 'a' + a;
                t[1] = 'a' + b;
                t[C[a] + 1] = 'a' + c;
                --C[a];
                --C[b];
                --C[c];

                int pt = 0;
                for(int i = 0; i < 26; ++i)
                {
                    for(int j = 0; j < C[i]; ++j)
                    {
                        while(t[pt] != ' ') ++pt;
                        t[pt++] = 'a' + i;
                    }
                }
            }

            else
            {
                t[0] = 'a' + a;
                for(int i = 1; i <= C[b]; ++i) t[i] = 'a' + b;
                for(int i = C[b] + 1; i < n; ++i) t[i] = 'a' + a;
            }

            cout << t << '\n';
        }
    }
}