#include<bits/stdc++.h>
using namespace std;

int a,b,op,t;

void solve(int A,int B,int i)
{
    if (i<0)
    {
        cout<<"! "<<A<<" "<<B<<endl;
        return ;
    }

    cout<<"? "<<A<<" "<<B<<endl;
    cin>>op;
    if (op)
    {
        for (;~i;--i)
        {
            cout<<"? "<<(A^(1<<i))<<" "<<(B^(1<<i))<<endl;
            cin>>t;
            if (op!=t)
            {
                if (op==1)
                    A^=(1<<i);
                else
                    B^=(1<<i);
                break;
            } else
            {        
                cout<<"? "<<A<<" "<<(B^(1<<i))<<endl;
                cin>>t;
                if (t==1)
                    A^=(1<<i),B^=(1<<i);
            }
        }
        solve(A,B,--i);
    } else
    {
        cout<<"? "<<A<<" "<<(B^(1<<i))<<endl;
        cin>>t;
        if (t==1)
            A^=(1<<i),B^=(1<<i);
        solve(A,B,--i);
    }
}

int main()
{
    solve(0,0,29);
    return 0;
}