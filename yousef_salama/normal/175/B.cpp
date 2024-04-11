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
int n, best[1005], m = 0, score;
map <string, int> mp;
string s, names[1005];
int main(){
    cin >> n;
    while(n--){
        cin >> s >> score;
        if(!mp.count(s)){
            names[m] = s;
            mp[s] = m++;
        }
        best[mp[s]] = max(best[mp[s]], score);
    }
    cout << m << endl;
    for(int i = 0; i < m; i++){
        cout << names[i] << ' ';
        int cnt = 0;
        for(int j = 0; j < m; j++)
            if(best[j] <= best[i])cnt++;
        int per = cnt * 100 / m;
        if(per >= 99)cout << "pro" << endl;
        else if(per >= 90)cout << "hardcore" << endl;
        else if(per >= 80)cout << "average" << endl;
        else if(per >= 50)cout << "random" << endl;
        else cout << "noob" << endl;
    }
    return 0;
}