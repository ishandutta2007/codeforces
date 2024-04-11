#include <iostream>

using namespace std;

int main()
{
    int n; cin>>n;
    int wid[n]; int hei[n];
    for(int i=0;i<n;i++) {cin>>wid[i]; cin>>hei[i];}
    int prev;
    if(wid[0]<hei[0]) prev=hei[0]; else prev=wid[0];
    bool flag=true;
    for(int i=1;i<n;i++)
    {
        int x; int y;
        if(wid[i]<hei[i]) {x=hei[i]; y=wid[i];}
        else {x=wid[i]; y=hei[i];}
        if(x<=prev) prev=x;
        else if(y<=prev) prev=y;
        else {flag=false; break;}
    }
    if(flag) cout<<"YES"; else cout<<"NO";
    return 0;
}