#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int binary_search(int* arr,int size,int low,int high){
    
}

int exponential_search(int* arr,int size,int key){
    int i=0;
    if(arr[i]==key){
        return i;
    }
    else{
        for(int i=1;i<size;i=i*2){
            if(key>arr[i] and key<arr[i*2]){
                int low=i;
                int high=arr[i*2];
                binary_search(arr,size,low,high);
            }
        }
    }
}
 
int main(){
    
    return 0;
}