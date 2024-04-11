#include <iostream>
using namespace std;
int a, b, c, d, e, f;
int main()
{
    cin>>a>>b>>c>>d>>e>>f;
    if(c+e<=a && d<=b && f<=b)
    {
        cout<<"YES";
        return 0;
    }
    if(c+f<=a && d<=b && e<=b)
    {
        cout<<"YES";
        return 0;
    }
    if(d+e<=a && c<=b && f<=b)
    {
        cout<<"YES";
        return 0;
    }
    if(d+f<=a && c<=b && e<=b)
    {
        cout<<"YES";
        return 0;
    }

    if(c+e<=b && d<=a && f<=a)
    {
        cout<<"YES";
        return 0;
    }
    if(c+f<=b && d<=a && e<=a)
    {
        cout<<"YES";
        return 0;
    }
    if(d+e<=b && c<=a && f<=a)
    {
        cout<<"YES";
        return 0;
    }
    if(d+f<=b && c<=a && e<=a)
    {
        cout<<"YES";
        return 0;
    }
    cout<<"NO";
    return 0;
}