#include <iostream>
#include <string>

using namespace std;


string strs[20001];

void merge(string* arr, int first, int middle, int last){
    int i = first;
    int j = middle + 1;
    int v = first;

    while(i <= middle && j <= last){
        string strI = arr[i], strJ = arr[j];
        int lengI = strI.length(), lengJ = strJ.length();
        if(lengI > lengJ){
            strs[v++] = strJ;
            j++;
        }else if(lengI < lengJ){
            strs[v++] = strI;
            i++;
        }
        else{
            bool isSame = true;
            for(int k=0; k<lengI; k++){
                if(strI[k] > strJ[k]){
                    isSame = false;
                    strs[v++] = strJ;
                    j++;
                    break;
                }else if(strI[k] < strJ[k]){
                    isSame = false;
                    strs[v++] = strI;
                    i++;
                    break;
                }                  
            }
            if(isSame){
                strs[v++] = "";
                j++;
            }
        }
        
    }

    if(i > middle)
        for(int k = j; k <= last; k++){
            strs[v++] = arr[k];
        }
    else
        for(int k = i; k <= middle; k++){
            strs[v++] = arr[k];
        }

    for(int k=first; k<=last; k++){
        arr[k] = strs[k];
    }    
}

void mergeSort(string* arr, int first, int last){
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
    string* words = new string[n];
    for(int i=0; i<n; i++){
        string a;
        cin >> a;
        words[i] = a;
    }
    
    mergeSort(words, 0, n-1);

    for(int i=0; i<n; i++){
        if(words[i] == "")
            continue;
        printf("%s\n", words[i].c_str());
    }

    return 0;
}