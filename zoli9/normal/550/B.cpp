#include <iostream>
#include <vector>
using namespace std;
long long n, l, r, xxx;
long long db=0;
long long t[21];
bool v[21];
long long sum, maxi, mini;
void fel(int x)
{
    //cout<<"*";
    if(x<=n)
    {
        v[x]=true;
        fel(x+1);
        v[x]=false;
        fel(x+1);
    }
    else
    {
        vector<int> akt;
        sum=0;
        maxi=-1;
        mini=1000009;
        for(int i=1; i<=n; i++)
        {
            if(v[i])
            {
                akt.push_back(t[i]);
                if(t[i]>maxi)
                {
                    maxi=t[i];
                }
                if(t[i]<mini)
                {
                    mini=t[i];
                }
                sum+=t[i];
            }
        }
        if(akt.size()>=2)
        {
            //cout<<"ok";
            if(sum>=l and sum<=r)
            {
                //cout<<"j";
                if(maxi-mini>=xxx)
                {
                    db++;
                }
            }
        }
    }
}
int main()
{
    cin>>n>>l>>r>>xxx;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i];
    }
    fel(1);
    cout<<db;
    return 0;
}