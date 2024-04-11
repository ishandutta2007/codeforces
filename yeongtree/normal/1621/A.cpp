#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    int T; cin >> T;
    while(T--)
    {
        int n, k; cin >> n >> k;
        if((n + 1) / 2 < k) cout << "-1\n";
        else
        {
            for(int i = 0; i < n; ++i)
            {
                for(int j = 0; j < n; ++j)
                {
                    if(i == j && (i % 2 == 0) && i / 2 < k) cout  << 'R';
                    else cout << '.';
                }
                cout << '\n';
            }
        }
    }
}