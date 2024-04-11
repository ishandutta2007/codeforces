#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, mod = (int)1e9 + 7, inf = (int)1e9;
int n, x, del = -1, m;
vector< pii > v[3];
bool was[N];
void get(int i,int j){
	if(was[j] || i == j)
		return;
	was[i] = 1;
	cout << 1 << " " << i + 1<< " " << j + 1<<endl;
}
void any(){
	int pos = -1;
	for(int i = 0; i < n; i++)
		if(!was[i] && i!=del)
			pos = i;
	if(del != -1)
		cout << 2 << " " << del + 1 <<endl;
	for(int i = 0; i < n; i++){
		if( was[i] || i == pos || i == del)
			continue;
		get(i, pos);
	}
	exit(0);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> x;
    	
    	if(x < 0)
    		v[0].pb({x, i});
    	if(x == 0)
    		v[1].pb({x, i});
    	if(x > 0)
    		v[2].pb({x, i});
    }
    if(v[1].size() == n)
    	any();
    if(v[1].size() == n - 1 && v[0].size() == 1){
        del=v[0][0].s;
    	any();
    }
    sort(v[0].begin(),v[0].end());
   
    if(!v[1].empty())
    	del = v[1][0].s;
    
    if(v[0].size()%2 == 1)
    	del = (v[0].back()).s;
    for(int i = 0; i < v[1].size(); i++)
    	get(v[1][i].s, del);
	
	any();
	return 0;
}