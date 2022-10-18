//In the name of allah
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <list>

using namespace std;
int main ()
{
    string a,b,c = "";
    cin >> a >> b;
    for (int i = a.size()-1;i>=0;i--){
        c += a[i];
    }
    if (b == c)cout << "YES";
    else cout << "NO";
}