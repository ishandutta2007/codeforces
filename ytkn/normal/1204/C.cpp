#include <iostream>
#include <vector>

#define N_MAX 100
#define INF 100000

using namespace std;

void find_shortest_pair(int dist[N_MAX][N_MAX], int edge[N_MAX][N_MAX], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dist[i][j] = edge[i][j];
        }
        dist[i][i] = 0;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                int new_len = dist[j][i] + dist[i][k];
                dist[j][k] = min(new_len, dist[j][k]);
            }
        }
    }
}

int v[1000000];

int main(){
    int n;
    int e[100][100];
    int d[100][100];
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char c;
            cin >> c;
            if(c == '0') e[i][j] = INF;
            else e[i][j] = 1;
        }
    }
    find_shortest_pair(d, e, n);
    int k;
    cin >> k;
    for(int i = 0; i < k; i++){
        cin >> v[i];
        v[i]--;
    }
    
    int cnt = 1;
    int prev = v[0];
    vector<int> ans;
    ans.push_back(v[0]);
    for(int i = 1; i < k; i++){
        //cout << prev << ':' << v[i] << endl;
        //cout << d[prev][v[i]] << ' ' << cnt << endl;
        if(d[prev][v[i]] == cnt){
            cnt++;
        }else{
            ans.push_back(v[i-1]);
            prev = v[i-1];
            cnt = 2;
        }
    }
    ans.push_back(v[k-1]);
    cout << ans.size() << endl;

    for(int i = 0; i+1 < ans.size(); i++){
        cout << ans[i]+1 << ' ';
    }
    cout << ans[ans.size()-1]+1 << endl;
}