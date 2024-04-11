#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str; int n;
    cin >> str;
    cin >> n;
    for(int i=0; i<str.size(); i++)
        if(str[i]>='A' && str[i]<='Z')
            str[i]=str[i]-'A'+'a';

    for(int i=0; i<str.size(); i++)
        if(str[i]<n+97)
            str[i]=str[i]-'a'+'A';

    cout << str << endl;
}