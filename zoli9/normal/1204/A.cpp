#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s;
    int h=s.size();
    bool hatar=true;
    for(int i=1; i<h; i++)
    {
        if(s[i]=='1')
        {
            hatar=false;
            break;
        }
    }
    int ans=(h+1)/2;
    if(h%2==1 && hatar) ans--;
    cout<<ans<<endl;
    return 0;
}