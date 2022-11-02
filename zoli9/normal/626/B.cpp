#include <bits/stdc++.h>
using namespace std;
int n;
int b, g, r;
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        char cc;
        cin>>cc;
        if(cc=='B') b++;
        if(cc=='G') g++;
        if(cc=='R') r++;
    }
    if(b>0 && g>0 && r>0)
    {
        cout<<"BGR";
        return 0;
    }
    if(b>0 && g>0)
    {
        if(b>1 && g>1)
        {
            cout<<"BGR";
            return 0;
        }
        if(b==1 && g>1)
        {
            cout<<"BR";
            return 0;
        }
        if(b>1 && g==1)
        {
            cout<<"GR";
            return 0;
        }
        cout<<"R";
        return 0;
    }


    if(b>0 && r>0)
    {
        if(b>1 && r>1)
        {
            cout<<"BGR";
            return 0;
        }
        if(b==1 && r>1)
        {
            cout<<"BG";
            return 0;
        }
        if(b>1 && r==1)
        {
            cout<<"GR";
            return 0;
        }
        cout<<"G";
        return 0;
    }


    if(r>0 && g>0)
    {
        if(r>1 && g>1)
        {
            cout<<"BGR";
            return 0;
        }
        if(r==1 && g>1)
        {
            cout<<"BR";
            return 0;
        }
        if(r>1 && g==1)
        {
            cout<<"BG";
            return 0;
        }
        cout<<"B";
        return 0;
    }

    if(b>0)
    {
        cout<<"B";
        return 0;
    }
    if(g>0)
    {
        cout<<"G";
        return 0;
    }
    if(r>0)
    {
        cout<<"R";
        return 0;
    }
    return 0;
}