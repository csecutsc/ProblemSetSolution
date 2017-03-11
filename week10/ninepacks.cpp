#include<bits/stdc++.h>
#define MAXN 1000
#define MAXDP 1000*(MAXN+1)
#define DEBUG(X,Y) cout << #X << " " << X << " " << #Y << " " << Y << endl;
#define INF 0x3f3f3f3f

using namespace std;

int H, B;
int hot[MAXN+1], bun[MAXN+1];
int dp_hot[MAXDP], dp_bun[MAXDP];
bool vis[MAXN+1];

void rec(int *dp_arr, int size_dp, int *values, int size_val, 
         int csum, int celem){
    for(int i = 0;i < size_val;i++){
        if(!vis[i] && dp_arr[csum+values[i]] > celem+1){
            dp_arr[csum+values[i]] = celem+1;
            vis[i] = true;
            rec(dp_arr, size_dp, values, size_val, csum+values[i], celem+1);
            vis[i] = false;
        }
    }

}

void calc_dp(int *dp_arr, int size_dp, int *values, int size_val){
    memset(dp_arr, INF, sizeof(int)*size_dp);
    memset(vis, false, sizeof(vis));
    for(int i = 0;i < size_val;i++){
        dp_arr[values[i]] = 1;
        vis[i] = true;
        rec(dp_arr, size_dp, values, size_val, values[i], 1);
        vis[i] = false;
    }
}


int main() {
    cin >> H;
    for(int i = 0;i < H;i++){
        cin >> hot[i];
    }
    sort(hot, hot+H);
    cin >> B;
    for(int i = 0;i < B;i++){
        cin >> bun[i];
    }
    sort(bun, bun+B);
    calc_dp(dp_hot, MAXDP, hot, H);
    calc_dp(dp_bun, MAXDP, bun, B);
    int ans = INF;
    for(int i = 0;i < MAXDP;i++){
        if(dp_hot[i] != INF && dp_bun[i] != INF){
            if(ans > dp_hot[i]+dp_bun[i]){
                ans = dp_hot[i]+dp_bun[i];
            }
        }
    }
    if(ans == INF){
        cout << "impossible" << endl;
    } else{
        cout << ans << endl;
    }
    return 0;
}

