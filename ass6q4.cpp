#include <iostream>
using namespace std;

int profit(int V[],int n){
    int totalprofit=0;

    for(int i=0;i<n;i++){
        int j=i+1;
        while(j<n && V[i]>V[j]){
            j++;
        }

        if(j<n){
            totalprofit+=V[j]-V[i];
        }
        else{
            totalprofit+=V[i];
        }

    }
    return totalprofit;
}


int main(){

    int prices[]={1,2,3,4,5};
    int n1=sizeof(prices)/sizeof(int);

    cout<<"totalprofit is "<<profit(prices,n1)<<endl;
    cout<<sizeof(prices[0]);
}