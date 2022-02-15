#include <iostream>
using namespace std;

int cal(int a, int b, int c){
    return a+b*c;
}

int main(){
    int a, b, c, result = 0;
    scanf("%d %d %d", &a, &b, &c);
    int first = 1000, third = 100;
    if(a == b && b == c){
        result = cal(10000, a, 1000);
    }else if(a == b || b == c || a == c){
        if(a==b) result = cal(first, a, third);
        else if(b==c) result = cal(first, b, third);
        else if(a==c) result = cal(first, a, third);
    }else{
        if(a > b && a > c) result = cal(0, a, third);
        else if(b > a && b > c) result = cal(0, b, third);
        else result = cal(0, c, third);
    }
    printf("%d", result);
    return 0;
}