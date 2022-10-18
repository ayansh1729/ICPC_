#include<stdio.h>
#include<stdlib.h>
 
int fib(int n){
    int x,y;
    int* arr=(int*)malloc(100*sizeof(int));
    for(int i=0;i<=n;i++){
        arr[i]=-1;              //Fill all array initially with -1
    }
    arr[0]=1;arr[1]=1;
    if(arr[n]==-1){         //We are storing the corresponding fibonacci in array---arr.....if(arr[n]==-1) means it's not present in arr
        if(n<2){            
            arr[n]=n;       //if(n<2) store n in the array
        }
        else{
            arr[n]=fib(n-1)+fib(n-2);     //else calculate fib(n-1)+fib(n-2) and store it in arr[n]
        }
    }
    return arr[n];      //At last return the required fibonacci no.
} 
int main(){
    int fi=fib(5);
    printf("%d",fi);
    return 0;
}