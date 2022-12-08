#include <iostream>
using namespace std;

int a[100010];

int main()
{
    int n;
    cin >> n;
    
    int great=0, gi=0;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        if(great<=a[i])
        {
            great=a[i];
            gi=i;
        }
    }
    if(gi==n-1 && a[gi]==a[0])
    {
        gi=0;
        while(gi<n-1 && a[gi]==a[gi+1]) gi++;
    }
    
    int can=1;
    for(int i=0; i<n-1; i++)
    {
        if(a[(i+gi+1)%n]>a[(i+gi+2)%n]) can=0;
    }
    
    if(can)
    {
        cout << n-1-gi << endl;
    }
    else
        cout << -1 << endl;
}