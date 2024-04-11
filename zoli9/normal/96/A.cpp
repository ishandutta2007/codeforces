#include <iostream>
using namespace std;
string s;
int t[1000];
int counter;
int main()
{
    cin>>s;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]=='0')
        {
            t[i]=0;
        }
        else
        {
            t[i]=1;
        }
    }
    counter=1;
    for(int i=1; i<s.length(); i++)
    {
        if(t[i]==t[i-1])
        {
            counter++;
        }
        else
        {
            counter=1;
        }
        if(counter==7)
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";

    return 0;
}