#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore();
    for(int i=0; i<n; i++){
        string word;
        getline(cin, word);
        stack<char> c;
        for(int j=0; j<1001; j++){
            if(word[j] == ' ' || word[j] == 0){
                while(c.size() > 0){
                    printf("%c", c.top());
                    c.pop();
                }
                printf(" ");
                if(word[j] == 0)
                    break;
            }else{
                c.push(word[j]);
            }
        }
        printf("\n");
    }
}