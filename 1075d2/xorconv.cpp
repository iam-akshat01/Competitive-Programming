#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        ll sum = 1LL * n * (n + 1) / 2;
        vector<int> p(n);

        p[n-1] = 1;

        ll psum = 1;

        for(int i = 1; i < n - 1; i++){
            if((i + 1) % 2 == 0)
                p[i] = i + 2;
            else
                p[i] = i;
            psum += p[i];
        }

        p[0] = sum - psum;
        
        for(int i = 0; i < n; i++){
            cout << p[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}