#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int x[n], y[n];
    for(int i=0; i<n; i++){
        scanf("%d %d", &x[i], &y[i]);
    }

    for(int i=1; i<n; i++){
        for(int j=i; j>0; j--){
            if(x[j] < x[j-1]){
                int temp = x[j];
                x[j] = x[j-1];
                x[j-1] = temp;
                temp = y[j];
                y[j] = y[j-1];
                y[j-1] = temp;
            }else break;
        }
    }

    int start = -100001;
    int seq = 0;

    for(int i=0; i<n; i++){
        if(i + 1 != n && x[i] == x[i+1]){
            if(i != start){
                start = i;
            }
            seq++;
        }else{
            if(seq > 0){
                for(int j=start+1; j <= start+seq; j++){
                    for(int k=j; k>start; k--){
                        if(y[k] < y[k-1]){
                            int temp = y[k];
                            y[k] = y[k-1];
                            y[k-1] = temp;
                        }else break;
                    }
                }
                start = -100001;
                seq = 0;
            }
        }
    }
    for(int i=0; i<n; i++){
        printf("%d %d\n", x[i], y[i]);
    }
}