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
int n, m, L[1005][1005], R[1005][1005], U[1005][1005], D[1005][1005], d[1005][1005][4];
struct state{
    int i, j, dir;
    state(int a, int b, int c){
        i = a;
        j = b;
        dir = c;
    }
};
deque <state> q;
string s[1005];
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> s[i];
        s[i] = "." + s[i] + ".";
        if(i == n - 1)s[i][m + 1] = '#';
    }

    m += 2;
    for(int i = 0; i < n; i++){
        int temp = -1;
        for(int j = 0; j < m; j++){
            L[i][j] = temp;
            if(s[i][j] == '#')temp = j;
        }
        temp = -1;
        for(int j = m - 1; j >= 0; j--){
            R[i][j] = temp;
            if(s[i][j] == '#')temp = j;
        }
    }
    for(int j = 0; j < m; j++){
        int temp = -1;
        for(int i = 0; i < n; i++){
            U[i][j] = temp;
            if(s[i][j] == '#')temp = i;
        }
        temp = -1;
        for(int i = n - 1; i >= 0; i--){
            D[i][j] = temp;
            if(s[i][j] == '#')temp = i;
        }
    }

    q.push_back(state(0, 0, 1));
    memset(d, -1, sizeof d);
    d[0][0][1] = 0;

    while(!q.empty()){
        state cur = q.front();
        q.pop_front();

        if(U[cur.i][cur.j] != -1){
            if(d[U[cur.i][cur.j]][cur.j][0] == -1){
                if(cur.dir == 0)q.push_front(state(U[cur.i][cur.j], cur.j, 0));
                else q.push_back(state(U[cur.i][cur.j], cur.j, 0));

                d[U[cur.i][cur.j]][cur.j][0] = d[cur.i][cur.j][cur.dir] + (cur.dir != 0);
            }
        }
        if(D[cur.i][cur.j] != -1){
            if(d[D[cur.i][cur.j]][cur.j][2] == -1){
                if(cur.dir == 2)q.push_front(state(D[cur.i][cur.j], cur.j, 2));
                else q.push_back(state(D[cur.i][cur.j], cur.j, 2));

                d[D[cur.i][cur.j]][cur.j][2] = d[cur.i][cur.j][cur.dir] + (cur.dir != 2);
            }
        }
        if(R[cur.i][cur.j] != -1){
            if(d[cur.i][R[cur.i][cur.j]][1] == -1){
                if(cur.dir == 1)q.push_front(state(cur.i, R[cur.i][cur.j], 1));
                else q.push_back(state(cur.i, R[cur.i][cur.j], 1));

                d[cur.i][R[cur.i][cur.j]][1] = d[cur.i][cur.j][cur.dir] + (cur.dir != 1);
            }
        }
        if(L[cur.i][cur.j] != -1){
            if(d[cur.i][L[cur.i][cur.j]][3] == -1){
                if(cur.dir == 3)q.push_front(state(cur.i, L[cur.i][cur.j], 3));
                else q.push_back(state(cur.i, L[cur.i][cur.j], 3));

                d[cur.i][L[cur.i][cur.j]][3] = d[cur.i][cur.j][cur.dir] + (cur.dir != 3);
            }
        }
    }

    cout << d[n - 1][m - 1][1] << endl;
    return 0;
}