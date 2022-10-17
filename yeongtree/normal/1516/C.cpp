#include <iostream>

using namespace std;

int main()
{
    int n; cin >> n;
    int A[n]; for(auto &i : A) cin >> i;
    int s = 0; for(auto i : A) s += i;
    if(s & 1) { cout << 0; return 0; }
    s /= 2;
    bool dp[s + 1]{};
    dp[0] = true;
    for(int i = 0; i < n; ++i) for(int j = s; j >= A[i]; --j) dp[j] = dp[j] || dp[j - A[i]];
    if(!dp[s]) { cout << 0; return 0; }
    while(1)
    {
        for(int i = 0; i < n; ++i)
        {
            if(A[i] & 1)
            {
                cout << "1\n" << i + 1;
                return 0;
            }
        }
        for(int i = 0; i < n; ++i) A[i] /= 2;
    }
}