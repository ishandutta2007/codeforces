#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    string s;
    for(int i = 0; i < t; i++)
    {
        cin >> s;
        cout << s;
        reverse(s.begin(), s.end());
        cout << s << endl;
    }
    return 0;

}