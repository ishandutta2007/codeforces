#include <iostream>

using namespace std;

int n, x, k;
int a[150], s = 0;

int main()
{
    cin>>n>>k>>x;
    for(int i = 0; i < n; i++)
        cin>>a[i];
    for(int i = n-1; i >= 0; i--)
    {
        if(a[i] > x && k > 0)
        {
            s += x;
            k--;
        }
        else
        {
            s += a[i];
        }
    }
    cout<<s<<endl;
    return 0;
}