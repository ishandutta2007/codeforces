#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    int n = s.size();
    int arr[n];

    int cnt = 0, mx = 0;
    for(int i = n - 1; i >= 0; --i)
    {
        if(cnt - mx < 0 && s[i] == '1') arr[i] = 1;
        else arr[i] = 0;

        if(s[i] == '1') ++cnt;
        else --cnt;

        mx = max(mx, cnt);
    }

    for(auto i : arr) cout << i;
    return 0;
}