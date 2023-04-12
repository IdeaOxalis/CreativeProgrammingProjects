#include <stdio.h>
#include <stdbool.h>

#define N 8

void bt(int *, int, int);

//int bt_time = 0;
//int ck_time = 0;
//int pra_time = 0;
int a[256];
//aの重ね合わせを格納
int b[256][8][8];
int b1_index = 0;
int max_k = 0;

int main(void){
    // Your code here!
    bt(a, N, 0);
    
    //printf("bt_time = %d\n", bt_time);
    //printf("ck_time = %d\n", ck_time);
    //printf("pra_time = %d\n", pra_time);
    printf("maximum k = %d\n", max_k);
    
    return 0;
}

//
void judgea(int a[], int n){
    if(n > 0){
        b1_index++;
        //すべてのbに対してaは共存できるか判定
        for(int k=0; k<b1_index; k++){
            bool b_bool = true;
            bool b2_index = 0;
            for(int l=0; l<n; l++){
                if(b[k][l][0] == NULL){
                    b2_index = l;
                    break;
                }
                for(int m=0; m<n; m++){
                    if(a[m] == b[k][l][m]){
                        b_bool = false;
                        break;
                    }
                }
                if(!b_bool) break;
            }
            if(b_bool){
                for(int o=0; o<n; o++){
                    b[k][b2_index][o] = a[o];
                }
                if(b2_index+1 > max_k){
                    max_k = b2_index+1;
                }
            }
        }
    }
}

void printa(int a[], int n){
    //pra_time++;
    if(n > 0){
        printf("%d", a[0]);
        for(int i = 1; i < n; i++){
            printf(", %d",a[i]);
        }
        printf("\n");
    }
}

int ck(int a[], int x, int y){
    //ck_time++;
    for(int k = 0; k < x; k++){
        if(a[k] == y || (a[k]+x-k) == y || (a[k]-x+k) == y){//a[k] == y || (a[k]+x-k) == y || (a[k]-x+k) == y
            return 0;
        }
    }
    return 1;
}

/*
void bt(int a[], int n, int x){
    //bt_time++;
    if(x == n){
        printa(a, n);
    }
    else{
        for(int y = 0; y < n; y++){
            if(ck(a, x, y)){
                a[x] = y;
                bt(a, n, x+1);
            }
        }
    }
}
*/

void bt(int a[], int n, int x){
    int y = 0;
    while(1){
        while(y<n){
            if(ck(a, x, y)){
                a[x] = y;
                x = x+1;
                if(x == n){
                    //printa(a, n);
                    judgea(a, n);
                    break;
                }
                y = 0;
            }
            else{
                y = y+1;
            }
        }
        x = x - 1;
        if(x < 0) return;
        y = a[x]+1;
    }
}
