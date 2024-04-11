#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

const int maxn = 3e5 + 5;

string s[maxn];
string t[maxn];
int n, m;
char ch[4] = {'A', 'G', 'C', 'T'};

int main(){
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin >> s[i];
        t[i] = s[i];
    }
    int p[4] = {0, 1, 2, 3}; 
    int cnt = 0;
    int ans = n * m + 1;
    string ansstr = "";
    do{
        for(int i = 0;i < n;i++){
            if(i & 1){
                int tmp1 = 0;
                for(int j = 0;j < m;j++){
                    t[i][j] = ch[p[j & 1]];
                }
                for(int j = 0;j < m;j++){
                    if(t[i][j] != s[i][j])
                        tmp1++;
                }
                string t1 = t[i];
                int tmp2 = 0;
                for(int j = 0;j < m;j++){
                    t[i][j] = ch[p[(j & 1) ^ 1]];
                }
                for(int j = 0;j < m;j++){
                    if(t[i][j] != s[i][j])
                        tmp2++;
                }
                if(tmp1 < tmp2)
                    t[i] = t1;
            }else{
                int tmp1 = 0;
                for(int j = 0;j < m;j++){
                    t[i][j] = ch[p[(j & 1) + 2]];
                }
                for(int j = 0;j < m;j++){
                    if(t[i][j] != s[i][j])
                        tmp1++;
                }
                string t1 = t[i];
                int tmp2 = 0;
                for(int j = 0;j < m;j++){
                    t[i][j] = ch[p[((j & 1) ^ 1) + 2]];
                }
                for(int j = 0;j < m;j++){
                    if(t[i][j] != s[i][j])
                        tmp2++;
                }
                if(tmp1 < tmp2)
                    t[i] = t1;
            }
        }
        int tmp = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(s[i][j] != t[i][j])
                    tmp++;
            }
        }
        if(tmp < ans){
            ans = tmp;
            ansstr = "";
            for(int i = 0;i < n;i++){
                ansstr += t[i];
            }
        }
        for(int j = 0;j < m;j++){
            if(j & 1){
                int tmp1 = 0;
                for(int i = 0;i < n;i++){
                    t[i][j] = ch[p[i & 1]];
                }
                for(int i = 0;i < n;i++){
                    if(t[i][j] != s[i][j])
                        tmp1++;
                }
                string t1 = "";
                for(int i = 0;i < n;i++){
                    t1 += t[i][j];
                }
                int tmp2 = 0;
                for(int i = 0;i < n;i++){
                    t[i][j] = ch[p[(i & 1) ^ 1]];
                }
                for(int i = 0;i < n;i++){
                    if(t[i][j] != s[i][j])
                        tmp2++;
                }
                if(tmp1 < tmp2){
                    for(int i = 0;i < n;i++){
                        t[i][j] = t1[i];
                    }
                }
            }else{
                int tmp1 = 0;
                for(int i = 0;i < n;i++){
                    t[i][j] = ch[p[(i & 1) + 2]];
                }
                for(int i = 0;i < n;i++){
                    if(t[i][j] != s[i][j])
                        tmp1++;
                }
                string t1 = "";
                for(int i = 0;i < n;i++){
                    t1 += t[i][j];
                }
                int tmp2 = 0;
                for(int i = 0;i < n;i++){
                    t[i][j] = ch[p[((i & 1) ^ 1) + 2]];
                }
                for(int i = 0;i < n;i++){
                    if(t[i][j] != s[i][j])
                        tmp2++;
                }
                if(tmp1 < tmp2){
                    for(int i = 0;i < n;i++){
                        t[i][j] = t1[i];
                    }
                }
            }
        }
        tmp = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(s[i][j] != t[i][j])
                    tmp++;
            }
        }
        if(tmp < ans){
            ans = tmp;
            ansstr = "";
            for(int i = 0;i < n;i++){
                ansstr += t[i];
            }
        }
    }while(next_permutation(p, p + 4));
    for(int i = 0;i < n;i++){
        cout << ansstr.substr(i * m, m) << endl;
    }
    return 0;
}