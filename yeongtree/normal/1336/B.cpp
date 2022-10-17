#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long ans;

void sol(vector<int> X, vector<int> Y, vector<int> Z)
{
    int x = X.size();
    int y = Y.size();
    int z = Z.size();

    int px = 0, py = 0, pz = 0;
    while(px < x)
    {
        while(py < y && Y[py] < X[px]) ++py;
        while(pz < z && Z[pz] < Y[py]) ++pz;
        while(py < y - 1 && Y[py] + Y[py + 1] < X[px] + Z[pz]) ++py;
        if(px != x && py != y && pz != z) ans = min(ans, 1ll * (X[px] - Y[py]) * (X[px] - Y[py]) + 1ll * (Y[py] - Z[pz]) * (Y[py] - Z[pz]) + 1ll * (Z[pz] - X[px]) * (Z[pz] - X[px]));
        ++px;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int x, y, z; cin >> x >> y >> z;
        ans = (long long)8e18;
        vector<int> X(x), Y(y), Z(z);
        for(auto &i : X) cin >> i;
        for(auto &i : Y) cin >> i;
        for(auto &i : Z) cin >> i;
        sort(X.begin(), X.end());
        sort(Y.begin(), Y.end());
        sort(Z.begin(), Z.end());

        sol(X, Y, Z);
        sol(X, Z, Y);
        sol(Y, X, Z);
        sol(Y, Z, X);
        sol(Z, X, Y);
        sol(Z, Y, X);
        cout << ans << '\n';
    }
}