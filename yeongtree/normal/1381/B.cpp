#include <iostream>
#include <vector>

using namespace std;

int arr[101010];
bool dp[101010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n; int N = 2 * n;
        for(int i = 0; i < N; ++i) cin >> arr[i];
        int mx = arr[0], pr = 0;
        vector<int> ls;
        for(int i = 1; i < N; ++i)
        {
            if(arr[i] > mx) ls.push_back(i - pr), mx = arr[i], pr = i;
        }
        ls.push_back(N - pr);

        dp[0] = 1;
        for(int i = 1; i <= n; ++i) dp[i] = false;
        for(auto i : ls)
        {
//            cout << i << ' ';
            for(int j = n; j >= 0; --j) if(dp[j]) dp[i + j] = true;
        }
//        cout << endl;

        cout << (dp[n] ? "YES" : "NO") << '\n';
    }
}