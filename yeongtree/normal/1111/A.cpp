#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a,b; cin >> a >> b;
    if(a.size() != b.size()) {cout << "No"; return 0;}
    int n = a.size();
    for(int i = 0; i < n; ++i)
    {
        bool x,y;
        if(a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u')
            x = true;
        else x = false;
        if(b[i] == 'a' || b[i] == 'e' || b[i] == 'i' || b[i] == 'o' || b[i] == 'u')
            y = true;
        else y = false;

        if(x != y) {cout << "No"; return 0;}
    }
    cout << "Yes";
    return 0;
}