#include <iostream>

using namespace std;

int main(){
    int n, m;
    int a[101];
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }    
    int result = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j) continue;
            for(int k=0; k<n; k++){
                if(i == k || j == k) continue;
                int sum = a[i] + a[j] + a[k];
                if(sum <= m && result < sum) result = sum;
            }
        }
    }

    cout << result;
    return 0;
}