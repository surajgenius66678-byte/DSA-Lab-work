#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void reverseArray(vector<int>& arr,int l,int r){
    while(l<r){
        swap(arr[l],arr[r]);
        l++;
        r--;
    }
}

int main(){
    int n;

    cout<<"Enter size: ";
    cin>>n;

    if(n<=0){
        cout<<"Invalid size"<<endl;
        return 0;
    }

    vector<int> arr(n);

    cout<<"Enter elements: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];

    int k;

    cout<<"Enter number of positions to rotate: ";
    cin>>k;

    k=((k%n)+n)%n;

    reverseArray(arr,0,n-1);
    reverseArray(arr,0,k-1);
    reverseArray(arr,k,n-1);

    cout<<"Rotated array -> ";

    for(int x:arr)
        cout<<x<<" ";

    cout<<endl;

    return 0;
}