#include <iostream>
#include <string>

using namespace std;

string s;
int mi[300005], ma[300005];
int n;

int main()
{
    cin>>n>>s;
    for(int i = 0; i < 3*n; i++)
    {
        ma[i] = -1;
        mi[i] = n+1;
    }
    int pre = n;
    mi[n] = 0;
    ma[n] = 0;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '1')
            pre++;
        else
            pre--;
        if(i < mi[pre])
            mi[pre] = i+1;
        if(i > ma[pre])
            ma[pre] = i+1;
    }
    int x = 0;
    for(int i = 0; i < 3*n; i++)
    {
        if(ma[i]-mi[i] > x)
            x = ma[i]-mi[i];
    }
    cout<<x<<endl;
    return 0;
}