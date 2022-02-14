#include <iostream>
#include <string>
#include <cmath>
#include <queue>
using namespace std;

int input[500001];

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int start, int end){
    if(start > end) return;
    int pivot = start;
    int i = start+1;
    int j = end;
    while(i <= j){
        while(i <= end && input[i] <= input[pivot]) i++;
        while(j > start && input[j] >= input[pivot]) j--;
        if(i <= j) swap(&input[i], &input[j]);
        else swap(&input[pivot], &input[j]);
    }

    quickSort(start, j-1);
    quickSort(j+1, end);
}

int main(){
    int num;
    scanf("%d", &num);
    int *many = new int[num];
    double sum;
    for(int i=0; i<num; i++){
        scanf("%d", &input[i]);
        many[input[i]+4000]++;
        sum += input[i];
    }

    quickSort(0, num-1);
    
    queue<int> manyQueue;
    int max = 0;
    for(int i=0; i<8001; i++){
        if(many[i] == 0) continue;
        if(many[i] > max){
            max = many[i];
            manyQueue = queue<int>();
            manyQueue.push(i-4000);
        }else if(many[i] == max){
            manyQueue.push(i-4000);
        }
    }
    int valueMany=0;
    if(manyQueue.size() == 1)
        valueMany = manyQueue.front();
    else if(manyQueue.size() > 1){
        manyQueue.pop();
        valueMany = manyQueue.front();
    }
    int middle = num == 1 ? input[0] : input[num/2];
    printf("%lf \n%d \n%d \n%d", round(sum/num), middle, valueMany, input[num-1]-input[0]);

    return 0;
}