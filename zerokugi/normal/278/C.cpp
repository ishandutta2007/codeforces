#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;


int n,m,f;
char know[101][101];
char graph[101][101];
int visited[101];
void fill(int s){
    visited[s]=1;
    for(int j=0;j<n;j++){
        if(!visited[j] && graph[s][j]) fill(j);
    }
}

main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int d;
        cin >> d;
        if(d)f=1;
        if(n==1 && d==0){
            cout << "1" << endl;
            return 0;
        }
        for(int j=0;j<d;j++){
            int l;
            cin >> l;
            know[i][l-1] = 1;
        }
    }
    for(int i=0;i<=m;i++){
        for(int j=0;j<n;j++){
            if(know[j][i]){
                for(int k=0;k<n;k++){
                    if(know[k][i]) graph[j][k] = 1;
                }
            }
        }
    }
    int ans=0;
    
    for(int i=0;i<n;i++){
        if(visited[i]) continue;
        fill(i);
        ans++;
    }
    cout << ans-f << endl;
    return 0;
}