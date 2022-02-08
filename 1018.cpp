#include <iostream>
using namespace std;

int main(){
    int n, m, result = 33;
    cin >> n >> m;
    char c[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char input;
            cin >> input;
            c[i][j] = input;
        }
    }
    
    for(int h=0; h<n-7; h++){
        for(int w=0; w<m-7; w++){
            char one, two;
            for(int a=0; a<2; a++){
                if(a == 0){
                    one = 'W';
                    two = 'B';
                }else{
                    one = 'B';
                    two = 'W';
                }
                int count = 0;
                int com = (h+w)%2;
                for(int i=h; i<h+8; i++){
                    for(int j=w; j<w+8; j++){
                        int cal = (i+j)%2;
                        if(cal == com && c[i][j] != one) count++;
                        if(cal != com && c[i][j] != two) count++;
                        
                    }
                }
                if(result > count) result = count;
            }
            
        }
    }
    cout << result;
    return 0;
}