#include <iostream>
#include <utility>
#define pii pair<int, int>
#define piii pair<pii, int>
#define pll pair<long long, long long>
#define ff first
#define ss second
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        int arr[n]; for(auto &i : arr) cin >> i;
        int m; cin >> m;
        pii stt[m]; for(auto &i : stt) cin >> i.ff >> i.ss;
        sort(stt, stt + m, greater<pii>());
        vector<pii> rel;
        rel.push_back(stt[0]);
        for(int i = 0; i < m; ++i)
            if(stt[i].ss > rel.back().ss) rel.push_back(stt[i]);
        reverse(rel.begin(), rel.end());

        int pt = 0;
        int cnt = 0;
        while(pt < n)
        {
            int __pt = pt - 1;
            int pos = 0;
            while(pt < n)
            {
                pos = max(pos, lower_bound(rel.begin(), rel.end(), pii{arr[pt], 0}) - rel.begin());
                if(pos == rel.size()) {cnt = -1; break;}
                if(rel[pos].ss < pt - __pt) break;
                ++pt;
            }

            if(cnt == -1) break;
            ++cnt;
        }

        cout << cnt << '\n';
    }
}