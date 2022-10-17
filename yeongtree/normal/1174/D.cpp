#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x; cin >> n >> x;
    int t = (1 << n);
    vector<int> basis;
    for(int i = 1; i < t; ++i)
    {
        int tmp = i;
        tmp = min(tmp, tmp ^ x);
        for(auto j : basis) tmp = min(tmp, tmp ^ j);
        if(tmp) basis.push_back(tmp);
    }

    int num = (1 << basis.size()) - 1;
    cout << num << '\n';
    for(int i = 1; i <= num; ++i)
    {
        int pl = 0;
        while(!(i & (1 << pl))) ++pl;
        cout << basis[pl] << ' ';
    }

    return 0;
}