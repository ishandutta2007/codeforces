#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <set>
#define pii pair<int, int>
#define piii pair<int, pii>
#define pll pair<long long, long long>
#define plll pair<long long, pll>
#define tiii tuple<int, int, int>
#define tiiii tuple<int, int, int, int>
#define ff first
#define ss second
#define ee ss.ff
#define rr ss.ss
#define DEBUG
const int INF = (int)1e9 + 7;

using namespace std;

int match = 0;
const int MAX = 1010;
vector<int> adj[1010];

int N, M, A[MAX], B[MAX];
// adj[i]: A[i]   B 
bool visited[MAX];

// A   a    true
bool dfs(int a){
    visited[a] = true;
    for(int b: adj[a]){
        //   
        //            
        if(B[b] == -1 || !visited[B[b]] && dfs(B[b])){
            A[a] = b;
            B[b] = a;
            return true;
        }
    }
    //  
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, X; cin >> n >> X;
    int A[n]; for(auto &i : A) cin >> i;
    sort(A, A + n);
    if(A[n - 1] * 2 + 1 > X) { cout << -1; return 0; }

    vector<int> B, C;
    for(auto x : A)
    {
        if(3 * x <= X) B.push_back(x);
        else C.push_back(x);
    }

    int N = B.size(), M = C.size();
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            if(C[j] % B[i] == 0 && 2 * C[j] + B[i] <= X) adj[i].push_back(j);
        }
    }
    fill(::A, ::A+N, -1);
    fill(::B, ::B+M, -1);

    for(int i=0; i<N; i++){
        //     A    
        if(::A[i] == -1){
            // visited  
            fill(visited, visited+N, false);
            if(dfs(i)) match++;
        }
    }

    if(match != M) cout << -1;
    else
    {
        cout << N << '\n';
        for(int i = 0; i < N; ++i)
        {
            if(::A[i] != -1)
            {
                int x = ::A[i];
                cout << 2 * C[x] + B[i] << ' ' << C[x] + B[i] << '\n';
            }
        else cout << 3 * B[i] << ' ' << 2 * B[i] << '\n';
        }
    }
}