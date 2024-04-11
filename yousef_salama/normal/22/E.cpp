#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <limits.h>
#include <limits>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <sstream>
using namespace std;
int n, f[100005], d[100005], en[100005];
bool v[100005];
vector < pair <int, int> > a, b;
void rec(int i){
    v[i] = true;
    if(!v[f[i]])rec(f[i]);
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &f[i]);
        d[--f[i]]++;
    }
    for(int i = 0; i < n; i++){
        if(d[i] != 0){
            rec(i);
            break;
        }
    }
    bool ok = true;
    for(int i = 0; i < n; i++)
        if(!v[i])ok = false;

    if(ok){
        cout << 0 << endl;
        return 0;
    }


    memset(v, 0, sizeof v);
    memset(en, -1, sizeof en);
    for(int i = 0; i < n; i++){
        if(d[i] == 0){
            int j = i;
            while(!v[j]){
                v[j] = true;
                j = f[j];
            }
            int p = i;
            while(p != j){
                en[p] = j;
                p = f[p];
            }
            if(en[j] == -1)en[i] = j;
            else en[i] = en[j];

            a.push_back(make_pair(i + 1, en[i] + 1));
        }
    }
    for(int i = 0; i < n; i++){
        if(!v[i]){
            a.push_back(make_pair(i + 1, i + 1));
            int j = i;
            while(!v[j]){
                v[j] = true;
                j = f[j];
            }
        }
    }
    for(int i = 0; i < a.size(); i++)
        b.push_back(make_pair(a[i].second, a[(i + 1) % a.size()].first));
    cout << b.size() << endl;
    for(int i = 0; i < b.size(); i++)
        cout << b[i].first << ' ' << b[i].second << endl;
    return 0;
}