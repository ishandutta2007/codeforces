#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//(double)clock() / CLOCKS_PER_SEC;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        string s;
        cin>>s;
        int n=s.size();
        vi last(26, -1);
        for(int i=0; i<n; i++)
        {
            last[s[i]-'a']=i;
        }
        vector<bool> used(26, false);
        string ans="";
        vector<char> best;
        for(int i=0; i<n; i++)
        {
            if(used[s[i]-'a']) continue;
            while(best.size()>0 && s[i]>best.back() && last[best.back()-'a']>i)
            {
                used[best.back()-'a']=false;
                best.pop_back();
            }
            used[s[i]-'a']=true;
            best.push_back(s[i]);
        }
        for(char ccc: best) cout<<ccc;
        cout<<'\n';
    }
    return 0;
}