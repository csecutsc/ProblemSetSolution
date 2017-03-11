#include<bits/stdc++.h>
#define needforspeed ios::sync_with_stdio(0);cin.tie(0);
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define endl '\n'
#define pb push_back
#define mp make_pair
#define mp3(a,b,c) make_pair(a,make_pair(b,c))
#define mp4(a,b,c,d) make_pair(make_pair(a,b),make_pair(c,d))
#define trace1(a) cout (#a) << ":" << (a) << endl;
#define trace2(a,b) cout << (#a) << ":" << (a)  << " "<< (#b) << ":" << (b) << endl;
#define trace3(a,b,c) cout << (#a) << ":" << (a)  << " "<< (#b) << ":" << (b) << " "<< (#c) << ":" << (c) << endl;
#define trace4(a,b,c,d) cout << (#a) << ":" << (a)  << " " << (#b) << ":" << (b) << " " (#c) << ":" << (c) <<  " "<< (#d) << ":" << (d) << endl;
#define trace5(a,b,c,d,e) cout << (#a) << ":" << (a)  << " " << (#b) << ":" << (b) << " " (#c) << ":" << (c) <<  " "<< (#d) << ":" << (d) << " " << (#e) << ":" << (e) << endl;
#define ms(a,b) memset( (a), (b), sizeof(a))
#define fi(x) freopen(x,"r",stdin)
#define fo(x) freopen(x,"w",stdout)
#define all(x) (x).begin(),(x).end()
#define len(x) (int)(x).size()
#define xx first
#define yy second
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define MAXN 105 
#define inf 0x3f3f3f3f
#define nullptr 0
#define db 0
using namespace std;

int N,M;
int item[MAXN];
vector<pair<int,int>>adj[MAXN];// node, weight
int dist[MAXN];

int dijkstra(){
    // dist, node
    priority_queue<pair<int,int>>q;
    q.push(mp(0,0));
    ms(dist,inf);
    dist[0] = 0;
    while(!q.empty()){
        pair<int,int>state = q.top();
        int cdist = -state.xx; 
        int cnode = state.yy;
        q.pop();
        for(auto &edge:adj[cnode]){
            int nextnode = edge.xx;
            int weight  = edge.yy; 
            if(cdist+weight < dist[nextnode]){
                dist[nextnode] = cdist+weight;
                q.push(mp(-dist[nextnode],nextnode));
            }
        }
    }
    return dist[N-1];
}

int rec(int n, int cdist, int citems){
    if(n == N-1){
        return citems;
    }
    int ret = 0;
    for(auto &edge:adj[n]){
        int nextnode = edge.xx;
        int weight  = edge.yy; 
        int items = item[nextnode];
        if(cdist+weight <= dist[nextnode])
            ret = max(ret, rec(nextnode, cdist+weight, citems+items));
    }
    return ret;
}

int main() {
    needforspeed;
    cin >> N;
    for(int i = 0;i < N;i++){
        cin >> item[i];
    }
    cin >> M;
    for(int i = 0;i < M;i++){
        int u,v,w;
        cin >> u >> v >>w;
        adj[--u].pb(mp(--v,w)); 
        adj[v].pb(mp(u,w)); 
    }
    int path = dijkstra();
    int best = rec(0, 0, item[0]);   
    if(path == inf)
        cout << "impossible" << endl;
    else
        cout << path << " " << best << endl; 
    return 0;
}
