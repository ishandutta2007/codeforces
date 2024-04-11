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

int n, p[55], a[5];
ll x, c[5];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &p[i]);
    for(int i = 0; i < 5; i++)
        scanf("%d", &a[i]);

    x = 0;
    for(int i = 0; i < n; i++){
        x += p[i];
        for(int j = 4; j >= 0; j--){
            ll y = x / a[j];
            c[j] += y;

            x -= y * a[j];
        }
    }
    for(int i = 0; i < 5; i++){
        if(i != 0)printf(" ");
        printf("%I64d", c[i]);
    }
    printf("\n%I64d\n", x);
}