#include<bits/stdc++.h>

using namespace std;

int N;
int arr[1005];
int sz[1005];
bool seq[1005];


int main()
{
    freopen("busnumbers_input.txt","r",stdin);
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
