#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main(){
    int n;

    cout<<"Enter size: ";
    cin>>n;

    if(n<2){
        cout<<"At least two elements are required"<<endl;
        return 0;
    }

    vector<int> arr(n);

    cout<<"Enter elements: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];

    int largest=INT_MIN,secondLargest=INT_MIN;
    int smallest=INT_MAX,secondSmallest=INT_MAX;

    bool hasSecondLargest=false,hasSecondSmallest=false;

    for(int x:arr){
        if(x>largest){
            secondLargest=largest;
            largest=x;
            hasSecondLargest=(secondLargest!=INT_MIN);
        }
        else if(x<largest&&(!hasSecondLargest||x>secondLargest)){
            secondLargest=x;
            hasSecondLargest=true;
        }

        if(x<smallest){
            secondSmallest=smallest;
            smallest=x;
            hasSecondSmallest=(secondSmallest!=INT_MAX);
        }
        else if(x>smallest&&(!hasSecondSmallest||x<secondSmallest)){
            secondSmallest=x;
            hasSecondSmallest=true;
        }
    }

    if(hasSecondLargest)
        cout<<"Second largest element: "<<secondLargest<<endl;
    else
        cout<<"No distinct second largest element"<<endl;

    if(hasSecondSmallest)
        cout<<"Second smallest element: "<<secondSmallest<<endl;
    else
        cout<<"No distinct second smallest element"<<endl;

    return 0;
}