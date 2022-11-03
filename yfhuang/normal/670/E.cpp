//
//  main.cpp
//  E
//
//  Created by  on 16/5/6.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;

int n,m,p;

const int maxn = 500000 + 5;

int pre[maxn],suf[maxn];

int Left[maxn],Right[maxn];

bool vis[maxn];
char s[maxn];
char opt[maxn];

int main(int argc, const char * argv[]) {
    cin >> n >> m >> p;
    suf[0] = 1,pre[n + 1] = n;
    for(int i = 1;i <= n;i++)
        pre[i] = i - 1,suf[i] = i + 1;
    memset(vis,true,sizeof(vis));
    scanf("%s",s + 1);
    scanf("%s",opt + 1);
    stack<int> st;
    for(int i = 1;i <= n;i++){
        if(s[i] == '('){
            st.push(i);
        }else{
            Left[i] = st.top();
            st.pop();
        }
    }for(int i = n;i >= 1;i--){
        if(s[i] == ')'){
            st.push(i);
        }else{
            Right[i] = st.top();
            st.pop();
        }
    }
    for(int i = 1;i <= m;i++){
        if(opt[i] == 'L'){
            p = pre[p];
        }else if(opt[i] == 'R'){
            p = suf[p];
        }else{
            if(s[p] =='('){
                suf[pre[p]] = suf[Right[p]];
                pre[suf[Right[p]]] = pre[p];
                if(suf[Right[p]] <= n){
                    p = suf[Right[p]];
                }else{
                    p = pre[p];
                }
            }else{
                suf[pre[Left[p]]] = suf[p];
                pre[suf[p]] = pre[Left[p]];
                if(suf[p] <= n){
                    p = suf[p];
                }else{
                    p = pre[Left[p]];
                }
            }
        }
    }
    //cout << suf[0] << endl;
    //for(int i = 1;i <= n;i++){
    //    cout << pre[i] << endl;
    //    cout << suf[i] << endl;
    //}
    for(int i = suf[0];i != n + 1;i = suf[i]){
        printf("%c",s[i]);
    }
    puts("");
    return 0;
}