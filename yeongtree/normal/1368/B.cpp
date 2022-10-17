#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n; cin >> n;
    int ans = 0;
    while(1)
    {
        long long k = 1;
        for(int i = 0; i < 10; ++i)
        {
            k *= (ans + i) / 10;
        }
        if(k >= n)
        {
            char cd[] = "codeforces";
            for(int i = 0; i < 10; ++i)
            {
                for(int j = 0; j < (ans + i) / 10; ++j)
                    cout << cd[i];
            }
            return 0;
        }
        ++ans;
    }
}