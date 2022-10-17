#include <iostream>

using namespace std;

int main()
{
    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        int ans = 1;
        while(ans <= n) ans *= 2;
        if(--ans == n)
        {
            for(int i = 3; i < 8000; i += 2)
                if(n % i == 0){ans /= i; break;}
            if(ans == n) ans = 1;
        }
        cout << ans << '\n';
    }
    return 0;
}