#include <iostream>
using namespace std;

int main(){
    int input;
    cin >> input;
    int w[input], h[input], r[input];
    for(int i=0; i<input; i++){
        int x, y;
        cin >> x >> y;
        w[i] = x; h[i] = y; r[i] = 1;
    }

    for(int i=0; i<input; i++){
        for(int j=0; j<input; j++){
            if(i == j) continue;
            if(w[i] < w[j] && h[i] < h[j]) r[i]++;
        }
        cout << r[i] << " ";
    }

    return 0;
}