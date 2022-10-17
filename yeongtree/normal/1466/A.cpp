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
        int n; cin >> n;
        int ps[n];
        for(auto &i : ps) cin >> i;
        vector<int> V;
        for(int i = 0; i < n; ++i) for(int j = 0; j < i; ++j) if(ps[i] > ps[j]) V.push_back(ps[i] - ps[j]);
        auto prV = V;
        sort(prV.begin(), prV.end());
        prV.erase(unique(prV.begin(), prV.end()), prV.end());
        for(auto &i : V) i = lower_bound(prV.begin(), prV.end(), i) - prV.begin();
//        for(auto i : prV) cout << i << ' '; cout << endl;
        cout << (int)prV.size() << '\n';
    }
}