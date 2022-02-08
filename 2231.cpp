#include <iostream>
#include <string>
using namespace std;

int main(){
    int input;
    cin >> input;
    int result = 1000001;
    for(int i=1; i<=1000001; i++){
        string s = to_string(i);
        int sum = i;
        for(int j=0; j<s.length(); j++){
            sum += s[j] - '0';
        }
        if(sum == input && result > i) result = i;
    }
    if(result == 1000001) result = 0;

    cout << result;
    return 0;
}