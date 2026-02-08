#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;

        vector<ll> a(n), b(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];

        vector<pair<int,int>> queries(q);
        for(int i = 0; i < q; i++){
            int l, r;
            cin >> l >> r;
            queries[i] = {l-1, r-1};
        }

        for(int i = n-1; i >= 0; i--){
            if(i == n-1)
                a[i] = max(a[i], b[i]);
            else
                a[i] = max({a[i], b[i], a[i+1]});
        }

        vector<ll> presum(n);
        presum[0] = a[0];
        for(int i = 1; i < n; i++)
            presum[i] = presum[i-1] + a[i];

        for(auto [l, r] : queries){
            ll ans = presum[r] - (l ? presum[l-1] : 0);
            cout << ans << " ";
        }
        cout << "\n";
    }
    return 0;
}
