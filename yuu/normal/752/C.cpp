#include <bits/stdc++.h>
using namespace std;
#define one __builtin_popcount
#define onbit(s, i) (s|(1<<(i)))
#define bit(s, i) ((s>>i)&1)
int n;
string s;

int main(){
//    freopen("C.INP", "r", stdin);
    cin>>n>>s;
    int state=0;
    int cnt=0;
    for(int i=0; i<n; i++){
        if(s[i]=='L'){
            if(bit(state, 1)){
                cnt++;
                state=0;
            }
            state=onbit(state, 0);
        }
        else if(s[i]=='R'){
            if(bit(state, 0)){
                cnt++;
                state=0;
            }
            state=onbit(state, 1);
        }
        else if(s[i]=='U'){
            if(bit(state, 3)){
                cnt++;
                state=0;
            }
            state=onbit(state, 2);
        }
        else if(s[i]=='D'){
            if(bit(state, 2)){
                cnt++;
                state=0;
            }
            state=onbit(state, 3);
        }
    }
    cout<<cnt+1;
}