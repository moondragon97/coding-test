#include <iostream>
#include <string>
#include <cmath>
#include <queue>
using namespace std;

int input[500001], sorts[500001];
int num;

void merge(int m, int middle, int n){
    int a = m, b = middle + 1, c = m;

    while(a <= middle && b <= n){
        if(input[a] <= input[b]) sorts[c++] = input[a++];
        else sorts[c++] = input[b++];
    }
    if(a <= middle){
        for(int i=a; i<=middle; i++) sorts[c++] = input[i];
    }else{
        for(int i=b; i<=n; i++) sorts[c++] = input[i];
    }

    for(int i=m; i<=n; i++){
        input[i] = sorts[i];
    }
}

void mergeSort(int m, int n){
    if(m < n){
        int middle = (m + n) / 2;
        mergeSort(m, middle);
        mergeSort(middle + 1, n);
        merge(m, middle, n);
    }
}

int main(){
    scanf("%d", &num);
    int many[8001] = {0, };
    double sum;
    for(int i=0; i<num; i++){
        scanf("%d", &input[i]);
        many[input[i]+4000]++;
        sum += input[i];
    }

    mergeSort(0, num-1);
    
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
    printf("%d \n%d \n%d \n%d", (int)round(sum/num), middle, valueMany, input[num-1]-input[0]);

    return 0;
}