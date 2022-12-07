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
        int n;
        cin >> n;
        if(n % 2)
        {
            for(int i = 0; i < n; i++)
                cout << 1 << " ";
            cout << endl;
        }
        else
        {
            cout << 1 << " " << 3 << " ";
            for(int i = 0; i < n - 2; i++)
                cout << 2 << " ";
            cout << endl;
        }
    }
    return 0;

}