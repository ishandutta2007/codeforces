#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    int n = s.size();
    int arr[n];
    for(int i = 0; i < n; ++i)
    {
        int cnt = 0;
        bool flag = false;
        for(int j = i + 1; j < n; ++j)
        {
            if(s[j] == '0') --cnt;
            else ++cnt;
            if(cnt < 0) {flag = true; break;}
        }
        if(flag && s[i] == '1') arr[i] = 1;
        else arr[i] = 0;
    }
    for(auto i : arr) cout << i;
    return 0;
}