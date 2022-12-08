#include <iostream>
using namespace std;

int markers[1005][1005];
int cdiam[1005];
int capc[100005];
int capd[100005];

int main()
{
    int N, M;
    cin >> N >> M;

    for(int i=0; i<N; i++)
    {
        int a, b;
        cin >> a >> b;
        markers[a][b]++;
        cdiam[b]++;
    }
    int closed=0, bclosed=0;

    for(int i=0; i<M; i++)
    {
        cin >> capc[i] >> capd[i];
        if(markers[capc[i]][capd[i]]>0)
        {
            bclosed++;
            closed++;
            markers[capc[i]][capd[i]]--;
            cdiam[capd[i]]--;
            capc[i]=0;
            capd[i]=0;
        }
    }

    for(int i=0; i<M; i++)
    {
        if(cdiam[capd[i]]>0)
        {
            closed++;
            cdiam[capd[i]]--;
        }
    }

    cout << closed << " " << bclosed << endl;
}