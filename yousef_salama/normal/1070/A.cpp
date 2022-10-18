#include <bits/stdc++.h>
using namespace std;

int main(){
    int d, s;
    scanf("%d %d", &d, &s);

    vector < vector <int> > dist(d, vector <int> (s + 1, -1));
    vector < vector <int> > parent_rem(d, vector <int> (s + 1));
    vector < vector <int> > parent_sum(d, vector <int> (s + 1));
    queue < pair <int, int> > q;

    dist[0][0] = 0;
    parent_rem[0][0] = -1;
    parent_sum[0][0] = -1;
    q.push(make_pair(0, 0));

    while(!q.empty()){
        pair <int, int> p = q.front();
        q.pop();

        int rem = p.first, sum = p.second;
        for(int i = 0; i <= 9; i++){
            int nrem = (rem * 10 + i) % d, nsum = sum + i;
            if(nsum > s)break;

            if(dist[nrem][nsum] == -1){
                dist[nrem][nsum] = dist[rem][sum] + 1;
                parent_rem[nrem][nsum] = rem;
                parent_sum[nrem][nsum] = sum;
                q.push(make_pair(nrem, nsum));
            }
        }
    }

    if(dist[0][s] == -1){
        printf("-1\n");
        return 0;
    }

    int rem = 0, sum = s;
    string num = "";
    while(parent_rem[rem][sum] != -1){
        int i = sum - parent_sum[rem][sum];
        num += i + '0';

        rem = parent_rem[rem][sum];
        sum = sum - i;
    }
    reverse(num.begin(), num.end());
    cout << num << '\n';

    return 0;
}