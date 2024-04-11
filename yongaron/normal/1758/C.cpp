#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int n, x;
        cin >> n >> x;
        if(n % x)
        {
            cout << -1 << endl;
            continue;
        }
        cout << x << " ";
        int next = x + 1;
        for(int i = 2; i < n; i++)
        {
            if(i != x)
                cout << i << " ";
            else
            {
                for(int j = next; j <= n; j++)
                {
                    if(j%x == 0 && n%j == 0)
                    {
                        cout << j << " ";
                        x = j;
                        next = j + 1;
                        break;
                    }
                }
            }
        }
        cout << 1 << endl;
    }
    return 0;

}