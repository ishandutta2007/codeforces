#include <iostream>
#include <algorithm>
using namespace std;

int s[500100];

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> s[i];

    sort(s, s+n);
    int a=0, ans=n;
    for(int b=(n+1)/2; b<n; b++)
    {
        if(2*s[a]<=s[b])
        {
            ans--;
            a++;
        }
    }

    cout << ans << endl;
}