#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    int num, value;
    stack<int> st;
    cin >> num;
    for(int i=0; i<num; i++){
        string input;
        cin >> input;
        if(input == "push"){
            cin >> value;
            st.push(value);
        }else if(input == "top"){
            printf("%d\n", st.empty() ? -1 : st.top());
        }
        else if(input == "size")
            printf("%lu\n", st.size());
        else if(input == "empty")
            printf("%d\n", st.empty() ? 1 : 0);
        else if(input == "pop"){
            if(st.empty())
                printf("-1\n");
            else{
                printf("%d\n", st.top());
                st.pop();
            }
        }
    }

    return 0;
}
