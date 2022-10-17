#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int n1 = 0, n2 = 0;
    char arr[n]; for(char &i : arr){cin >> i; if(i == '(') ++n1; else if(i == ')') ++n2;}

    if(n & 1){cout << ":("; return 0;}
    int res = (n >> 1) - n1; if(res < 0){cout << ":("; return 0;}

    int st = 0;
    for(int i = 0; i < n; ++i)
    {
        if(st <= 0 && i){cout << ":("; return 0;}

        if(arr[i] == '(') ++st;
        else if(arr[i] == ')') --st;
        else if(res){arr[i] = '('; --res; ++st;}
        else{arr[i] = ')'; --st;}
    }

    for(char &i : arr) cout << i;
    return 0;
}