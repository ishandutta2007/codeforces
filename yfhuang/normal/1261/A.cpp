#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int T;
int n, k;
const int maxn = 2005;
char s[maxn];
vector<pair<int, int> > ans;
char t[maxn];

int main(){
    cin >> T;
    while(T--){
        ans.clear();
        cin >> n >> k;
        scanf("%s", s + 1);
        for(int i = 1;i < k;i++){
            t[2 * i - 1] = '(';
            t[2 * i] = ')';
        }
        for(int i = 2 * k - 1, j = n;i < j;i++, j--){
            t[i] = '(';
            t[j] = ')';
        }
//        printf("%s\n", t + 1);
        for(int now = 1;now <= n;now++){
//            printf("%s\n", s + 1);
            if(s[now] != t[now]){
                int p = 0;
                for(int j = now + 1;j <= n;j++){
                    if(s[j] == t[now]){
                        p = j;
                        break;
                    }
                }
                for(int i = now, j = p;i < j;i++,j--){
                    swap(s[i], s[j]);
                }
                ans.push_back(make_pair(now, p));
            } 
        }
        cout << ans.size() << endl;
        for(auto it: ans){
            cout << it.first << " " << it.second << endl;
        } 
    }
    return 0;
}