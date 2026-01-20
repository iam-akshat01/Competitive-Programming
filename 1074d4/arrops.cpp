#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t;
    cin >> t;

    while (t--) {
        ll n, m, h;
        cin >> n >> m >> h;

        vector<ll> base(n), add(n, 0);
        for(int i=0;i<n;i++){
            cin>>base[i];
        }
    
        vector<int>indexes;
        for(int i=0;i<m;i++){
            ll idx,val;
            cin>>idx>>val;
            
            add[idx-1]+=val;
            indexes.push_back(idx-1);
            if(add[idx-1]+base[idx-1]>h){
            
                int x=indexes.size();
                for(int i=x-1;i>=0;i--){
                    add[indexes[i]]=0;
                    indexes.pop_back();
                }
            }
        }

        for(int i=0;i<n;i++){
                cout<<base[i]+add[i]<<" ";
            }
            cout<<endl;
            continue;
        }
        
    return 0;
}
