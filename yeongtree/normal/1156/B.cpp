#include <iostream>
#include <string>
#include <vector>
#define f first
#define s second

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        string s; cin >> s;

        int cnt[26]{};
        for(int i : s) ++cnt[i - 'a'];

        vector<pair<char, int> > rcnt;               /// f: , s: 
        for(int i = 0; i < 26; ++i)
            if(cnt[i]) rcnt.emplace_back(i + 'a', cnt[i]);

        if(rcnt.size() == 2 && rcnt[0].f + 1 == rcnt[1].f
           || rcnt.size() == 3 && rcnt[0].f + 1 == rcnt[1].f && rcnt[1].f + 1 == rcnt[2].f)
            cout << "No answer\n";

        else if(rcnt.size() == 3 && rcnt[0].f + 1 == rcnt[1].f)
        {
            int odr[3] = {0, 2, 1};
            for(int i = 0; i < 3; ++i)
                for(int j = 0; j < rcnt[odr[i]].s; ++j)
                    cout << rcnt[odr[i]].f;
            cout << '\n';
        }

        else
        {
            for(int i = 1; i < rcnt.size(); i += 2)
                for(int j = 0; j < rcnt[i].s; ++j)
                    cout << rcnt[i].f;

            for(int i = 0; i < rcnt.size(); i += 2)
                for(int j = 0; j < rcnt[i].s; ++j)
                    cout << rcnt[i].f;

            cout << '\n';
        }
    }
    return 0;
}