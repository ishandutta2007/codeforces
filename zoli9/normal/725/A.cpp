#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int fir=-1;
int sec=-1;
int main()
{
    cin>>n;
    cin>>s;
    for(int i=0; i<n; i++)
    {
        if(s[i]=='>')
        {
            if(fir==-1) fir=i;
        }
        else if(s[i]=='<')
        {
            sec=i;
        }
    }
    if(fir==-1 || sec==-1)
    {
        cout<<n<<endl;
        return 0;
    }
    cout<<fir+n-sec-1<<endl;
    return 0;
}