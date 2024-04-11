#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD=998244353;
ll szo[11][64][64];
ll kozos[11][64][64][64];
int n;
string z;
unordered_set<string> s;
int getid(char c)
{
    int res;
    if('a'<=c && c<='z') return (c-'a');
    res+=26;
    if('A'<=c && c<='Z') return res+=(c-'A');
    res+=26;
    return res+(c-'0');
}
char g(int x)
{
    if(x<26) return 'a'+x;
    x-=26;
    if(x<26) return 'A'+x;
    x-=26;
    return '0'+x;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>z;
        s.insert(z);
        reverse(z.begin(), z.end());
        s.insert(z);
    }
    for(string z: s)
    {
        int h=(int)(z.size());
        int kezd=getid(z[0]);
        int veg=getid(z[h-1]);
        szo[h][kezd][veg]++;
    }
    for(int hossz=3; hossz<=10; hossz++)
    {
        for(int i1=0; i1<62; i1++)
        {
            for(int i2=i1; i2<62; i2++)
            {
                for(int i3=i2; i3<62; i3++)
                {
                    for(int vege=0; vege<62; vege++)
                    {
                        ll uj=(szo[hossz][i1][vege]*szo[hossz][i2][vege])%MOD;
                        uj=(uj*szo[hossz][i3][vege])%MOD;
                        kozos[hossz][i1][i2][i3]=(kozos[hossz][i1][i2][i3]+uj)%MOD;

                    }
                }
            }
        }
    }
    ll ans=0;
    for(int hossz=3; hossz<=10; hossz++)
    {
        for(int i1=0; i1<62; i1++)
        {
            for(int i2=i1; i2<62; i2++)
            {
                for(int i3=i2; i3<62; i3++)
                {
                    for(int i4=i3; i4<62; i4++)
                    {
                        ll uj=24;
                        if(i1==i2 && i2==i3 && i3==i4) uj=1;
                        else if((i1==i2 && i2==i3) || (i2==i3 && i3==i4)) uj=4;
                        else if(i1==i2 && i3==i4) uj=6;
                        else if(i1==i2 || i2==i3 || i3==i4) uj=12;
                        uj=(uj*kozos[hossz][i1][i2][i3])%MOD;
                        uj=(uj*kozos[hossz][i1][i2][i4])%MOD;
                        uj=(uj*kozos[hossz][i1][i3][i4])%MOD;
                        uj=(uj*kozos[hossz][i2][i3][i4])%MOD;
                        ans=(ans+uj)%MOD;
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}