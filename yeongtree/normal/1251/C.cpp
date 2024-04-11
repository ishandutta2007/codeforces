#include <iostream>
#include <vector>
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
        vector<int> ev, od;
        for(auto i : s)
        {
            int j = i - '0';
            if(j & 1) od.push_back(j);
            else ev.push_back(j);
        }

        int evp = 0, odp = 0;
        while(evp != ev.size() || odp != od.size())
        {
            if(evp == ev.size() || (odp != od.size() && ev[evp] > od[odp]))
            {
                cout << (char)(od[odp++] + '0');
            }
            else cout << (char)(ev[evp++] + '0');
        }
        cout << '\n';
    }
    return 0;
}