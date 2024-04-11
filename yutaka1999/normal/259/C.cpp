#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;



int main()
{
    string p;
    cin>>p;
    
    for(int i=0;i<p.size()-1;i++)
    {
        if(p[i]=='0')
        {
            for(int j=i+1;j<p.size();j++)
            {
                cout<<p[j];
            }
            cout<<endl;
            return 0;
        }
        cout<<p[i];
    }
    cout<<endl;
    return 0;
}