#include<bits/stdc++.h>
using namespace std;
long long root;
bool isPrime(long long num){
    if(num<=1) return false;
    if(num==2) return true;
    if(num%2==0) return false;
    for(int i=3;i*i<=num;i+=2){
        if (num%i==0){
            return false;
        }
    }
    return true;
}

bool isSquare(long long num){
    root=sqrtl(num);
    return root*root==num;
}

int main(){
    int n;
    cin>>n;
    vector<long long > number(n+10,0);
    for (long long i=0;i<n;i++){
        cin>>number[i];
        if (isSquare(number[i])){
            if(isPrime(sqrtl(number[i]))){
                cout << "YES"<<"\n";
            } else {
                cout << "NO"<<"\n";
            }
        } else{
            cout << "NO"<<"\n";
        }
    }
}

