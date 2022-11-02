#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
int t;

int n;
const int maxn = 2e5 + 5;
char s[maxn];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        scanf("%s", s + 1);
        int flag = 0;
        for(int i = 1;i < n;i++){
            if(s[i + 1] < s[i]){
                flag = i;
                break;
            }
        }
        if(!flag){
            for(int i = 1;i <= n;i++){
                putchar('1');
            }
            cout << endl;
        }else{
            vector<int> a, b;
            for(int i = 1;i <= flag;i++){
                if(s[i] <= s[flag + 1]){
                    a.push_back(i);
                }else{
                    b.push_back(i);
                }
            } 
            a.push_back(flag + 1);
            for(int i = flag + 2;i <= n;i++){
                if(s[i] > s[b[0]])
                    b.push_back(i);
                if(s[i] < s[b[0]])
                    a.push_back(i);
                if(s[i] == s[b[0]]){
                    if(s[i] >= s[b[b.size() - 1]]){
                        b.push_back(i);
                    }else{
                        a.push_back(i);
                    }
                }
            }
            bool ok = true;
            for(int i = 0;i < a.size() - 1;i++){
                if(s[a[i + 1]] < s[a[i]])
                    ok = false;
            }
            for(int i = 0;i < b.size() - 1;i++){
                if(s[b[i + 1]] < s[b[i]])
                    ok = false;
            }
            if(s[a[a.size() - 1]] > s[b[0]])
                ok = false;
            if(ok){
                for(int i = 0;i < a.size();i++){
                    s[a[i]] = '1';
                }
                for(int i = 0;i < b.size();i++){
                    s[b[i]] = '2';
                }
                s[n + 1] = 0;
                printf("%s\n", s + 1);
            }else{
                printf("-\n");
            }
        }
    }

    return 0;
}