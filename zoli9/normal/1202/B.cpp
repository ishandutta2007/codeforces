#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

int best[10][10][10];
string s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            for(int k=0; k<10; k++)
            {
                best[i][j][k]=-1;
            }
        }
    }
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            for(int id=0; id<10; id++)
            {
                for(int jd=0; jd<10; jd++)
                {
                    if(id==0 && jd==0) continue;
                    int pl=(id*i+jd*j)%10;
                    if(best[i][j][pl]==-1 || id+jd<best[i][j][pl]) best[i][j][pl]=id+jd;
                }
            }
        }
    }
    cin>>s;
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            int ans=0;
            for(int k=1; k<s.size(); k++)
            {
                int kell=(s[k]-s[k-1]+10)%10;
                if(best[i][j][kell]==-1)
                {
                    ans=-1;
                    break;
                }
                ans+=(best[i][j][kell]-1);
            }
            cout<<ans<<" ";
        }
        cout<<endl;
    }


    return 0;
}