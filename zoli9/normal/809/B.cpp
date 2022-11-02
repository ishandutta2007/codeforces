#include <bits/stdc++.h>
using namespace std;
int n;
int k;
string ba;
int main()
{
    cin>>n>>k;
    int elso=1;
    int utolso=n;
    while(elso!=utolso)
    {
        int kozep=(elso+utolso)/2;
        cout<<"1 "<<kozep<<" "<<kozep+1<<endl;
        fflush(stdout);
        cin>>ba;
        if(ba=="TAK")
        {
            utolso=kozep;
        }
        else
        {
            elso=kozep+1;
        }
    }
    int gold=elso;
    if(gold!=1)
    {
        int e1=1;
        int e2=gold-1;
        while(e1!=e2)
        {
            int kozep=(e1+e2)/2;
            cout<<"1 "<<kozep<<" "<<kozep+1<<endl;
            fflush(stdout);
            cin>>ba;
            if(ba=="TAK")
            {
                e2=kozep;
            }
            else
            {
                e1=kozep+1;
            }
        }
        cout<<"1 "<<e1<<" "<<gold<<endl;
        fflush(stdout);
        cin>>ba;
        if(ba=="TAK")
        {
            cout<<"2 "<<e1<<" "<<gold<<endl;
            fflush(stdout);
            return 0;
        }
    }
    int f1=gold+1;
    int f2=n;
    while(f1!=f2)
    {
        int kozep=(f1+f2)/2;
        cout<<"1 "<<kozep+1<<" "<<kozep<<endl;
        fflush(stdout);
        cin>>ba;
        if(ba=="TAK")
        {
            f1=kozep+1;
        }
        else
        {
            f2=kozep;
        }
    }

        cout<<"2 "<<gold<<" "<<f1<<endl;
        fflush(stdout);


    return 0;
}