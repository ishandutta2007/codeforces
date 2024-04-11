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

vi db[5];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        int n;
        cin>>n;
        for(int i=0; i<5; i++) db[i].assign(n, 0);
        vector<string> s(n);
        for(int i=0; i<n; i++)
        {
            cin>>s[i];
            for(int j=0; j<s[i].size(); j++)
            {
                db[s[i][j]-'a'][i]++;
            }
        }
        vi idx;
        for(int i=0; i<n; i++) idx.push_back(i);
        int ans=0;
        for(int x=0; x<5; x++)
        {
            sort(idx.begin(), idx.end(), [x, &s] (int i1, int i2) -> bool
            {
               return 2*db[x][i1]-(int)(s[i1].size())>2*db[x][i2]-(int)(s[i2].size());
            });
            int cans=0;
            int d1=0;
            int d2=0;
            for(int i=0; i<n; i++)
            {
                int si=s[idx[i]].size();
                if(d1+db[x][idx[i]]>d2+si-db[x][idx[i]])
                {
                    d1+=db[x][idx[i]];
                    d2+=(si-db[x][idx[i]]);
                    cans++;
                }
                else
                {
                    break;
                }
            }
            ans=max(ans, cans);
        }
        cout<<ans<<'\n';
    }
    return 0;
}