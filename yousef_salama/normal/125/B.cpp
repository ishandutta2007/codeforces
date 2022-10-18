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
    cin >> s;
    int h = 0, j;
    for(int i = 0; i < s.size(); i++){
        for(j = i; s[j] != '>'; j++);
        bool found = false;
        if(j - i > 2)
            h--;
        else found = true;
        for(int i = 0; i < 2 * h; i++)
            cout << ' ';
        cout << s.substr(i, j - i + 1) << endl;
        if(found)h++;
        i = j;
    }
    return 0;
}