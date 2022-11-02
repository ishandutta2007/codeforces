#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

const int maxn = 5e5 + 5;
int t;
int n;
int a[maxn];
int b[maxn];
int p[maxn];
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1;i <= n;i++){
            scanf("%d", &a[i]);
            if(a[i] == -1){
                a[i] = i + 1;
            }
            b[i] = 0;
        }
        stack<int> s;
        bool flag = true;
        int base = 0;
        for(int i = 1;i <= n;i++){
            if(!s.empty()){
                while(!s.empty() and s.top() == i){
                    s.pop();
                }
            }
            if(!s.empty()){
                if(a[i] > s.top()){
                    flag = false;
                    break;
                }
            }
            //if(s.empty()){
            //    base = b[i];
            //    b[i] = 0;
            //}
            base = max(base, b[i]);
            p[i] = base + (a[i] - i);
            //cout << i << " " << p[i] << endl;
            b[a[i]] = max(b[a[i]], p[i]);
            s.push(a[i]);
        } 
        if(flag){
            for(int i = 1;i <= n;i++){
                printf("%d%c", p[i], i == n ? '\n' : ' ');
            }
        }else{
            cout << -1 << endl;
        }
    }
    return 0;
}