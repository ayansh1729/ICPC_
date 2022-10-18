#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
 
char* xnor(char* a,int p,char* b,int q){
    char* c=(char*)malloc(min(p,q)*sizeof(char));
    for(int i=0;i<min(p,q);i++){
        if(a[i]==b[i]){
            c[i]=1;
        }
        else{
            c[i]=0;
        }
    }
    return c;
}
int main(){
    int n,m;
    cout<<"Enter values of n and m: ";
    cin>>n>>m;
    cout<<n<<" "<<m<<endl;
    char* a,*b;
    itoa(n,a,2);
    itoa(m,b,2);
    printf("%s %s",a,b);
    // cout<<a<<endl;
    // cout<<b<<endl;
    char* result=xnor(a,strlen(a),b,strlen(b));
    cout<<result<<endl;
    return 0;
}