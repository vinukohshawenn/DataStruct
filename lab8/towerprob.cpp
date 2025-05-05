#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Function to check and apply the maximum blocks that can be transferred.
void blocktrans(){
    int n;
    
    cout<<"Enter the number of towers:";
    cin>>n;
    vector<long long> arr(n);
    cout<<"Enter the elements:";
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    
    sort(ar.begin()+1,ar.end());
    
    for(int i=0;i<n;i++){
        if(ar[i]>ar[0]){
            int value=(ar[i]-ar[0]+1)/2;
            ar[0]=ar[0]+value;
            ar[i]=ar[i]-value;
        }
    }
    cout<<"The largest amount of blocks you can have on the tower after all the moves:"<<ar[0]<<endl;
    
}

//Main Program
int main(){
    int t;
    cout<<"Enter the number of test cases:";
    cin>>t;
    while(t--){
        blocktrans();
        cout<<endl;
    }
    return 0;
}