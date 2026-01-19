#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int sum=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            int el;
            cin>>el;
            maxi=max(maxi,el);
        }
        sum=maxi*n;
        cout<<sum<<endl;
    }
    return 0;
}