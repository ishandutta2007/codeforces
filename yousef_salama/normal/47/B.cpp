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
using namespace std;
int main(){
    string s;
    int itr = 3, v = 0;
    pair <int, char> m[3];
    for(int i = 0; i < 3; i++){
        m[i].first = 0;
        m[i].second = i + 'A';
    }
    while(itr--){
        cin >> s;
        if(s[1] == '>')m[s[2] - 'A'].first++;
        else m[s[0] - 'A'].first++;
    }
    for(int i = 0; i < 3; i++)v |= 1 << m[i].first;
    if(v != 7){
        cout << "Impossible" << endl;
        return 0;
    }
    sort(m, m + 3);
    for(int i = 2; i >= 0; i--)cout << m[i].second;
    cout << endl;
    return 0;
}