#include <iostream>

using namespace std;

int value;

void dot(int i, int j){
    if(i >= value)
        return;
    
    if(j >= value){
        cout << "\n";
        dot(++i, 0);
        return;
    }
    
    int r = value / 3;
    
    for(int k=1; k<=r; k*=3){
            if((j/k) % 3 == 1 && (i/k) % 3 == 1){
            cout << " ";
            dot(i, ++j);
            return;
        }
    }
    
    cout << "*";
    dot(i, ++j);
}

int main(){
    cin >> value;
    dot(0, 0);
}