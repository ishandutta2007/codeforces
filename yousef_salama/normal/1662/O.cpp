#include <bits/stdc++.h>
using namespace std;

const int MAXR = 50;
const int MAXA = 800;

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);

        vector < vector <bool> > blocked(MAXR, vector <bool> (MAXA, false));
        vector < vector <bool> > vis(MAXR, vector <bool> (MAXA, false));

        while(n--){
            char type;
            scanf(" %c", &type);

            if(type == 'C'){
                int r, theta1, theta2;
                scanf("%d %d %d", &r, &theta1, &theta2);

                r *= 2;
                theta1 *= 2;
                theta2 *= 2;

                for(int i = theta1; ; i = (i + 1) % 720){
                    blocked[r][i] = true;
                    if(i == theta2)break;
                }
            }else{
                int r1, r2, theta;
                scanf("%d %d %d", &r1, &r2, &theta);

                r1 *= 2;
                r2 *= 2;
                theta *= 2;

                for(int i = r1; i <= r2; i++)
                    blocked[i][theta] = true;
            }
        }

        auto dfs = [&](auto self, int i, int j) -> void {
            vis[i][j] = true;

            if(i + 1 < MAXR && !blocked[i + 1][j] && !vis[i + 1][j])self(self, i + 1, j);
            if(i > 0 && !blocked[i - 1][j] && !vis[i - 1][j])self(self, i - 1, j);
            if(!blocked[i][(j + 1) % 720] && !vis[i][(j + 1) % 720])self(self, i, (j + 1) % 720);
            if(!blocked[i][(j + 719) % 720] && !vis[i][(j + 719) % 720])self(self, i, (j + 719) % 720);
        };

        dfs(dfs, 0, 0);

        if(vis[MAXR - 1][0])printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}