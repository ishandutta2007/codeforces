#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string in[10];
string str[10];
string arr[10];

int main()
{
    for(int i=0;i<8;i++)
    {
        string p;
        cin>>p;
        for(int j=1;j<8;j++)
        {
            if(p[j]==p[j-1])
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    cout<<"YES"<<endl;
    return 0;
}