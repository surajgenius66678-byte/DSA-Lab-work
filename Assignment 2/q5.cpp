#include<iostream>
#include<vector>
#include<chrono>
#include<algorithm>
using namespace std;
using namespace chrono;

void insertionSort(vector<int>& arr){
    int n=arr.size();

    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;

        while(j>=0&&arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }

        arr[j+1]=key;
    }
}

void bubbleSort(vector<int>& arr){
    int n=arr.size();

    for(int i=0;i<n-1;i++){
        bool swapped=false;

        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
        }

        if(!swapped)break;
    }
}

int main(){
    int choice,n;

    cout<<"Enter 0 for manual input, 1 for 100000 reversed elements: ";
    cin>>choice;

    if(choice==0){
        cout<<"Enter size: ";
        cin>>n;

        if(n<=0){
            cout<<"Invalid size"<<endl;
            return 0;
        }
    }
    else if(choice==1){
        n=100000;
    }
    else{
        cout<<"Invalid choice"<<endl;
        return 0;
    }

    vector<int> arr(n);

    cout<<"Enter elements: ";

    for(int i=0;i<n;i++){
        if(choice==0)
            cin>>arr[i];
        else
            arr[i]=n-i;
    }

    cout<<"Enter 0 for insertion sort, 1 for bubble sort: ";
    cin>>choice;

    if(choice!=0&&choice!=1){
        cout<<"Invalid choice"<<endl;
        return 0;
    }

    auto start=steady_clock::now();

    if(choice==0)
        insertionSort(arr);
    else
        bubbleSort(arr);

    auto stop=steady_clock::now();

    double seconds=duration<double>(stop-start).count();

    if(n<=100){
        cout<<"Sorted array: ";

        for(int x:arr)
            cout<<x<<" ";

        cout<<endl;
    }

    cout<<"Execution time: "<<seconds<<" seconds"<<endl;

    return 0;
}