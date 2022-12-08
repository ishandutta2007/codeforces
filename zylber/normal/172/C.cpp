#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int ans[100010];

int main()
{
    int N, M;
    cin >> N >> M;

    vector < pair <int,int> > pasajeros(N);
    for(int i=0; i<N; i++)
    cin >> pasajeros[i].first >> pasajeros[i].second;
    int time=0;
    for(int i=0; i<N; i+=M)
    {
        time = max(time,pasajeros[min(N-1,i+M-1)].first);
        vector< pair <int,int> > bus(M);
        if(i+M>N)
        bus.resize(N-i);
        for(int j=i; j<min(N,i+M); j++)
        bus[j-i]=make_pair(pasajeros[j].second,j);
        sort(bus.begin(),bus.end());
        time+=bus[0].first;
        ans[bus[0].second]=time;
        int s=bus.size(), cant=1;
        for(int i=1; i<s; i++)
        {
            time+=bus[i].first-bus[i-1].first;
            if(bus[i].first==bus[i-1].first)
            cant++;
            else
            {
                time+=1+cant/2;
                cant=1;
            }

            ans[bus[i].second]=time;
        }
        time+=bus[s-1].first+1+cant/2;
    }
    for(int i=0; i<N-1; i++)
    cout << ans[i] << " ";
    cout << ans[N-1] << endl;
}