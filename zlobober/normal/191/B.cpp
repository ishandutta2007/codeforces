#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long llong;

const int N = 100500;

llong A[N];

int main()
{
    int n, k;
    cin >> n >> k;
    llong b;
    cin >> b;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    vector<pair<int, int> > V;
    for (int i = 0; i < n - 1; i++)
        V.push_back(make_pair(-A[i], i));
    sort(V.begin(), V.end());
    for (int i = 0; i < V.size(); i++)
        V[i].first *= -1;
    llong s = 0;
    for (int i = 0; i < k - 1; i++)
        s += V[i].first;
    int ans = n - 1;
    for (int i = k; i < V.size(); i++)
        if (s + V[i].first > b)
            ans = min(ans, V[i].second);
    s += V[k - 1].first;
    if (s > b)
        for (int i = 0; i < k; i++)
            ans = min(ans, V[i].second);
    cout << ans + 1 << endl;
}