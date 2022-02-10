#include <iostream>
#include <string>
#include <cmath>
#include <queue>
using namespace std;

int main(){
    int num;
    scanf("%d", &num);
    int arr[num];
    int index[8001] = {0, };
    for(int i=0; i<num; i++){
        scanf("%d", &arr[i]);
        index[arr[i]+4000]++;
    }
    double sum;
    int max=-4001, min=4001, temp;
    for(int i=0; i<num; i++){
        sum += arr[i];
        if(max < arr[i]) max = arr[i];
        if(min > arr[i]) min = arr[i];

        for(int j=i; j>0; j--){
            if(arr[j] >= arr[j-1]) continue;
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
        }
    }

    int manyIndex = 0, maxSeq=1;
    queue<int> manyQueue;
    for(int i=1; i<num; i++){
        if(arr[i] == arr[i-1]){ 
            manyIndex++;
            if(maxSeq == manyIndex){
                manyQueue.push(arr[i]);
            }else if(maxSeq < manyIndex){
                manyQueue = queue<int>();
                manyQueue.push(arr[i]);
                maxSeq = manyIndex;
            }
        }else{ 
            manyIndex = 0;
        }
    }
    
    
    int many=0;
    if(manyQueue.size() > 2){
        manyQueue.pop();
        many = manyQueue.front();
    }else if(manyQueue.size() == 0){
        many = arr[1];
        if(num < 2)
            many = arr[0];
    }
    else if(manyQueue.size() == 1)
        many = manyQueue.front();

    printf("%f \n", round(sum/num));
    printf("%d \n", arr[num/2]);
    printf("%d \n", many);
    printf("%d \n", max-min);
    return 0;
}