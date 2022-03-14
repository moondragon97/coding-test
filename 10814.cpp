#include <iostream>
#include <string>

using namespace std;

class user{
public:
    int _num;
    int _age;
    string _name;
};

user users[100001];

void merge(user* arr, int first, int middle, int last){
    int i = first;
    int j = middle + 1;
    int v = first;

    while(i <= middle && j <= last){
        if(arr[i]._age > arr[j]._age){
            users[v++] = arr[j++];
        }else if(arr[i]._age < arr[j]._age){
            users[v++] = arr[i++];
        }
        else{
            if(arr[i]._num > arr[j]._num){
                users[v++] = arr[j++];
            }else if(arr[i]._num < arr[j]._num){
                users[v++] = arr[i++];
            }       
        }
    }        

    if(i > middle)
        for(int k = j; k <= last; k++){
            users[v++] = arr[k];
        }
    else
        for(int k = i; k <= middle; k++){
            users[v++] = arr[k];
        }

    for(int k=first; k<=last; k++){
        arr[k] = users[k];
    }    
}

void mergeSort(user* arr, int first, int last){
    if(first < last){
        int middle = (first + last)/2;
        mergeSort(arr, first, middle);
        mergeSort(arr, middle+1, last);
        merge(arr, first, middle, last); 
    }
}

int main(){
    int n;
    cin >> n;
    user* arr = new user[n];
    for(int i=0; i<n; i++){
        int age;
        string name;
        cin >> age >> name;
        arr[i]._num = i;
        arr[i]._age = age;
        arr[i]._name = name;
     }
    
    mergeSort(arr, 0, n-1);
    
    for(int i=0; i<n; i++){
        printf("%d %s\n", arr[i]._age, arr[i]._name.c_str());
    }

    return 0;
}