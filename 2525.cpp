#include <iostream>
using namespace std;

int main(){
    int hour, minute, need;
    scanf("%d %d %d", &hour, &minute, &need);
    minute += need;
    if(minute >= 60){
        hour += (minute / 60);
        minute %= 60;
    }
    hour %= 24;
    printf("%d %d", hour, minute);
    return 0;
}