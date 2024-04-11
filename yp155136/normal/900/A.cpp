#include <iostream>
#include <cstdio>
using namespace std;

int main ()
{
    int n;
    cin >> n;
    int ans=0;
    int _=n;
    while (n--)
    {
        int x,y;
        cin >> x >> y;
        if (x>0) ans++;
        else ans--;
    }
    if (ans == -_ || ans == _ || ans == _-2 || ans == -_+2) puts("Yes");
    else puts("No");
}