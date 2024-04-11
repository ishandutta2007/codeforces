#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        int A[n]; for(auto &i : A) cin >> i;
        int pr = 0;
        int cnt = 0;
        for(int i : A)
        {
            if(pr < i) pr = i, ++cnt;
            else if(pr <= i) pr = i + 1, ++cnt;
        }
        cout << cnt << '\n';
    }
}