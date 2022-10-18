#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>
#include <bitset>
using namespace std;
bool isRight(string s){
    if(s[0] == '0')return false;
    for(int i = 0; i < s.size(); i++)if(!(s[i] == '4' || s[i] == '7'))
        return false;
    return true;
}
int main(){
    string s;
    cin >> s;
    map <string, int> mp;
    for(int i = 0; i < s.size(); i++)
        for(int size = 1; size + i <= s.size(); size++){
            string a = s.substr(i, size);
            if(isRight(a))
                mp[a]++;
        }
    vector <pair <int, string> > v;
    map <string, int> :: iterator it;
    for(it = mp.begin(); it != mp.end(); it++)
        v.push_back(make_pair(it->second, it->first));
    sort(v.rbegin(), v.rend());
    if(v.size() == 0){
        cout << "-1" << endl;
        return 0;
    }
    string best = v[0].second;
    for(int i = 1; i < v.size(); i++){
        if(v[i].first < v[i - 1].first)
           break;
        else{
            if(v[i].second < best)
                best = v[i].second;
        }
    }
    cout << best << endl;
}