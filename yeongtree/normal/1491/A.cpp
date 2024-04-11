#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, T; cin >> n >> T;
    int A[n]; int cnt = 0;
    for(auto &i : A)
    {
        cin >> i;
        if(i) ++cnt;
    }

    while(T--)
    {
        int c; cin >> c;
        if(c == 1)
        {
            int x; cin >> x; --x;
            if(A[x]) --cnt;
            else ++cnt;
            A[x] = !A[x];
        }
        else
        {
            int x; cin >> x;
            if(x <= cnt) cout << "1\n";
            else cout << "0\n";
        }
    }
}