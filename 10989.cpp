#include <iostream>
#include <string>
using namespace std;

int main(){
    int input;
    scanf("%d", &input);
    int a;
    int b[10001] = {0, };
    for(int i=0; i<input; i++){
        scanf("%d", &a);
        b[a]++;
    }

    for(int i=1; i<=10000; i++){
        if(b[i] != 0)
            for(int j=0; j<b[i]; j++) printf("%d \n", i);
    }
    return 0;
}