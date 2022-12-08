#include <iostream>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n<3)
    {
        cout << "-1" << endl;
        return 0;
    }
    if(n%2)
    {
        int k=(n-1)/2;

        for(int i=1; i<=n; i++)
            if(i!=k) cout << i << " ";

        cout << k << endl;
    }
    else
    {
        int k=(n-2)/2;

        for(int i=1; i<=n-1; i++)
            if(i!=k) cout << i << " ";

        cout << k << " " << n << endl;

    }
}