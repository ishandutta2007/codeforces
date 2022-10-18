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

char s[1000005];
int N, z[1000005];
int main(){
    scanf("%s", &s);
    N = strlen(s);

    for(int i = 1, L = 0, R = 0; i < N; i++){
        if(i <= R)
            z[i] = min(R - i + 1, z[i - L]);
        while(i + z[i] < N && s[z[i]] == s[i + z[i]])
            z[i]++;
        if(i + z[i] - 1 > R)
            L = i, R = i + z[i] - 1;
    }

    int Max = 0;
    for(int i = 1; i < N; i++){
        if(i + z[i] == N && Max >= N - i){
            for(int j = i; j < N; j++)
                printf("%c", s[j]);
            printf("\n");

            return 0;
        }
        Max = max(Max, z[i]);
    }
    printf("Just a legend\n");
}