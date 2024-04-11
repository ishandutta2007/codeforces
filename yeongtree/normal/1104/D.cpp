#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

int min(int x, int y) {return (x<y)?x:y;}

int main()
{
    string T;

    while(1)
    {
        cin >> T;
        if(T == "mistake" || T == "end") break;

        char re;
        cout << "? 0 1\n";
        fflush(stdout);
        cin >> re;
        if(re == 'x') {cout << "! 1\n"; fflush(stdout); continue;}
        else if(re == 'e') break;

        int b = 2 , e = (int)1e9 + 1;
        bool flag = false;
        while(b + 1 < e)
        {
            int mid = min(b * 2 , (b + e) / 2 - 1);
            cout << "? " << mid / 2 << ' ' << mid << '\n';
            fflush(stdout);
            cin >> re;

            if(re == 'x') e = mid + 1;
            else if(re == 'y') b = mid + 1;
            else {flag = false; break;}
        }

        if(flag) break;
        cout << "! " << b << '\n';
        fflush(stdout);
    }

    return 0;
}