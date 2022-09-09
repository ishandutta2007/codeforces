#include<bits/stdc++.h>
using namespace std;
const int N=500005;
struct atom{
	char c;
	int len;
};
char c[N];
vector<atom>a,b;
vector<pair<int,int> >ans;
int i,j;
void work(vector<atom>a,vector<atom>b){
	for(;;){
		if(a.size()==1 && b.size()==1 && a[0].c!=b[0].c)break;
		if(a.back().c==b.back().c){
			int sa=a.size(),sb=b.size();
			if(sb==1){
				ans.push_back(make_pair(a.back().len,0));
				b.push_back(a.back());a.pop_back();
			}else if(sa==1){
				ans.push_back(make_pair(0,b.back().len));
				a.push_back(b.back());b.pop_back();
			}else{
				auto opt=[&](vector<atom>&a,vector<atom>&b,int sa,int sb){
					atom x=a[sa-1],y=a[sa-2],z=b[sb-1];
					ans.push_back({x.len+y.len,z.len});
					a.pop_back();a.pop_back();b.pop_back();
					a.push_back(z);b.back().len+=y.len;b.push_back(x);
				};
				if(sa>sb)opt(a,b,sa,sb);else opt(b,a,sb,sa),
					swap(ans.back().first,ans.back().second);
			}
		}else{
			ans.push_back(make_pair(a.back().len,b.back().len));
			swap(a.back(),b.back());
		}
		while(a.size()>1 && a.back().c==a[a.size()-2].c){
			a[a.size()-2].len+=a.back().len;
			a.pop_back();
		}
		while(b.size()>1 && b.back().c==b[b.size()-2].c){
			b[b.size()-2].len+=b.back().len;
			b.pop_back();
		}
	}
}
int main(){
	scanf("%s",c+1);
	for(i=1;c[i];++i){
		if(c[i]!=c[i-1])a.push_back((atom){c[i],1});
			else ++a.back().len;
	}
	scanf("%s",c+1);
	for(i=1;c[i];++i){
		if(c[i]!=c[i-1])b.push_back((atom){c[i],1});
			else ++b.back().len;
	}
	auto calcw=[&](int sa,int sb,int ca,int cb){
		if(sa<sb)swap(sa,sb);
		return sb==1?sa==1 && ca==cb?1:sa-1:ca!=cb?sa-1:sb+(sa-sb>>1);
	};
	int x=0,y=0,sa=a.size(),sb=b.size(),mn=calcw(sa,sb,a[0].c,b[0].c);
	vector<int>va,vb;
	for(i=0;i<min(sa,5);++i)va.push_back(i),va.push_back(sa-i);
	for(i=0;i<min(sb,5);++i)vb.push_back(i),vb.push_back(sb-i);
	for(i=max(0,(sa+sb)/2-5);i<=min(max(sa,sb),(sa+sb)/2+5);++i)
		if(sa>sb)va.push_back(i);else vb.push_back(i);
	auto unq=[&](vector<int>&v){sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end());};
	unq(va);unq(vb);
	for(int i:va)for(int j:vb){
		int nsa,nsb,nca,ncb,ww;
		nsa=sa-i+j;nsb=sb-j+i;
		nca=j?b[0].c:i==a.size()?-1:a[i].c;
		ncb=i?a[0].c:j==b.size()?-1:b[j].c;
		if(j && i<a.size())nsa-=b[j-1].c==a[i].c;
		if(i && j<b.size())nsb-=a[i-1].c==b[j].c;
		ww=calcw(nsa,nsb,nca,ncb)+1;
		if(ww<mn)mn=ww,x=i,y=j;
	}
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	if(x || y){
		vector<atom>aa(a.begin()+a.size()-x,a.end()),bb(b.begin()+b.size()-y,b.end());
		a.resize(a.size()-x);b.resize(b.size()-y);
		int sa=0,sb=0;for(auto u:aa)sa+=u.len;for(auto u:bb)sb+=u.len;
		ans.push_back({sa,sb});
		auto doo=[&](vector<atom>&a,vector<atom>&z){
			if(!z.empty() && z[0].c==a.back().c)a.back().len+=z[0].len,z.erase(z.begin());
			a.insert(a.end(),z.begin(),z.end());
		};
		doo(a,bb);doo(b,aa);
	}
	work(a,b);
	printf("%d\n",int(ans.size()));
	for(i=0;i<ans.size();++i)printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}