#include <iostream>
#include <string>

using namespace std;

int m, n;
string s;

int main()
{
    cin>>m>>n
    ;
    cin>>s;
    for(int i = 0; i < n; i++)
    {
        int l, r;
        char a, b;
        cin>>l>>r>>a>>b;
        for(int j = l-1; j < r; j++)
        {
            if(s[j] == a)
                s[j] = b;
        }
    }
    cout<<s<<endl;
    return 0;
}