#include <iostream>
#include <string>
using namespace std;

int main(){
    int input;
    cin >> input;
    string words = to_string(input);
    for(int i=words.length()-2; i>=0; i--){
        for(int j=i; j < words.length() - 1; j++){
            int temp;
            if(words[j] < words[j+1]){
                temp = words[j];
                words[j] = words[j+1];
                words[j+1] = temp;
            }else
            break;
        }
    }

    for(int i=0; i<words.length(); i++){
        cout << words[i];
    }
}