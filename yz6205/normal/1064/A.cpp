#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    int mx = max(max(a,b) , c);
    cout << max(0,mx + mx - a - b - c + 1) << endl;
    return 0;
}