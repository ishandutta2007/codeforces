#include <iostream>
#include <vector>

using namespace std;

int b[50][50];

vector<int> x, y;

int dx[4] = {-1, -1, 0, 0};
int dy[4] = {-1, 0, -1, 0};

int main(){
    int n, m;
    cin >> n >> m;
    int a[50][50];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 1 && b[i][j] == 0){
                int tx = -1, ty = -1;
                for(int k = 0; k < 4; k++){
                    if(i+dx[k] < 0 || j+dy[k] < 0) continue;
                    for(int l = 0; l < 4; l++){
                        if(i+dx[k]+1+dx[l] >= n || j+dy[k]+1+dy[l] >= m) continue;
                        if(a[i+dx[k]+1+dx[l]][j+dy[k]+1+dy[l]] == 0) break;
                        if(l == 3){
                            tx = i+dx[k];
                            ty = j+dy[k];
                            if(l == 1) l++;
                        }
                    }                    
                }
                if(tx == -1 || ty == -1){
                    cout << -1 << endl;
                    return 0;
                }
                x.push_back(tx+1);
                y.push_back(ty+1);
                for(int l = 0; l < 4; l++){
                    b[tx+dx[l]+1][ty+dy[l]+1] = 1;
                }
            }
        }
    }
    cout << x.size() << endl;
    for(int i = 0; i < x.size(); i++){
        cout << x[i] << ' ' << y[i] << endl;;
    }
}