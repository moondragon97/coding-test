#include <iostream>
using namespace std;

int main(){
    char input[50];
    scanf("%s", input);
    for(int i=0; i<sizeof(input)/sizeof(char); i++){
        if(input[i] == '\0') break;
        printf("%c", input[i]);
    }
    printf("\?\?!");
    return 0;
}