#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    cin >> n;
    string s,t;
    cin >> s >> t;
    string ss=s,tt=t;
    sort(ss.begin(),ss.end());
    sort(tt.begin(),tt.end());
    if (ss != tt)
    {
        cout << -1 << endl;
        return 0;
    }
    swap(s,t);
    vector<int> ans;
    for (int i=0;n>i;i++)
    {
        if (s[i] != t[i])
        {
            int j;
            for (j=i;n>j;j++)
            {
                if (s[i] == t[j]) break;
            }
            while (j != i)
            {
                ans.push_back(j);
                swap(t[j],t[j-1]);
                --j;
            }
        }
    }
    cout << ans.size() << endl;
    for (int i:ans) cout << i << ' ';
    cout<<endl;
}