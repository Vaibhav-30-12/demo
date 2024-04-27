#include<iostream>
using namespace std;

template <typename T>

void reverse(T *arr, int size){
    for (int i=0;i<size/2;i++){
        swap(arr[i],arr[size-i-1]);
    }
}

template <typename T>
void swap (T& a,T& b){
    T temp;
    temp=a;
    a=b;
    b=temp;
}

template <typename T>
void print(T * arr, int size){
    for (int i=0;i<size;i++){
        cout<<arr[i]<<endl;
    }
    cout<<endl;

}

int main(){
    int array[5]={1,2,3,4,5 };
    int sizeofarray=sizeof(array)/sizeof(int);
    reverse(array,sizeofarray);
    print(array,sizeofarray);
}