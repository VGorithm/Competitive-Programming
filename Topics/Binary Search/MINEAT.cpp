//Link to the question: https://www.codechef.com/practice/course/binary-search/INTBINS01/problems/MINEAT

#include <bits/stdc++.h>
using namespace std;

const long long N=1e5+10;
long long h=1e9+10;
long long banana[N];
long long n,H;

bool isValid(long long m){
    if (m==0) return false;
    long long ct=0;
    for (int i =0;i<n;i++){
        if(m>=banana[i]){
            ct++;
        }else{
            if (banana[i]%m==0){
                ct+=banana[i]/m;
            }else {
                ct+=(banana[i]/m)+1;
            }
        }
    }
    return ct<=H;
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	//F F F F F F T T T T T
	while(t--){
    	long long low=0,high=h,mid;
	    cin>>n>>H;
	    for (int i =0;i<n;i++){
	        cin>>banana[i];
	    }
        while(high-low>1){
            mid=(high+low)/2;
            if(isValid(mid)){
                high=mid;
            }else {
                low=mid;
            }
        }
	    if(isValid(low)){
	        cout << low << endl;
	    }else {
	        cout << high<<endl;
	    }
	}
}
