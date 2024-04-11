#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    int n = a.size();
    int c[] = {0, 0};
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
            c[a[i] == '4']++;
    }
    cout << max(c[0], c[1]);
}