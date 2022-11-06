#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t, m, n, vysl, e, cer;
    cin >> t;
    vector<string> b;
    vector< string > s;
    vector<vector <pair<int, int> > > c;
    vector<pair <int, int> > p;
    vector<int> delka;
    vector<vector <int> > par;
    for(int i=0; i<t; i++){
        vysl=0;
        cin >> n >> m;
        b.resize(n);
        s.resize(n);
        c.resize(n);
        for(int j=0; j<n; j++){
            c[j].resize(m);
            cin >> b[j];
            for(int k=0; k<m; k++){
                c[j][k].first=-1;
                c[j][k].second=0;
            }
        }
        for(int j=0; j<n; j++){
            cin >> s[j];
        }
        int cyk=0;
        delka.resize(0);
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                if(c[j][k].first==-1){
                    p.resize(0);
                    int y=j;
                    int x=k;
                    e=1;
                    while(c[y][x].first==-1){
                        p.push_back({y,x});
                        c[y][x].first=cyk;
                        c[y][x].second=e;
                        e++;
                        if(s[y][x]=='D') y++;
                        else if(s[y][x]=='U') y--;
                        else if(s[y][x]=='L') x--;
                        else if(s[y][x]=='R') x++;
                    }
                    if(c[y][x].first==cyk){
                        vysl+=e-c[y][x].second;
                        delka.push_back(e-c[y][x].second);
                        for(int h=0; h<p.size(); h++){
                            c[p[h].first][p[h].second].second = e-c[p[h].first][p[h].second].second;
                            c[p[h].first][p[h].second].second%=delka.back();
                        }
                        cyk++;
                    }
                    else{
                        for(int h=0; h<p.size(); h++){
                            c[p[h].first][p[h].second].first=c[y][x].first;
                            c[p[h].first][p[h].second].second=((e-c[p[h].first][p[h].second].second+c[y][x].second)%delka[c[y][x].first]);
                        }
                    }
                }
            }
        }
        cer=0;
        par.resize(delka.size());
        for(int j=0; j<delka.size(); j++){
            par[j].resize(delka[j]);
            for(int k=0; k<delka[j]; k++) par[j][k]=0;
        }
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                if(b[j][k]=='0' && par[c[j][k].first][c[j][k].second]==0){
                    cer++;
                    par[c[j][k].first][c[j][k].second]=1;
                }
            }
        }
        cout<< vysl << " " << cer << endl;
    }
    return 0;
}