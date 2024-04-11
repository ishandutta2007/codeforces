#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
typedef vector<int> vi;
const int N=1e5+7;
int n;
char str[N];
bool vis[N];
set<int>s[2];
vector<vi>vec[4];
int main(){
    scanf("%s",str+1),n=strlen(str+1);
    for(int i=1;i<=n;i++)s[str[i]=='L'].insert(i);
    int ans=0;
    for(int i=1;i<=n;i++)
	if(!vis[i]){
	    int o=str[i]=='L',x=i;vi buf;ans++;
	    while(1){
		vis[x]=1,s[o].erase(x);
		buf.push_back(x),o^=1;
		auto it=s[o].lower_bound(x);
		if(it==s[o].end())break;
		x=*it;
	    }
	    o^=1;
	    if(str[i]=='L'){
		if(o)vec[0].push_back(buf);
		else vec[2].push_back(buf);
	    }else if(o)vec[3].push_back(buf);
	    else vec[1].push_back(buf);
	}
    printf("%d\n",ans-1);
    for(int i=0;i<(int)min(vec[2].size(),vec[3].size());i++){
	vi r1=vec[2][i],r2=vec[3][i];
	if(r1.back()<r2.back())r1.push_back(r2.back()),r2.pop_back();
	else r2.push_back(r1.back()),r1.pop_back();
	vec[0].push_back(r1),vec[1].push_back(r2);
    }
    auto out = [](vi a)->void{for(int x:a)printf("%d ",x);};
    bool fl1=vec[2].size()<vec[3].size(),fl2=vec[3].size()<vec[2].size();
    if(vec[0].size()<vec[1].size()){
	for(int i=0;i<(int)vec[1].size();i++){
	    if(fl1){fl1=0;for(int j=vec[2].size();j<(int)vec[3].size();j++)out(vec[3][j]);}
	    out(vec[1][i]);
	    if(fl2){fl2=0;for(int j=vec[3].size();j<(int)vec[2].size();j++)out(vec[2][j]);}
	    if(i<(int)vec[0].size())out(vec[0][i]);
	}
    }else{
	for(int i=0;i<(int)vec[0].size();i++){
	    if(fl2){fl2=0;for(int j=vec[3].size();j<(int)vec[2].size();j++)out(vec[2][j]);}
	    out(vec[0][i]);
	    if(fl1){fl1=0;for(int j=vec[2].size();j<(int)vec[3].size();j++)out(vec[3][j]);}
	    if(i<(int)vec[1].size())out(vec[1][i]);
	}
    }
    if(fl1){fl1=0;for(int j=vec[2].size();j<(int)vec[3].size();j++)out(vec[3][j]);}
    if(fl2){fl2=0;for(int j=vec[3].size();j<(int)vec[2].size();j++)out(vec[2][j]);}
    return 0;
}