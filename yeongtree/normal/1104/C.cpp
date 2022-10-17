#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s; cin >> s;
    int cv = 1 , ch = 1;
    int s_size = s.size();

    for(int i = 0; i < s_size; ++i)
    {
        if(s[i] == '1')
        {
            cout << ch << " 3\n";
            ch = ch % 4 + 1;
        }
        else
        {
            cout << cv << " 1\n";
            cv = (cv + 2) % 4;
        }
    }

    cout << endl;
    return 0;
}