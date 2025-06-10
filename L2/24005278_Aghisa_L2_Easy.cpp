/*
 ID: 24005278
 Name: Aghisa Zahra
 Group: G2
 Lab: L2 (Easy) - Print matrix in snake pattern
 Problem: https://www.geeksforgeeks.org/print-matrix-snake-pattern/
 */
#include <iostream>

using namespace std;

int main(){
    int matrix[3][3] = {
        {18, 26, 30},
        {47, 59, 65},
        {74, 87, 92}
    };
    
    for (int i=0; i<3; i++){
        
        if (i % 2 == 0){    // Even Row
            for (int j=0; j<3; j++){
                cout<<matrix[i][j]<<" ";
            }
        }
        
        else {  //Odd Row
            for (int j=2; j>=0; j--){
                cout<<matrix[i][j]<<" ";
            }
        }
    }
    
    return 0;
}
