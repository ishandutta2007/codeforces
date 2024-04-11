#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int i, j;
    for(i = 1; i <= n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(j == i - 1)
            {
                cout << k << " ";
            }
            else
            {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
    return 0;
}