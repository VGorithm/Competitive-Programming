// Link to the question : https://codeforces.com/problemset/problem/474/B
#include <bits/stdc++.h>
using namespace std;

long long piles,juicy;
vector<long long > pile;
vector<long long > prefix;

int find (long long tofind){
    long long low=0,high=piles,mid;
    while(high-low>1){
        mid=(high+low)/2;
        if(tofind>prefix[mid]){
            low=mid;
        }else{
            high=mid;
        }
    }
    return high;
}


int main(){
    cin>>piles;
    pile.resize(piles+10,0);
    prefix.resize(piles+10,0);
    for(int i =0;i<piles;i++){
        cin>>pile[i];
    }
    for(int i=1;i<piles+1;i++){
        prefix[i]=prefix[i-1]+pile[i-1];
    }
    cin>>juicy;
    vector<long long > juice(juicy+10,0);
    for(int i =0;i<juicy;i++){
        cin>>juice[i];
    }
    for(int i=0;i<juicy;i++){
        cout << find(juice[i])<<endl;
    }
}
