#include <iostream>
using namespace std;
int n;
int q;
int ans;
char c[300009];
int main()
{
    cin>>n>>q;
    for(int i=1; i<=n; i++)
    {
        cin>>c[i];
    }
    c[0]='a';
    c[n+1]='a';
    ans=0;
    for(int i=1; i<=n; i++)
    {
        if(c[i]=='.' && c[i+1]=='.') ans++;
    }
    for(int i=1; i<=q; i++)
    {
        char k;
        int l;
        cin>>l>>k;
        int elo, uta;
        elo=0;
        uta=0;
        if(c[l-1]=='.' && c[l]=='.') elo++;
        if(c[l+1]=='.' && c[l]=='.') elo++;
        c[l]=k;
        if(c[l-1]=='.' && c[l]=='.') uta++;
        if(c[l+1]=='.' && c[l]=='.') uta++;
        ans+=uta;
        ans-=elo;
        cout<<ans<<endl;
    }
    return 0;
}