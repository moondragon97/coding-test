#include <iostream>
#include <stdlib.h>

class point{
public:
    int x;
    int y;
};

point points[100001];

void merge(point* arr, int first, int middle, int last){
    int i = first;
    int j = middle + 1;
    int v = first;

    while(i <= middle && j <= last){
        if(arr[i].y > arr[j].y){
            points[v++] = arr[j++];
        }else if(arr[i].y < arr[j].y){
            points[v++] = arr[i++];
        }
        else{
            if(arr[i].x > arr[j].x){
                points[v++] = arr[j++];
            }else if(arr[i].x < arr[j].x){
                points[v++] = arr[i++];
            }
        }
    }

    if(i > middle)
        for(int k = j; k <= last; k++){
            points[v++] = arr[k];
        }
    else
        for(int k = i; k <= middle; k++){
            points[v++] = arr[k];
        }

    for(int k=first; k<=last; k++){
        arr[k] = points[k];
    }    
}

void mergeSort(point* arr, int first, int last){
    if(first < last){
        int middle = (first + last)/2;
        mergeSort(arr, first, middle);
        mergeSort(arr, middle+1, last);
        merge(arr, first, middle, last); 
    }
}

int main(){
    int n;
    scanf("%d", &n);
    point* arr = (point*)malloc(sizeof(point)*n);
    for(int i=0; i<n; i++){
        scanf("%d %d", &arr[i].x, &arr[i].y);
    }

    mergeSort(arr, 0, n-1);

    for(int i=0; i<n; i++){
        printf("%d %d \n", arr[i].x, arr[i].y);
    }
    return 0;
}