#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    long long arr[n]; for(auto &i : arr) cin >> i;
    long long st = arr[0];
    vector<long long> Z;
    for(int i = 1; i < n; ++i)
    {
        long long x = arr[i] - (st + i - 1 - (long long)Z.size());
        while(Z.size() && x > i - Z.back()) x -= i - Z.back() + 1, Z.pop_back();
        if(Z.empty())
        {
            st += (x + i - 1) / (i + 1);
            x %= i + 1;
            if(x > 1) Z.push_back(0);
        }
        if(Z.size() && x) Z[(int)Z.size() - 1] += x - 1;
        else if(!x) Z.push_back(i);
    }
    int pt = 0;
    cout << st << ' ';
    for(int i = 1; i < n; ++i)
    {
        if(pt < (int)Z.size() && Z[pt] == i) ++pt;
        else ++st;
        cout << st << ' ';
    }
}