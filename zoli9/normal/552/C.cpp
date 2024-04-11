#include <iostream>
using namespace std;
long long w, m;
bool h[100];
bool jo(long long x)
{
    int also=0;
    long long sz=1;
    while(x>sz)
    {
        also++;
        sz*=w;
    }
    if(x==sz)
    {
        if(h[also])
        {
            h[also]=false;
            return true;
        }
        return false;
    }
    also--;
    long long sza=sz/w;
    if(x-sza<=sz-x)
    {
        if(h[also])
        {
            h[also]=false;
            return jo(x-sza);
        }
        else
        {
            return false;
        }
    }
    else
    {
        if(h[also+1])
        {
            h[also+1]=false;
            return jo(sz-x);
        }
        else
        {
            return false;
        }
    }
    return false;
}
int main()
{
    cin>>w>>m;
    if(w==2 or w==3)
    {
        cout<<"YES";
        return 0;
    }
    for(int i=0; i<=100; i++)
    {
        h[i]=true;
    }
    if(jo(m))
    {
        cout<<"YES";
        return 0;
    }
    cout<<"NO";
    return 0;
}