// Link to the problem : https://www.interviewbit.com/problems/painters-partition-problem/

const int N=1e5+10;
long long A;
long long B;
long long highest=1e11+10;
int board[N];
long long q;

bool isPossible(long long mid){
    long long currenttime=0;
    long long painters=1;
    for(int i =0;i<q;i++){
        if (board[i]>mid) return false;
        if (currenttime+board[i]<=mid){
            currenttime+=board[i];
        }else {
            painters++;
            currenttime=board[i];
        }
    }
    if (painters<=A){
        return true;
    }else {
        return false;
    }
}

#include <bits/stdc++.h>
using namespace std;
int main(){
    cin>>A;
    cin>>B;
    cin>>q;
    for (int i =0;i<q;i++){
        cin>>board[i];
    }
    long long low=0,high=highest,mid;
    while(high-low>1){
        mid=(high+low)/2;
        // F F F F F T T T 
        if(isPossible(mid)){
            high=mid;
        }else {
            low = mid;
        }
    }
    if (isPossible(low)){
        cout << (B*low )% 10000003<<endl;
    }else {
        cout << (B*high )% 10000003<<endl;
    }
    
}