#include<iostream>
#include<vector>
using namespace std;

int main(){
    int m,n;

    cout<<"Enter rows and columns: ";
    cin>>m>>n;

    if(m<=0||n<=0){
        cout<<"Invalid matrix size"<<endl;
        return 0;
    }

    vector<vector<int>> matrix(m,vector<int>(n));

    cout<<"Enter matrix elements:"<<endl;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cin>>matrix[i][j];
    }

    cout<<"Row Col Val"<<endl;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]!=0)
                cout<<i<<" "<<j<<" "<<matrix[i][j]<<endl;
        }
    }

    return 0;
}