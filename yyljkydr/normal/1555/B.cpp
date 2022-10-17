#include<bits/stdc++.h>
using namespace std;

int T;

int w,h;

int a,b,c,d,x,y;

int main()
{
    cin>>T;
    while(T--)
    {
        cin>>w>>h;
        cin>>x>>y>>a>>b>>c>>d;
        int ans=1e9;
        if(a-x+c>w&&b-y+d>h)
        {
            puts("-1");
            continue;
        }
        if(a-x+c<=w)
        {
            ans=min(ans,max(c-x,0));
            ans=min(ans,max(c-(w-a),0));
        }
        if(b-y+d<=h)
        {
            ans=min(ans,max(d-y,0));
            ans=min(ans,max(d-(h-b),0));
        }
        printf("%d\n",ans);
    }
}