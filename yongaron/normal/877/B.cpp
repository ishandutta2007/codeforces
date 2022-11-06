#include <iostream>
#include <string>

using namespace std;

string s;
int pre[5005];

int main()
{
    cin>>s;
    int x = 0;
    pre[0] = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'a')
            x++;
        pre[i+1] = x;
    }
    int ma = 0;
    for(int i = 0; i <= s.size(); i++)
    {
        for(int j = i; j <= s.size(); j++)
        {
            int f = pre[i]+(j-i-(pre[j]-pre[i]))+pre[s.size()]-pre[j];
            if(f > ma)
                ma = f;
        }
    }
    cout<<ma<<endl;
    return 0;
}