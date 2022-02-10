#include <iostream>
#include <string>
using namespace std;

int main(){
    int input;
    cin >> input;
    int num = 1;
    for(int i=666; i<3000000; i++){
        string s = to_string(i);
        if(s.find("666") != string::npos)
            if(num++ == input){
                cout << i;
                return 0;
            }
    }
}