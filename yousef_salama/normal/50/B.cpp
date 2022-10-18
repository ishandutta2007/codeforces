#include <iostream>
#include <map>
#include <math.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    long long ans = 0;
    map <char,long long> chars;
    for(int i =0;i<s.size();i++)chars[s[i]]++;
    map <char,long long> :: iterator it;
    for (it = chars.begin();it != chars.end();it++){
        ans += pow((*it).second,2);
    }
    cout << ans;
}