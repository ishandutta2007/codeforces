#include <iostream>

using namespace std;

bool ifEnd(int x)
{
    ++x;
    while(x)
    {
        if((x & 1) && x != 1) return false;
        x >>= 1;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int ans[20], cnt = 0;

    while(1)
    {
        if(ifEnd(n))
        {
            cout << cnt * 2 << endl;
            for(int i = 0; i < cnt; ++i) cout << ans[i] << ' ';
            return 0;
        }

        int i = 0;
        while(1)
        {
            if(n & (1 << i)) break;
            ++i;
        }
        ans[cnt++] = i;
        n ^= ((1 << i) - 1);

        if(ifEnd(n))
        {
            cout << cnt * 2 - 1 << endl;
            for(int i = 0; i < cnt; ++i) cout << ans[i] << ' ';
            return 0;
        }

        n += 1;
    }
}