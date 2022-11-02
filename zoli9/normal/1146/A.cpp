#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s;
    int h=s.size();
    int ac=0;
    for(int i=0; i<h; i++)
    {
        if(s[i]=='a') ac++;
    }
    if(ac*2>h) {

        cout<<h<<endl;
        return 0;
    }
    cout<<2*ac-1<<endl;
    return 0;
}