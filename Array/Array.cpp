#include <iostream>
#include <cstdlib>
using namespace std;

class Array{
    private:
        int arr[100],temp,last;
        int size = sizeof(arr);
        int len = size/4;
    public:
        Array(int n){
            for(int i=0;i<n;i++){
                arr[i] = rand() % 1000;
            }
            last = n;
        }
        int Get(int i){
            return arr[i];
        }
        void Replace(int a, int i){
            arr[i] = a;
        }
        void Traverse(){
            for(int i=0;i<last;i++){
                cout<<arr[i]<<"\t";
            }
            cout<<endl;
        }
        void Insert(int a, int i){
            if(len>i&&i>last){
                arr[i] = a;
            }
            else if(i<len&&!(arr[len-1])){
                for(int j = len;j>=i;j--){
                    if(arr[j-1]){
                        arr[j] = arr[j-1];
                    }   
                }
                arr[i] = a;
            }
            else if(i>=len){
                cout<<"Insertion Failed: Index Out of Range"<<endl;
            }
            else if(arr[len-1]){
                cout<<"Insertion Failed: Array is Full"<<endl;
            }
        }
        void Push(int a){
            if(last >= len){
                cout<<"Push Failed: Array is Full"<<endl;
            }
            else{
                arr[last] = a;
            }
        }
        void Remove(int i){
            while(arr[i+1]){
                arr[i] = arr[i+1];
                i++;
            }
        }
        void Sort(){
            for(int i=0;i<last;i++){
                for(int j=i;j<last;j++){
                    if(arr[i]>arr[j]){
                        temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
            cout<<"Array Sorted."<<endl;
        }
        void Selection_Search(int a){
            for(int i = 0; i<last ; i++){
                if(arr[i] == a){
                    cout<<"Element is on Index: "<<i<<endl;
                    return;
                }
            }
            cout<<"Element not Found."<<endl;
        }
        void Binary_Search(int a){
            int max = last-1, min = 0, mid = (max+min)/2;
            while(max>=min){
                if(arr[mid] == a){
                    cout<<"Element is on Index: "<<mid<<endl;
                    return;
                }
                if(a>arr[mid]){
                    min = mid+1;
                    mid = (min+max)/2;
                }
                else{
                    max = mid-1;
                    mid = (min+max)/2;
                }
            };
            cout<<"Element not Found."<<endl;
        }
};

int main(){
    Array array(30);
    array.Traverse();
    array.Insert(2,10);
    array.Push(9);
    array.Remove(8);
    array.Traverse();
    array.Sort();
    array.Traverse();
    array.Selection_Search(334);
    array.Binary_Search(391);
    return 0;
}