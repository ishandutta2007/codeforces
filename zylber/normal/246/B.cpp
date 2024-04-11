#include <iostream>
#include <vector>
using namespace std;

int a[100010];

int main()
{
    int n;
    cin >> n;

    for(int i=0; i<n; i++) cin >> a[i];

    int sum=0;
    for(int i=0; i<n; i++) sum+=a[i];

    while(sum<0) sum+=n;

    if(sum%n)
        cout << n-1 << endl;
    else
        cout << n << endl;
}