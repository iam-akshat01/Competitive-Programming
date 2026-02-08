#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        ll n,w;
        cin>>n>>w;
        if(w==1) {
            cout<<0<<endl;
            continue;
        }
        ll quo=n/(w);
        ll rem=n%(w);
        ll ans=(w-1)*quo+rem;
        cout<<ans<<endl;
    }
    return 0;
}