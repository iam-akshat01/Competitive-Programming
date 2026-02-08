#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        int fpod=n;
        for(int i=0;i<n;i++){
            int el;
            cin>>el;
            arr[i]=el;
        }
        int idx1=-1;
        for(int i=0;i<n;i++){
            if(arr[i]!=fpod){
                idx1=i;
                break;
            }
            fpod--;
        }
        int idx=-1;
        for(int i=0;i<n;i++){
            if(arr[i]==fpod){
                idx=i;
                break;
            }
        }
        reverse(arr.begin()+idx1,arr.begin()+idx+1);
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}