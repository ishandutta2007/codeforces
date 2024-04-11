#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; long long k; cin >> n >> k;
    string s; cin >> s;
    for(auto c : s) k -= 1ll << (c - 'a');
    k += 1ll << (s[n - 2] - 'a' + 1);
    k = -k;
    if(k < 0 || k & 1) { cout << "No"; return 0; }
    k >>= 1;

    int cnt[26]{};
    for(int i = 0; i < n - 2; ++i) cnt[s[i] - 'a']++;
    for(int i = 25; i >= 0; --i) for(int j = 0; j < cnt[i]; ++j) if(k >= (1ll << i)) k -= 1ll << i;
    if(k == 0) cout << "Yes";
    else cout << "No";
    return 0;
}