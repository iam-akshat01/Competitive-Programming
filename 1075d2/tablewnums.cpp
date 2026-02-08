#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,h,l;
        cin>>n>>h>>l;
        vector<int>numbs;
        for(int i=0;i<n;i++){
            int el;
            cin>>el;
            numbs.push_back(el);
        }
        sort(numbs.begin(),numbs.end());
        int gre=max(l,h);
        int low=min(l,h);
        int idx=upper_bound(numbs.begin(),numbs.end(),gre)-numbs.begin();
        idx--;
        int s=0,e=idx;
        int cnt=0;
        while(s<e){
            if(numbs[s]<=low){
                cnt++;
            }
            s++,e--;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
