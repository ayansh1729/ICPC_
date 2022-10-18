//https://www.codechef.com/submit/TOOMEAN

//----------HINT---------
//if 1,4,7,8,9 is sorted array the think of cases when only 1 subsequence will be there i.e {1,4,7,8,9} then when 2 subsequencs
//{1,4,7},{8,9} or {1,4},{7,8,9} or {1},{4,7,8,9}-- THink on which will yeild the maximum mean the for 3 subsequences and so on!
#include <iostream>
#include <numeric>
#include<algorithm>
#include<limits>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
        long double sum=0; 
	    int* arr=(int*)malloc(n*sizeof(int));
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
            sum+=arr[i];
	    }
	    sort(arr,arr+n);
	    long double result=sum/n;
	    long double current=0.0;
	    for(int i=0;i<n;i++){
	        current+=arr[i];
	        result=max(result,(current/(i+1)+sum-current)/(n-i));
	    }
	    cout<<fixed<<setprecision(6)<<result<<endl;
	    sum=0;
	    free(arr);
	}
	return 0;
}

