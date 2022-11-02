#include <iostream>
using namespace std;
int n;
int h;
string s[100005];
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>s[i];
    }
    h=s[1].size();
    for(int i=0; i<h; i++)
    {
        int j=1;
        while(j<=n && s[j][i]=='?')
        {
            j++;
        }
        bool v=true;
        char c;
        if(j<=n)
        {
            c=s[j][i];

        for(int k=j+1; k<=n; k++)
        {
            if(s[k][i]=='?' || s[k][i]==c)
            {

            }
            else
            {
                cout<<"?";
                v=false;
                break;

            }
        }
        if(v)
        {
            cout<<c;
        }
        }
        else
        {
            cout<<"x";
        }
    }
    return 0;
}