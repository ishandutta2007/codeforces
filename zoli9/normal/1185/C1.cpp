#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n, m;
int t[200009];
int db[109];
vi ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i];
        int ido=0;
        int marad=0;
        for(int j=1; j<=100; j++)
        {
            if(db[j]*j+ido<=m-t[i])
            {
                ido+=(db[j]*j);
                marad+=db[j];
            }
            else
            {
                marad+=((m-t[i]-ido)/j);
                break;
            }
        }
        ans.push_back(i-marad-1);
        db[t[i]]++;
    }
    for(int i: ans) cout<<i<<" ";
    cout<<endl;


    return 0;
}