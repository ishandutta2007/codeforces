#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n, q;
int s[3][100009];
int db=0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>q;
    for(int i=1; i<=q; i++)
    {
        int a, b;
        cin>>a>>b;
        if(s[a][b]==0)
        {
            if(b>1)
            {
                if(s[3-a][b-1]) db++;
            }
            if(s[3-a][b]) db++;
            if(b<n)
            {
                if(s[3-a][b+1]) db++;
            }
            s[a][b]=1;
        }
        else
        {
            if(b>1)
            {
                if(s[3-a][b-1]) db--;
            }
            if(s[3-a][b]) db--;
            if(b<n)
            {
                if(s[3-a][b+1]) db--;
            }
            s[a][b]=0;
        }
        if(db>0) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }


    return 0;
}