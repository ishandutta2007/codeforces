#include <iostream>
using namespace std;

int a[60];

int main()
{
    int n, k;
    cin >> n >> k;
    for(int i=0; i<n; i++)
    cin >> a[i];

    int adv=0;
    for(int i=0; i<n; i++)
    if(a[i]>=a[k-1] && a[i]>0)
    adv++;

    cout << adv << endl;
}