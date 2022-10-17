#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        string s; cin >> s;
        int pr = 0;
        while(pr * 2 + 2 <= s.size() && s[pr] == s[(int)s.size() - pr - 1]) ++pr;

        string t;
        for(int i = pr; i < (int)s.size() - pr; ++i) t += s[i];
        string p = t;
        reverse(p.begin(), p.end());

        int N = t.size();
        int ft[N]{}, fp[N]{};
        int mt = 0;
        for(int i = 1; i < N; ++i)
        {
            while(mt > 0 && t[mt] != t[i]) mt = ft[mt - 1];
            if(t[mt] == t[i]) ++mt;
            ft[i] = mt;
        }
        mt = 0;
        for(int i = 1; i < N; ++i)
        {
            while(mt > 0 && p[mt] != p[i]) mt = fp[mt - 1];
            if(p[mt] == p[i]) ++mt;
            fp[i] = mt;
        }

        mt = 0;
        for(int i = 0; i < N; ++i)
        {
            while(mt > 0 && p[i] != t[mt]) mt = ft[mt - 1];
            if(p[i] == t[mt]) ++mt;
        }
        int f = mt;
        mt = 0;
        for(int i = 0; i < N; ++i)
        {
            while(mt > 0 && t[i] != p[mt]) mt = fp[mt - 1];
            if(t[i] == p[mt]) ++mt;
        }
        int b = mt;

        if(f > b)
        {
            for(int i = 0; i < pr; ++i) cout << s[i];
            for(int i = 0; i < f; ++i) cout << t[i];
            for(int i = pr - 1; i >= 0; --i) cout << s[i];
        }
        else
        {
            for(int i = 0; i < pr; ++i) cout << s[i];
            for(int i = 0; i < b; ++i) cout << p[i];
            for(int i = pr - 1; i >= 0; --i) cout << s[i];
        }
        cout << '\n';
    }
}