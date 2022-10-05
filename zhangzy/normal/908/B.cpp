#include<bits/stdc++.h>
using namespace std;
int n,m,a[55][55],sx,sy,ex,ey;

int gg(int i,int j){
	char c=getchar();
	for (;;){
		while (c=='\n'||c=='\r') c=getchar();
		if (c=='S'){
			sx=i, sy=j;
			return 1;
		}
		if (c=='E'){
			ex=i, ey=j;
			return 1;
		}
		if (c=='.') return 1;
		if (c=='#') return 0;
	}
} 

int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};
int id[]={0,1,2,3},ans;
char s[233]; int l;

bool ck(){
	int tx=sx,ty=sy;
	for (int i=0,t;i<l;++i){
		t=id[s[i]-'0'];
		tx+=dx[t]; ty+=dy[t];
		if (!a[tx][ty]) return 0;
		if (tx==ex&&ty==ey) return 1;
	}
	return 0;
}

int main(){
    //ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i){
    	for (int j=1;j<=m;++j)
    		a[i][j]=gg(i,j);
    }
    cin>>s; l=strlen(s);
    do{
    	if (ck()) ans++;
    }while (next_permutation(id,id+4));
	cout<<ans;
}