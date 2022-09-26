#include <iostream>
 
using namespace std;
 
int main()
{
        long long x, y;
        
        cin >> x;
        cin >> y;
        
        if(x > 0 && y > 0)
        {
                cout << "0 " << x + y << " " << x + y << " 0" << endl;
        }
        else if(x < 0 && y > 0)
        {
                cout << x - y << " 0 " << "0 " << y - x << " " << endl;
        }
        else if(x < 0 && y < 0)
        {
                cout << x + y << " 0 " << "0 " << x + y << endl;
        }
        else
        {
                cout << "0 " << y - x << " " << x - y << " 0" << endl;
        }
        return 0;
}