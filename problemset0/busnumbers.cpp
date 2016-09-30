#include<bits/stdc++.h>
#define endl '\n'
#define needforspeed ios_base::sync_with_stdio (false);cin.tie();
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define len(x) (int)(x).size()
#define ms(a,b) memset( (a), (b), sizeof( (a) ) )
#define xx first
#define yy second
#define LL long long
#define DB 0
#define MAXN 1005
#define inf 0x3f3f3f3f
using namespace std;

int N;
int arr[MAXN];
int sz[MAXN];
bool seq[MAXN];


int main()
{
    freopen("busnumbers_input.txt","r",stdin);
    needforspeed;
    cin >> N;
    for(int i = 0;i < N;i++)
    {
        cin >> arr[i];
        sz[i] = 1;
    }
    sort(arr,arr+N);
    for(int i = N-1;i > 0;i--)
    {
        if(arr[i] == arr[i-1]+1)
        {
           sz[i-1] += sz[i]; 
           seq[i] = true;
        } 
    }
    for(int i = 0;i < N-1;i++)
    {
        if(!seq[i] && seq[i+1] && sz[i] > 2)
            cout << arr[i] << "-";
        if(!seq[i] && seq[i+1] && sz[i] == 2)
            cout << arr[i] << " ";
        if(!seq[i] && !seq[i+1])
            cout << arr[i] << " ";
        if(seq[i] && !seq[i+1])
            cout << arr[i] << " ";
    }
    cout << arr[N-1] << endl;
    return 0;
}
