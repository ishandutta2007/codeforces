#include <iostream>
#include <algorithm>

using namespace std;

int n, k, a[200];

int main()
{
    cin>>n>>k;
    for(int i = 0; i < n; i++)
        cin>>a[i];
    sort(&a[0], &a[n]);
    int best;
    for(int i = 0; i < n; i++)
    {
        if(k%a[i] == 0)
            best = k/a[i];
    }
    cout<<best<<endl;
    return 0;
}