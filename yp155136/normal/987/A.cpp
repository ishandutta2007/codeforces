#include <bits/stdc++.h>
using namespace std;

/*

    the Power Gem of purple color,
    the Time Gem of green color,
    the Space Gem of blue color,
    the Soul Gem of orange color,
    the Reality Gem of red color,
    the Mind Gem of yellow color.
*/

string s1[] = {"Power" , "Time" , "Space" , "Soul" , "Reality" , "Mind"};
string s2[] = {"purple" , "green" , "blue" , "orange" , "red" , "yellow"  };

int main ()
{
    int n;
    cin >> n;
    vector<string> v;
    cout << 6-n << endl;
    while (n--)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }
    for (int i=0;6>i;i++)
    {
        bool flag = false;
        for (string s:v)
        {
            if (s2[i] == s) flag = true;
        }
        if (!flag) cout <<s1[i] << endl;
    }
}