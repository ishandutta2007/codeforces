#include<iostream>

using namespace std;

int t;

int main(int argc, char const *argv[])
{
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        if(k > (n+1)/2)
            cout << -1 << endl;
        else
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(i == j && ~i&1 && i/2 < k)
                        cout << 'R';
                    else
                        cout << '.';
                }
                cout << endl;
            }
        }
    }
    return 0;
}