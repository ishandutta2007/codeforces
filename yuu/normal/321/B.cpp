#include <bits/stdc++.h>
using namespace std;
int n, m;
vector <int> atk;
vector <int> def;
string pos;
int p[101];
int f[102][102][102][2];
int main(){
	cin>>n>>m;
	for(int i=0, s; i<n; i++){
		cin>>pos>>s;
		if(pos=="ATK") atk.push_back(s);
		else def.push_back(s);
	}
	sort(atk.begin(), atk.end());
	sort(def.begin(), def.end());
	for(int i=0; i<m; i++) cin>>p[i];
	sort(p, p+m);
	for(int i=0; i<=atk.size(); i++) for(int j=0; j<=def.size(); j++) for(int k=0; k<=m; k++)	for(int b=0; b<2; b++) f[i][j][k][b]=-1e9;
	f[0][0][0][0]=f[0][0][0][1]=0;
	for(int i=0; i<=atk.size(); i++) for(int j=0; j<=def.size(); j++) for(int k=0; k<=m; k++){
		f[i+1][j][k][0]=max(f[i+1][j][k][0], f[i][j][k][0]);
		f[i][j+1][k][0]=max(f[i][j+1][k][0], f[i][j][k][0]);
		f[i][j][k+1][0]=max(f[i][j][k+1][0], f[i][j][k][0]);
		f[i][j][k+1][1]=max(f[i][j][k+1][1], f[i][j][k][1]+p[k]);
		if(i!=atk.size())	if(p[k]>=atk[i]){
			f[i+1][j][k+1][0]=max(f[i+1][j][k+1][0], f[i][j][k][0]+p[k]-atk[i]);
			f[i+1][j][k+1][1]=max(f[i+1][j][k+1][1], f[i][j][k][1]+p[k]-atk[i]);
		}
		if(j!=def.size())	if(p[k]>def[j]) f[i][j+1][k+1][1]=max(f[i][j+1][k+1][1], f[i][j][k][1]);
	}
	cout<<max(f[atk.size()][def.size()][m][0], f[atk.size()][def.size()][m][1])<<'\n';
}