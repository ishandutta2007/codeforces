#include <iostream>
#include <string>
#include <vector>
#include <map>
#define ff first
#define ss second

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    multimap<pair<int, int>, string> mm;
    for(int i = 0; i < n; ++i)
    {
        string s; cin >> s;
        int num = 0, ev;
        for(char c : s)
        {
            if(c == 'a') {++num; ev = 0;}
            if(c == 'e') {++num; ev = 1;}
            if(c == 'i') {++num; ev = 2;}
            if(c == 'o') {++num; ev = 3;}
            if(c == 'u') {++num; ev = 4;}
        }
        mm.emplace(pair<int, int>(num, ev), s);
    }

    vector<pair<string, string>> vp;
    vector<pair<string, string>> np;

    auto prev = mm.begin();
    bool flag = false;
    for(auto it = mm.begin(); it != mm.end(); flag ? ++it : it)
    {
        if(flag && prev->ff == it->ff)
        {
            vp.emplace_back(prev->ss, it->ss);
            auto __it = it; ++__it;
            mm.erase(prev); mm.erase(it); it = __it;
            flag = false;
        }
        else
        {
            prev = it;
            flag = true;
        }
    }

    prev = mm.begin();
    flag = false;
    for(auto it = mm.begin(); it != mm.end(); flag ? ++it : it)
    {
        if(flag && prev->ff.ff == it->ff.ff)
        {
            np.emplace_back(prev->ss, it->ss);
            auto __it = it; ++__it;
            mm.erase(prev); mm.erase(it); it = __it;
            flag = false;
        }
        else
        {
            prev = it;
            flag = true;
        }
    }

    vector<pair<pair<string, string>, pair<string, string>>> ans;
    while(!vp.empty())
    {
        auto i = vp.back(); vp.pop_back();
        if(!np.empty())
        {
            ans.emplace_back(np.back(), i);
            np.pop_back();
        }
        else if(!vp.empty())
        {
            ans.emplace_back(vp.back(), i);
            vp.pop_back();
        }
    }

    cout << ans.size() << '\n';
    for(auto &i : ans)
    {
        cout << i.ff.ff << ' ' << i.ss.ff << '\n' << i.ff.ss << ' ' << i.ss.ss << '\n';
    }

    return 0;
}