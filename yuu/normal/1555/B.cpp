#include <bits/stdc++.h>
#define y1 feyqaertgyswrty
#define y2 yysgatweawerry2
using namespace std;
int width, height;
int w, h;
int x1, y1, x2, y2;
int solve(){
	cin>>width>>height;
	cin>>x1>>y1>>x2>>y2;
	cin>>w>>h;
	if(w<=x1) return 0;
	if(x2+w<=width) return 0;
	if(h<=y1) return 0;
	if(y2+h<=height) return 0;
	int dist=1e9;
	if(x2-x1+w<=width){
		dist=min(dist, w-x1);
		dist=min(dist, x2-(width-w));
	}
	if(y2-y1+h<=height){
		dist=min(dist, h-y1);
		dist=min(dist, y2-(height-h));
	}
	if(dist==1e9) dist=-1;
	return dist;
}
int main(){
	int t;
	cin>>t;
	while(t--) cout<<solve()<<'\n';
}