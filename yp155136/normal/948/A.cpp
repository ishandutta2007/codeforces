#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main ()
{
    int n,m;
    cin >>n >> m;
    string s[n];
    for (int i=0;n>i;i++)
    {
        cin >> s[i];
    }
    for (int i=0;n>i;i++)
    {
        for (int j=0;m>j;j++)
        {
            if (j+1 < m)
            {
                string tmp;
                tmp.push_back(s[i][j]);
                tmp.push_back(s[i][j+1]);
                sort(tmp.begin(),tmp.end());
                if (tmp == "SW")
                {
                    cout << "No" << endl;
                    return 0;
                }
            }
            if (i+1 < n)
            {
                string tmp;
                tmp.push_back(s[i][j]);
                tmp.push_back(s[i+1][j]);
                sort(tmp.begin(),tmp.end());
                if (tmp == "SW")
                {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Yes" << endl;
    for (int i=0;n>i;i++)
    {
        for (int j=0;m>j;j++)
        {
            if (s[i][j] != '.') cout <<s[i][j];
            else cout << 'D';
        }
        cout << endl;
    }
}