#include <iostream>
using namespace std;
int a[5];
string s;
long long cnt=0;
int main()
{
    for(int i=1; i<=4; i++)
    {
        cin>>a[i];
    }
    cin>>s;
    for(int i=0; i<s.size(); i++)
    {
        cnt+=a[s[i]-'0'];
    }
    cout<<cnt;
    return 0;
}