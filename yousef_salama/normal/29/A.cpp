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
    int n, x, d;
    cin >> n;
    vector <pair<int, int> > v(n);
    for(int i = 0; i < n; i++){
        cin >> x >> d;
        v[i] = make_pair(x, d);
    }
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            if(v[i].first + v[i].second == v[j].first && v[j].first + v[j].second == v[i].first){
                cout << "YES" << endl;
                return 0;
            }
    cout << "NO" << endl;
    return 0;
}