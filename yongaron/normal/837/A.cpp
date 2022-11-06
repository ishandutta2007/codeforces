#include <iostream>
#include <string>

using namespace std;

int n;
char text[250];
int val(string s)
{
    int x = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] <= 'Z')
            x++;
    }
    return x;
}
string st;

int main()
{
    int ma = 0;
    int s = 0;
    cin>>n;
    while(s < n)
    {
        cin>>st;
        s += st.size()+1;
        ma = max(ma, val(st));
    }
    cout<<ma<<endl;
    return 0;
}