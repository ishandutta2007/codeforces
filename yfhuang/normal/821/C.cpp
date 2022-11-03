#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

const int maxn = 3e5 + 5;

stack<pair<int,bool> > S;
int n;

int main(){
    cin >> n;
    int tot = 0;
    int ans = 0;
    for(int i = 1;i <= 2 * n;i++){
        // cout << S.top().first << endl;
        char s[10];
        scanf("%s",s);
        if(s[0] == 'r'){
            tot++;
            if(S.top().first == tot){
                bool f = S.top().second;
                S.pop();
                if(f && !S.empty()){
                    S.top().second = 1;
                }
            }else{
                if(S.top().second == 1){
                    S.pop();
                    if(!S.empty())S.top().second = 1;
                }else{
                    ans++;
                    S.pop();
                    if(!S.empty())S.top().second = 1;
                }
            }
        }else{
            int num;
            scanf("%d",&num);
            S.push(make_pair(num,0));
        }
    }
    cout << ans << endl;
    return 0;
}

/*
 5 4 3
 1 2 1
 2 3 1
 3 4 1
 4 5 1
 1 2 3 4
 2 3 1 2
 3 4 3 4
 */