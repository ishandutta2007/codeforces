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
        vector<char> V(n);
        for(auto &i : V) cin >> i;
        sort(V.begin(), V.end());
        for(auto i : V) cout << i;
        cout << '\n';
    }
}