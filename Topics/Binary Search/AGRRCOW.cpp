#include <bits/stdc++.h>
using namespace std;

const int N=1e6+10;
int n;
long long m=1e9+10;
long long stalls[N];

bool isPossible(long long p,int c){
    sort(stalls,stalls+n);
    long long ct=1;
    long long last=stalls[0];
    for (int i =0;i<n;i++){
        if (stalls[i]-last>=p){
            ct++;
            last=stalls[i];
        }
    }
    return ct>=c;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int c;
        cin>>n>>c;
        for (int i =0;i<n;i++){
            cin>>stalls[i];
        }
        long long low=0,high=1e9+10,mid;
        while(high-low>1){
            mid=(high+low)/2;
            if(isPossible(mid,c)){
                low=mid;
            }else {
                high=mid-1;
            }
        }
        if (isPossible(low,c)){
            cout << low<<endl;
        }else{
            cout << high << endl;
        }
    }
}