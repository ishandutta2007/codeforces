#include <bits/stdc++.h>
using namespace std;

#define int long long

int cal(vector<int> v)
{
    int ret=0;
    for (int i:v)
    {
        //cout << i << ' ';
        if (i%2==0) ret += i;
    }
    //cout << endl;
    return ret;
}

int solve(vector<int> v)
{
    //select v[0]
    int n=14;
    if (v[0] == 0) return 0;
    int num = v[0];
    v.erase(v.begin());
    v.push_back(0);
    //v[0] = 0;
    for (int i=0;n>i;i++)
    {
        v[i] += (num/n);
        if (num%n > i) ++v[i];
    }
    return cal(v);
}

main ()
{
    vector<int> v;
    int n = 14;
    for (int i=0;n>i;i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int ans=0;
    int cnt = 16;
    while (cnt--)
    {
        int _ = (*v.begin());
        //cout << "_ = " << _ << endl;
        v.erase(v.begin());
        v.push_back(_);
        ans = max(ans,solve(v));
    }
    cout <<ans << endl;
}