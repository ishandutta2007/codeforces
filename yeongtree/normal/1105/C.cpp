#include <iostream>

using namespace std;

int main()
{
    int n,l,r; cin >> n >> l >> r;
    const long long int Q = 1000000007;

    long long int id[3]={};
    id[0] += r / 3; id[1] += (r+2) / 3; id[2] += (r+1) / 3;
    id[0] -= (l-1) / 3; id[1] -= (l+1) / 3; id[2] -= l / 3;

    long long int cnt[2][3];
    cnt[0][0] = id[0]; cnt[0][1] = id[1]; cnt[0][2] = id[2];
    for(int i = 2; i <= n; ++i)
    {
        int bf = i % 2 , nx = (i+1) % 2;
        cnt[nx][0] = cnt[bf][0] * id[0] + cnt[bf][1] * id[2] + cnt[bf][2] * id[1];
        cnt[nx][1] = cnt[bf][0] * id[1] + cnt[bf][1] * id[0] + cnt[bf][2] * id[2];
        cnt[nx][2] = cnt[bf][0] * id[2] + cnt[bf][1] * id[1] + cnt[bf][2] * id[0];
        cnt[nx][0] %= Q;
        cnt[nx][1] %= Q;
        cnt[nx][2] %= Q;
    }

    cout << cnt[(n + 1) % 2][0] << endl;
    return 0;
}