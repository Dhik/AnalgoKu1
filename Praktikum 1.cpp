/*
Name : Mohammad Dhikri
NPM : 140810180075
Kelas : A 
*/

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#define N 5

bool chooseMen(int priority[2 * N][N], int w, int m, int m1){
    for (int i = 0; i < N; i++)
    {
        if (priority[w][i] == m1)
            return true;

        if (priority[w][i] == m)
            return false;
    }
} 
void printPeer(int priority[2 * N][N]) {
    bool singleMan[N];
    int peerWoman[N];
    memset(peerWoman, -1, sizeof(peerWoman));
    memset(singleMan, false, sizeof(singleMan));
    int jumlah = N;
    while (jumlah > 0){
        int m;
        for (m = 0; m < N; m++)
            if (singleMan[m] == false)
                break;

        for (int i = 0; i < N && singleMan[m] == false; i++){
            int w = priority[m][i];
            if (peerWoman[w - N] == -1){
                peerWoman[w - N] = m;
                singleMan[m] = true;
                jumlah--;
            }
            else{
                int m1 = peerWoman[w - N];
                if (chooseMen(priority, w, m, m1) == false){
                    peerWoman[w - N] = m;
                    singleMan[m] = true;
                    singleMan[m1] = false;
                }
            } 
        }
    }
    cout<<"Pasangan yang stabil : "<<endl<<endl;
    string man;
    string woman;
    for (int i = 0; i < N; i++){
        if (i < N){
            if (peerWoman[i] == 0)
                man = "Victor";
            if (peerWoman[i] == 1)
                man = "Wyatt";
            if (peerWoman[i] == 2)
                man = "Xavier";
            if (peerWoman[i] == 3)
                man = "Yancey";
            if (peerWoman[i] == 4)
                man = "Zeus";
                
            if (i == 0)
                woman = "Amy";
            if (i == 1)
                woman = "Bertha";
            if (i == 2)
                woman = "Clare";
            if (i == 3)
                woman = "Diane";
            if (i == 4)
                woman = "Erika";
        }
        cout << " " << man << "\t  " << woman << endl;
    }
}
int main(){
    int priority[2 * N][N] = {{6, 5, 8, 9, 7},
                            {8, 6, 5, 7, 9},
                            {6, 9, 7, 8, 5},
                            {5, 8, 7, 6, 9},
                            {6, 8, 5, 9, 7},
                            {3, 1, 4, 2, 0}};
    printPeer(priority);
    return 0;
}
 
