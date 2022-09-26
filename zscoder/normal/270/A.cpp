#include <iostream>

using namespace std;

int main()
{
    int t, a;
    
    cin >> t;
    
    int i, j;
    
    bool ans = false;

    for(i = 0; i < t; i++)
    {
        cin >> a;
        for(j = 3; j <= 360; j++)
        {
            if(((double)(a*j)/(j-2)) == 180)
            {
                cout << "YES" << endl;
                ans = true;
                break;
            }
        }
        if(!ans)
        {
            cout << "NO" << endl;
        }
        ans = false;
    }
    
    return 0;
}