#include <vector>
#include <iostream>
using namespace std;
string s;
int t[109];
int main()
{
    cin>>s;
    for(int i=0; i<s.size(); i++)
    {
        t[i]=s[i]-'0';
        if(t[i]==0 or t[i]==8)
        {
            cout<<"YES"<<endl;
            cout<<t[i];
            return 0;
        }
    }

    for(int a1=0; a1<s.size(); a1++)
    {
        for(int a2=a1+1; a2<s.size(); a2++)
    {
        if(a1!=a2)
        {
            int z;
            z=10*t[a1]+t[a2];
            if(z%8==0)
            {
                cout<<"YES"<<endl;
                cout<<z;
                return 0;
            }
        }
    }
    }

    for(int a1=0; a1<s.size(); a1++)
    {
        for(int a2=a1+1; a2<s.size(); a2++)
    {
        for(int a3=a2+1; a3<s.size(); a3++)
    {
        if(a1!=a2 and a1!=a3 and a2!=a3)
        {
            int z;
            z=100*t[a1]+10*t[a2]+t[a3];
            if(z%8==0)
            {
                cout<<"YES"<<endl;
                cout<<z;
                return 0;
            }
        }
    }
    }
    }
    cout<<"NO";
    return 0;
}