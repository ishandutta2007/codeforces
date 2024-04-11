#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int pr[n]; bool isnR[n];
    for(int i = 0; i < n; ++i) {cin >> pr[i] >> isnR[i]; --pr[i];}

    bool cantD[n]{};
    for(int i = 0; i < n; ++i)
    {
        if(!isnR[i])
        {
            cantD[i] = true;
            cantD[pr[i]] =true;
        }
    }

    vector<int> lisD;
    for(int i = 0; i < n; ++i) if(!cantD[i]) lisD.push_back(i);
    sort(lisD.begin(), lisD.end());

    for(auto& i : lisD) cout << i + 1 << ' ';
    if(lisD.empty()) cout << "-1";

    return 0;
}