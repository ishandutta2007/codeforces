//In the name of Allah

#include <bits/stdc++.h>
using namespace std;

int n, m, a[1005][1005], b[1005][1005], c[1005][1005], res[1000005];

struct query{
    int t, x1, y1, x2, y2;
};


vector < pair <int, pair <int, int> > > X;

void add(int x, int y, int k){
    x++, y++;
    
    while(x < 1005){
        int yi = y;
        while(yi < 1005){
            c[x][yi] += k;
            yi += yi & (-yi);
        }
        x += x & (-x);
    }
}
int sum(int x, int y){
    x++, y++;
    
    int r = 0;
    while(x > 0){
        int yi = y;
        while(yi > 0){
            r += c[x][yi];
            yi -= yi & (-yi);
        }
        x -= x & (-x);
    }
    return r;
}

bool test(int k, query x){
    if((x.x2 - x.x1 + 1) < k)return false;
    if((x.y2 - x.y1 + 1) < k)return false;
    
    int s = sum(x.x2, x.y2) -
            sum(x.x1 - 1 + max(k - 1, 0), x.y2) -
            sum(x.x2, x.y1 - 1 + + max(k - 1, 0)) +
            sum(x.x1 - 1 + max(k - 1, 0), x.y1 - 1 + max(k - 1, 0));
    return s > 0;
}


void solve(int L, int R, vector <query> &v){
    if(L > R)return;
    
    int mid = (L + R) / 2;
    
    stack < pair <int, pair <int, int> > > to_add;
    
    //cout << "------------------" << endl;
    //cout << L << ',' << R << ':' << endl;
 
    while(!X.empty()){
        pair <int, pair <int, int> > d = X.back();
        if(d.first < mid){
            add(d.second.first, d.second.second, -1);
            to_add.push({d.first, {d.second.first, d.second.second}});
            
            X.pop_back();
        }else break;
    }
    
    vector <query> vL, vR;
    for(int i = 0; i < v.size(); i++){
        bool ok;
        if(test(mid, v[i])){
            res[v[i].t] = mid;
            vR.push_back(v[i]);
        
            ok = true;
        }else{
            vL.push_back(v[i]);
            
            ok = false;
        }
        //cout << v[i].x1 << ',' << v[i].y1 << ' ' << v[i].x2 << ',' << v[i].y2 << "   " << ok << endl;    
    }
    solve(mid + 1, R, vR);
    
    while(!to_add.empty()){
        pair <int, pair <int, int> > t = to_add.top();
        to_add.pop();
        
        add(t.second.first, t.second.second, 1);
        X.push_back(t);
    }
    solve(L, mid - 1, vL);
}

int main(){
    scanf("%d %d", &n, &m);
    //n = 1000, m = 1000;
    
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++){
        scanf("%d", &a[i][j]);
    	//a[i][j] = rand() % 2;
    }
    
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++){
        if(a[i][j] == 0)b[i][j] = 0;
        else{
            if((i == 0) && (j == 0))b[i][j] = 1;
            else if(i == 0)b[i][j] = 1;
            else if(j == 0)b[i][j] = 1;
            else{
                int s = min(b[i - 1][j], b[i][j - 1]);
                if(a[i - s][j - s] == 1)b[i][j] = s + 1;
                else b[i][j] = s;
            }
        }
    }
    
    /*for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cout << b[i][j] << ' ';
        cout << endl;
    }*/
    
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++){
        X.push_back({b[i][j], {i, j}});
        add(i, j, 1);
    }
    sort(X.rbegin(), X.rend());
    
    vector <query> v;
    
    int t;
    scanf("%d", &t);
   	//t = 1000000;
    
    for(int q = 0; q < t; q++){
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        a--, b--, c--, d--;
        
        //a = q % n, b = q / n;
        //c = n - 1, d = m - 1;
        
        v.push_back({q, a, b, c, d});
    }
    
    solve(0, min(n, m), v);
    
    for(int i = 0; i < t; i++)
        printf("%d\n", res[i]);
    
    return 0;
}