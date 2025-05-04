#include<iostream>
#include<vector>

using namespace std;

void solve(){
    int k , q;
    cin>> k >> q>> endl;

    vector<int> a(k);
    for(int i=0; i<k; i++){
        cin>> a[i];
    }

    vector<int> n(q);
    for(int i=0; i<q; i++){
        cin>> n;

    // If number of players is less than first element in sequence
     // all players win as no one gets eliminated
    if(n < a[0]){
        cout<< n<< " ";
    }
    // If number of players is >= first element
     // only players with numbers less than a[0] win
    else{
        cout<< a[0]-1<< " ";
    }
    }
        cout<<"\n";

}

int main(){
    cin.tie(nullptr);
    while(t--){
        solve();
    }
    return 0;
}