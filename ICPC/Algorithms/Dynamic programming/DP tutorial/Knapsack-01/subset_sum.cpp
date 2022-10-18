#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//Given and array and a sum print 1 if a subset is present with sum and 0 if not
int subset_sum(int* arr,int n,int sum){
    int dp[n+1][sum];
    //Initalization
    for(int i=0;i<n+1;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<sum;i++){
        dp[0][i]=0;
    }
    //Similarity with knapsack
    
}
 
int main(){
    int arr[]={1,5,3,6,10,2};
    int sum=24;
    cout<<subset_sum(arr,sizeof(arr)/sizeof(int),sum);
    return 0;
}