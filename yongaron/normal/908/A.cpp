#include <iostream>
#include <string>

using namespace std;

string s;

int main()
{
    cin>>s;
    int n = s.size();
    int x = 0;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == '1' || s[i] == '3' || s[i] == '5' || s[i] == '7' || s[i] == '9')
            x++;
    }
    cout<<x<<endl;
    return 0;
}