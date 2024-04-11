#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <iostream>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

char s[205];
int st, en, len;
int main(){
    scanf("%s", &s);
    len = strlen(s);
    for(st = 0; st + 2 < len; st += 3){
        if(s[st] != 'W' || s[st + 1] != 'U' || s[st + 2] != 'B')break;
    }
    for(en = len - 1; en - 2 >= 0; en -= 3){
        if(s[en - 2] != 'W' || s[en - 1] != 'U' || s[en] != 'B')break;
    }

    bool flag = false;
    for(int i = st; i <= en; ){
        if(i + 2 <= en){
            if(s[i] == 'W' && s[i + 1] == 'U' && s[i + 2] == 'B'){
                if(!flag)printf(" ");
                flag = true;

                i += 3;
                continue;
            }
        }
        flag = false;
        printf("%c", s[i]);
        i++;
    }
    printf("\n");
}