#include <bits/stdc++.h>

#define ll long long

using namespace std;
 
int main(){
    int n,k;
    cin>>n>>k;
    map<int,int> mp;
    for(int i = 0;i<n;i++){
        int x;
        cin>>x;
        mp[x]++;
    }
    ll sum = 0;
    for(ll i = 0;i<n;i++){
        if(mp.find(i) == mp.end()){
            sum += (k * i);
            break;
        }else{
            if(mp[i] < k){
                sum += (i * (k-mp[i]));
                k = mp[i];
            }
        }
    }
    cout<<sum;
    return 0;
}