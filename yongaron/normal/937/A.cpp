#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a[200], n;
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>a[i];
    sort(&a[0], &a[n]);
    int x = 1;
    for(int i = n-2; i > -1; i--)
    {
        if(a[i] < a[i+1] && a[i] != 0)
            x++;
    }
    cout<<x<<endl;
    return 0;
}