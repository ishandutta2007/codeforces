#include <iostream>
#include <string>
using namespace std;

const int N = 1000500;
pair<int, int> mx[N];

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    mx[s.size()] = make_pair(-1e9, n);
    for (int i = s.size() - 1; i >= 0; i--)
        mx[i] = max(mx[i + 1], make_pair((int)s[i], -i));
    string ans = "";
    int cur = 0;
    while (1)
    {
        ans += mx[cur].first;
        if (cur == n)
            break;
        cur = -mx[cur].second + 1;
    }
    ans.resize(ans.size() - 1);
    cout << ans << endl;
}