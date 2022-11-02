#include <iostream>
using namespace std;
int n, t;
string s;
int main()
{
    cin>>n>>t>>s;
    for(int j=1; j<=t; j++)
    {
        for(int i=0; i<n-1; i++)
    {
        if(s[i]=='B' && s[i+1]=='G')
        {
            s[i]='G';
            s[i+1]='B';
            i++;
        }
    }
    }
    cout<<s;



    return 0;
}