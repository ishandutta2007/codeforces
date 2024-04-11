#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

char cnt[256];
pair<int, int> pr[256];    

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int m = 0;
    for (int i = 0; i < 256; i++)
        pr[i].second = i;
    for (int i = 0; i < n; i++)
        pr[s[i]].first++,
        cnt[s[i]]++;
    sort(pr, pr + 256);
    cin >> m;
    int cur = 0;
    bool good[256];
    for (int i = 0; i < 256; i++)
        if (cur + pr[i].first <= m)
            good[pr[i].second] = 1, cur += pr[i].first;
        else
            if (cnt[pr[i].second] != 0)
                good[pr[i].second] = 0;
            else
                good[pr[i].second] = 1;
    int ans = 0;
    for (int i = 0; i < 256; i++)
        ans += !good[i];
    
    string sans;
    
    for (int i = 0; i < n; i++)
        if (!good[s[i]])
            sans.push_back(s[i]);
    cout << ans << endl << sans;
}