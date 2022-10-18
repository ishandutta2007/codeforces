#include <iostream>
#include <vector>
#include <string>
#include <stack>
#define FOR(i,n) for(int i =0;i<n;i++)
using namespace std;
int main()
{
    string s,a = "";
    cin >> s;
    a += s[0];
    for (int i = 1;i<s.size();i++){
        if (a[a.size()-1] == s[i])a.erase(a.size()-1,1);
        else a += s[i];
    }
    cout << a << endl;
}