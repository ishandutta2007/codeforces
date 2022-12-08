#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[64];

int main()
{
    int n, k;
    cin >> n >> k;

    for(int i=0; i<n; i++) cin >> a[i];

    sort(a,a+n);

    int s=0, p=0;
    for(int i=0; i<k; i++)
    {
        cout << s+1 << " ";
        for(int j=0; j<s; j++)
            cout << a[n-1-j] << " ";

        cout << a[p] << endl;
        p++;
        if(p==n-s)
        {
            s++; p=0;
        }
    }
}