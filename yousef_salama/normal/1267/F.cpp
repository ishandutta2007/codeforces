#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, ka, kb;
    scanf("%d %d %d %d", &n, &m, &ka, &kb);

    vector <int> deg(n + m, 1);

    vector <int> a(ka);
    for(int i = 0; i < ka; i++){
        scanf("%d", &a[i]);
        a[i]--;

        deg[a[i]]++;
    }
    
    vector <int> b(kb);
    for(int i = 0; i < kb; i++){
        scanf("%d", &b[i]);
        b[i]--;

        deg[b[i]]++;
    }

    int rem_a = n + m - 1 - accumulate(deg.begin(), deg.begin() + n, 0);
    if(rem_a < 0){
        printf("No\n");
        return 0;
    }
    
    for(int i = 0; i < n; i++){
        int c = min(m - deg[i], rem_a);
        deg[i] += c;
        rem_a -= c;
    }

    int rem_b = n + m - 1 - accumulate(deg.begin() + n, deg.end(), 0);
    if(rem_b < 0){
        printf("No\n");
        return 0;
    }

    for(int i = n; i < n + m; i++){
        int c = min(n - deg[i], rem_b);
        deg[i] += c;
        rem_b -= c;
    }

    set <int> s;
    for(int i = 0; i < n + m; i++){
        if(deg[i] == 1){
            s.insert(i);
        }
    }

    vector < pair <int, int> > edges;
    int a_i = 0, a_j = 0, b_i = 0, b_j = n;

    int cnt = n + m;
    vector <bool> vis(n + m, false);
    
    while(!s.empty()){
        int u = *s.begin();
        s.erase(s.begin());

        cnt--;
        if(cnt == 1)break;
        vis[u] = true;
        
        /*cout << cnt << ',' << u + 1 << " :: ";
        for(int i = 0; i < n + m; i++)
            cout << i + 1 << ":" << deg[i] << ' ';
        cout << endl;*/

        if(u < n){
            if(b_i < kb){
                edges.push_back(make_pair(u, b[b_i]));
                deg[b[b_i]]--;
                if(deg[b[b_i]] == 1)s.insert(b[b_i]);
                b_i++;
            }else{
                while(deg[b_j] == 1)b_j++;

                edges.push_back(make_pair(u, b_j));
                deg[b_j]--;
                if(deg[b_j] == 1)s.insert(b_j);
            }
        }else{
            if(a_i < ka){
                edges.push_back(make_pair(a[a_i], u));
                deg[a[a_i]]--;
                if(deg[a[a_i]] == 1)s.insert(a[a_i]);
                a_i++;
            }else{
                while(deg[a_j] == 1)a_j++;

                edges.push_back(make_pair(a_j, u));
                deg[a_j]--;
                if(deg[a_j] == 1)s.insert(a_j);
            }
        }
    }
    for(int i = 0; i < n + m; i++)if(!vis[i]){
        for(int j = i + 1; j < n + m; j++)if(!vis[j]){
            edges.push_back(make_pair(i, j));
            break;
        }
        break;
    }

    printf("Yes\n");
    for(auto e : edges)
        printf("%d %d\n", e.first + 1, e.second + 1);

    return 0;
}