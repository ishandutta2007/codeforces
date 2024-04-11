#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 3123, inf = 1e9;
const ll INF = 1e18;

int n, l[N], r[N], sz[N];
int id = -1;
char a[N][N], b[N][N];
bool need[N];
vector<int> z_function (string s) {
	int n = (int) s.length();
	vector<int> z (n);
	for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
	return z;
}
bool check(string s, string t){
	string S = t + "$" + s;
	vector < int > z = z_function(S);
	for(int i = t.size(); i < S.size(); i++)
		if(z[i] == t.size())
			return 1;
	return 0;
}

int main(){
	scanf("%d", &n);      
	for(int i = 0; i < n; i++)
		scanf("%s", a[i]);
	for(int i = 0; i < n; i++)
		scanf("%s", b[i]);
	for(int i = 0; i < n; i++){
		sz[i] = strlen(a[i]);
		for(int j = 0; j < sz[i]; j++)	
			if(a[i][j] != b[i][j]){
				if(!need[i])
					l[i] = r[i] = j;
				need[i] = 1;
				l[i] = min(l[i], j);
				r[i] = max(r[i], j);
			}          
		if(!need[i])
			continue;
		bool ok = 1;
		if(id == -1)
			id = i;
		if(r[i] - l[i] == r[id] - l[id]){
			for(int j = 0; j < r[i] - l[i]; j++)
				if(a[i][l[i] + j] != a[id][l[id] + j] || b[i][l[i] + j] != b[id][l[id] + j])
					ok = 0;
		}else
			ok = 0;
		if(!ok){
			cerr << i << endl;
			puts("NO");
			return 0;
		}
	}
	while(true){
		bool ok = 1;
		for(int i = 0; i < n; i++){
			if(!need[i])
				continue;
			if(l[i] > 0){
				if(a[i][l[i] - 1] != a[id][l[id] - 1] || b[i][l[i] - 1] != b[id][l[id] - 1])
					ok = 0;
			}else
				ok =0;	
		}
		if(!ok)
			break;	
		for(int i = 0; i < n; i++)
			l[i]--;
	}
    while(true){
		bool ok = 1;
		for(int i = 0; i < n; i++){
			if(!need[i])
				continue;
			if(r[i] + 1 < sz[i]){
				if(a[i][r[i] + 1] != a[id][r[id] + 1] || b[i][r[i] + 1] != b[id][r[id] + 1])
					ok = 0;
			}else
				ok =0;	
		}
		if(!ok)
			break;	
		for(int i = 0; i < n; i++)
			r[i]++;
	}
	for(int i = 0; i < n; i++){
		string s = "";
		if(need[i])
        	for(int j = 0; j < r[i]; j++)
				s += a[i][j];
		else
			for(int j = 0; j < sz[i]; j++)
				s += a[i][j];
			
		string t = "";
		for(int j = l[id]; j <= r[id]; j++)
			t += a[id][j];
		if(check(s, t)){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	for(int i = l[id]; i <= r[id]; i++)
		printf("%c", a[id][i]);
	printf("\n");
	for(int i = l[id]; i <= r[id]; i++)
		printf("%c", b[id][i]);
	return 0;
}