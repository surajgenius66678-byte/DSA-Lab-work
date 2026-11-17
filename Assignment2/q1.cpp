#include<iostream>
#include<vector>
using namespace std;

vector<int> arr;

void print_array(){
    cout<<"Array -> ";
    for(int x:arr)
        cout<<x<<" ";
    cout<<endl;
}

void insert(int idx,int value){
    if(idx<0||idx>arr.size()){
        cout<<"Invalid Index"<<endl;
        return;
    }

    arr.insert(arr.begin()+idx,value);
    print_array();
}

void deleteElement(int idx){
    if(idx<0||idx>=arr.size()){
        cout<<"Invalid Index"<<endl;
        return;
    }

    arr.erase(arr.begin()+idx);
    print_array();
}

int main(){
    int size;
    cout<<"Enter size: ";
    cin>>size;

    if(size<0)return 0;

    arr.resize(size);

    for(int i=0;i<size;i++)
        cin>>arr[i];

    print_array();

    int choice;

    while(true){
        cout<<"Enter 0 for insert, 1 for delete, 2 for exit: ";
        cin>>choice;

        if(choice==0){
            int idx,value;

            cout<<"Enter index: ";
            cin>>idx;

            cout<<"Enter value: ";
            cin>>value;

            insert(idx,value);
        }
        else if(choice==1){
            int idx;

            cout<<"Enter index: ";
            cin>>idx;

            deleteElement(idx);
        }
        else
            break;
    }

    return 0;
}