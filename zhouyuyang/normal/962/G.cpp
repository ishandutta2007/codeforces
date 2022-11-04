#include<bits/stdc++.h>
#define ll long long
#define pli pair<ll,int>
#define pll pair<ll,ll>
using namespace std;

int h,w;

int get(int x,int y){
	if (!y) return x;
	if (x==h) return h+y;
	if (y==w) return h+w+(h-x);
	return h+w+h+(w-y); 
}

vector<pll > get(int h,int w,int x,int a,int b){
	vector<pll > ans;
	if (a<=0&&b<=0) return ans;
	if (a>=w&&b>=w) return ans;
	if (x>=h||x<=0) return ans;
	if (a>0&&a<w&&b>0&&b<w) return ans;
	int fl=0;
	if (a>b) swap(a,b),fl=1;
	if (a<=0&&b>=w){
		ans.push_back(pll(x,0));
		ans.push_back(pll(x,w));
	}
	else if (a>0)
		ans.push_back(pll(x,w));
	else ans.push_back(pll(x,0));
	if (fl) reverse(ans.begin(),ans.end());
	return ans;
}

#define N 120005

int x[N],y[N];
bool vis[N];
vector<int> e[N];

void add(int x,int y){
	e[x].push_back(y);
	e[y].push_back(x);
}
void dfs(int x){
	vis[x]=1;
	for (int i=0;i<e[x].size();i++)
		if (!vis[e[x][i]]) dfs(e[x][i]);
}

int main(){
	int x1,x2,y1,y2;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	swap(y1,y2);
	x1*=2; x2*=2;
	y1*=2; y2*=2;
	h=x2-x1,w=y2-y1;
	int n; scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%d%d",&x[i],&y[i]);
		x[i]*=2; y[i]*=2;
		x[i]-=x1; y[i]-=y1;
	}
	int fl=0;
	for (int i=0;i<n;i++)
		if (x[i]<0||y[i]<0||x[i]>h||y[i]>w){
			rotate(x,x+i,x+n);
			rotate(y,y+i,y+n);
			fl=1; break;
		}
	if (!fl)
		return puts("1"),0;
	x[n]=x[0]; y[n]=y[0];
	int cnt=0;
	vector<pli > vec;
	for (int i=0;i<n;i++)
		if (x[i]==x[i+1]){
			vector<pll > tmp=get(h,w,x[i],y[i],y[i+1]);
			for (int j=0;j<tmp.size();j++)
				vec.push_back(pli(get(tmp[j].first,tmp[j].second),cnt++));
		}
		else{
			vector<pll> tmp=get(w,h,y[i],x[i],x[i+1]);
			for (int j=0;j<tmp.size();j++)
				vec.push_back(pli(get(tmp[j].second,tmp[j].first),cnt++));
		}
	if (!vec.size()){
		int a=h/2,b=w/2;
		double ang=0;
		for (int i=0;i<n;i++)
			ang+=atan2((x[i]-a)*(y[i+1]-b)-(y[i]-b)*(x[i+1]-a),
					   (x[i]-a)*(x[i+1]-a)+(y[i]-b)*(y[i+1]-b));
		printf("%d",abs(ang)<=1?0:1);
		return 0; 
	}
	for (int i=0;i<vec.size();i+=2)
		add(vec[i].second,vec[i+1].second);
	sort(vec.begin(),vec.end());
	for (int i=0;i<vec.size();i++)
		if (vec[i].second==0){
			rotate(vec.begin(),vec.begin()+i,vec.end());
			break;
		}
	rotate(vec.begin(),vec.begin()+1,vec.end());
	for (int i=0;i<vec.size();i+=2)
		add(vec[i].second,vec[i+1].second);
	int ans=0;
	for (int i=0;i<cnt;i++)
		if (!vis[i]) 
			dfs(i),ans++;
	printf("%d",ans);
}