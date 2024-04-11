#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        string s; cin >> s;
        bool f = false, g = false;
        int sum = 0;
        for(auto i : s)
        {
            int x = i - '0';
            if(x == 0)
            {
                if(f) g = true;
                else f = true;
            }
            else if(!(x & 1)) g = true;
            sum += x;
        }

        if(f && g && (sum % 3 == 0)) cout << "red\n";
        else cout << "cyan\n";
    }
}