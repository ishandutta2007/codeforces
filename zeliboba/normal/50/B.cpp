#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main () {
    vector<int> count(1000, 0);
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i)
        count[s[i]]++;
    long long res = 0;
    for (int i = 0; i < count.size(); ++i)
        res += count[i] * (long long)count[i];
    cout << res << endl;
    return 0;
}