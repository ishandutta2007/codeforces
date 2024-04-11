#include <iostream>

using namespace std;

int main()
{
    int n; cin>>n;
    int x[n];
    for(int i=0;i<n;i++)
    {
        char a;
        cin>>a;
        x[i]=(int)a-48;
    }
    int s=0;
    for(int i=0;i<n;i++) s+=x[i];
    if(s==0) {cout<<"YES"; return 0;}
    bool flag=false;
    for(int i=1;i<s;i++)
    {
        bool _flag=true;
        if(s%i!=0) continue;
        int nw=0;
        for(int j=0;j<n;j++)
        {
            nw+=x[j];
            if(nw==i) nw=0;
            else if(nw>i) {_flag=false; break;}
        }
        if(_flag) {flag=true; break;}
    }
    cout<<(flag?"YES":"NO");
    return 0;
}