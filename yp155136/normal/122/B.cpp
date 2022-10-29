#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,string> P;

bool is_lucky(string s)
{
    for (char i:s)
    {
        if (i!='7' && i!='4') return false;
    }
    return true;
}

string _;

vector<P> ans;

void doo(string s)
{
    if (!is_lucky(s)) return;
    int n=_.size();
    int m=s.size();
    int cnt=0;
    for (int i=0;n>i;i++)
    {
        bool can=true;
        for (int j=0;m>j;j++)
        {
            if (i+j >= n)
            {
                can=false;
                break;
            }
            else if (_[i+j] != s[j])
            {
                can=false;
                break;
            }
        }
        cnt += can;
    }
    ans.push_back(make_pair(-cnt,s));
}

int main ()
{
    string s;
    cin >> s;
    _=s;
    int n=s.size();
    for (int i=0;n>i;i++)
    {
        string tmp="";
        for (int j=i;n>j;j++)
        {
            tmp.push_back(s[j]);
            doo(tmp);
        }
    }
    sort(ans.begin(),ans.end());
    if (ans.size() == 0) cout << -1 << endl;
    else cout << ans[0].second << endl;
}