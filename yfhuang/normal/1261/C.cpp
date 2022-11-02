#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 2e6 + 5;

char a[maxn];
char b[maxn];
int pre[2][maxn];
int n, m;

int calpre(int x, int y, int id){
    if(x < 0 || y < 0)
        return 0;
    if(x >= n)
        x = n - 1;
    if(y >= m)
        y = m - 1;
    return pre[id][x * m + y];
}

void setpre(int x, int y, int val, int id){
    pre[id][x * m + y] = val;
}

bool judge(int x, int y, int t, int id){
    if(x - t < 0 || y - t < 0 || x + t >= n || y + t >= m)
        return false;
    int val = calpre(x + t, y + t, id) - calpre(x - t - 1, y + t, id) - calpre(x + t, y - t - 1, id) + calpre(x - t - 1, y - t - 1, id);
    if(val == 1LL * (2 * t + 1) * (2 * t + 1))
        return true;
    return false;
}

bool check(int t){
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(judge(i, j, t, 0)){
                b[i * m + j] = 'X';
            }else{
                b[i * m + j] = '.';
            }
            //putchar(b[i * m + j]);
        }
        //puts("");
    }
    //cout << t << endl;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            int now = (b[i * m + j] == 'X');           
            int val = calpre(i - 1, j, 1) + calpre(i, j - 1, 1) - calpre(i - 1, j - 1, 1) + now;
            setpre(i, j, val, 1);
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            int x = i, y = j;
            if(a[i * m + j] == '.')
                continue;
            int val = calpre(x + t, y + t, 1) - calpre(x - t - 1, y + t, 1) - calpre(x + t, y - t - 1, 1) + calpre(x - t - 1, y - t - 1, 1);
            if(val == 0)
                return false;
        }
    }
    return true;
}

int main(){
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        scanf("%s", a + i * m);
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            int now = (a[i * m + j] == 'X');           
            int val = calpre(i - 1, j, 0) + calpre(i, j - 1, 0) - calpre(i - 1, j - 1, 0) + now;
            setpre(i, j, val, 0);
        }
    }
    int l = 0, r = min(n, m);
    while(l < r){
        int mid = (l + r + 1) / 2;
        if(check(mid)){
            l = mid;
        }else{
            r = mid - 1;
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(judge(i, j, l, 0)){
                b[i * m + j] = 'X';
            }else{
                b[i * m + j] = '.';
            }
        }
    }
    cout << l << endl;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            putchar(b[i * m + j]);
        }
        puts("");
    }
    return 0;
}