#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        int a = 0, b = 0;
        for(int i = 0; i < k; ++i)
        {
            int tmp = -1;
            for(int j = i; j < n; j += k)
            {
                if(s[j] == '0')
                {
                    if(tmp == 1) { cout << "NO\n"; goto A; }
                    tmp = 0;
                }
                if(s[j] == '1')
                {
                    if(tmp == 0) { cout << "NO\n"; goto A; }
                    tmp = 1;
                }
            }
            if(tmp == 0) ++a;
            else if(tmp == 1) ++b;
        }
        if(a > k / 2 || b > k / 2) cout << "NO\n";
        else cout << "YES\n";
        A:;
    }
}