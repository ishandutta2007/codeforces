#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

typedef long long LL;

LL MX = ((1LL << 32) - 1);

stack<pair<LL, LL> > st;
int main(){
    LL val = 0;
    int l;
    cin >> l;
    bool flag = false;
    for(int i = 1;i <= l;i++){
        char s[505];
        scanf("%s", s);
        if(s[0] == 'a'){
            st.push(make_pair(0, 1)); 
        }else if(s[0] == 'e'){
            LL now = 0;
            while(!st.empty()){
                pair<LL, LL> x = st.top();st.pop();
                if(x.first == 0){
                    now += x.second;
                }else{
                    LL loop = x.second;
                    if(MX / loop < now){
                        flag = true;
                    }else{
                        st.push(make_pair(0, loop * now));
                    }
                    break;
                }
            }
        }else{
            LL n;
            scanf("%lld", &n);
            st.push(make_pair(1, n)); 
        }
    }
    while(!st.empty()){
        pair<LL, LL> x = st.top(); st.pop();
        if(MX - val < x.second){
            flag = true;
        }else{
            val += x.second;
        }
    }
    if(flag){
        cout << "OVERFLOW!!!" << endl;
    }else{
        cout << val << endl;
    }
    return 0;
}