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

#include <ext/hash_set>
#include <ext/hash_map>

using namespace __gnu_cxx;

int main(){
//    freopen("a.in", "r", stdin);
    int n, sum = 0, m, x, y, z;
    cin >> n;
    vector <int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        sum += v[i];
    }
    if(sum % n != 0)cout << "Unrecoverable configuration." << endl;
    else{
        vector <string> print;
        m = sum / n;
        int a = 0, i, j, cnt = 0;
        for(int i = 0; i < n; i++){
            if(v[i] != m){
                if(cnt == 1){
                    cout << "Unrecoverable configuration." << endl;
                    return 0;
                }
                a = abs(v[i] - m);
                for(int j = i + 1; j < n; j++){
                    if(v[j] != m){
                        if(v[j] + a == m){
                            cnt++;
                            x = a;
                            y = j + 1;
                            z = i + 1;
                            v[i] -= a;
                            v[j] += a;
                            break;
                        }
                        else if(v[j] - a == m){
                            cnt++;
                            x = a;
                            y = i + 1;
                            z = j + 1;
                            v[j] -= a;
                            v[i] += a;
                            break;
                        }
                        else{
                            cout << "Unrecoverable configuration." << endl;
                            return 0;
                        }
                    }
                }
            }
        }
        if(cnt == 0)cout << "Exemplary pages." << endl;
        else printf("%d ml. from cup #%d to cup #%d.\n", x, y, z);
    }
    return 0;
}