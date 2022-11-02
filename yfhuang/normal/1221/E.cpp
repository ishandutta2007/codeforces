#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>

using namespace std;

int q;
const int maxn = 3e5 + 5;

char s[maxn];
int a, b;
vector<int> seg;
int main(){
    cin >> q;
    while(q--){
        seg.clear();
        cin >> a >> b;
        scanf("%s", s + 1);
        int n = strlen(s + 1);
        s[++n] = 'X';
        int cnt = 0;
        for(int i = 1;i <= n;i++){
            if(s[i] == 'X'){
                if(cnt >= b)
                    seg.push_back(cnt);
                cnt = 0;
            }else{
                cnt++;
            }
        }
        bool flag = false;
        for(auto v : seg){
            if(v >= a)
                flag = true;
        }
        if(!flag){
            cout << "NO" << endl;
            continue;
        }
        int cnt1 = 0;
        for(auto v : seg){
            if(v >= 2 * b)
                cnt1++;
        }
        if(cnt1 >= 2){
            cout << "NO" << endl;
            continue;
        }
        cnt1 = 0;
        for(auto v : seg){
            if(v < a and v >= b){
                cnt1++;
            } 
        }
        if(cnt1 >= 1){
            cout << "NO" << endl;
            continue;
        }
        sort(seg.begin(), seg.end());
        int len = seg[seg.size() - 1];
        if(len < 2 * b){
            if(seg.size() % 2){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }else{
            bool flag = false;
            int num = seg.size() - 1;
            for(int i = 1;i + a - 1 <= len;i++){
                int t1 = i - 1;
                int t2 = len - (i + a - 1);
                bool now = false;
                if(t1 >= 2 * b or (t1 < a and t1 >= b))
                    now = true;
                if(t2 >= 2 * b or (t2 < a and t2 >= b))
                    now = true;
                int tmp = num;
                if(!now){
                    if(t1 >= a and t1 < 2 * b){
                        tmp++; 
                    }
                    if(t2 >= a and t2 < 2 * b){
                        tmp++;
                    }
                    if(tmp % 2 == 0){
                        flag = true;
                    }
                }
            }
            if(flag){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }

    }
    return 0;
}