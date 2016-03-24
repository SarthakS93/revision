#include<bits/stdc++.h>
using namespace std;

int subsequences(char ip[], char op[][20], int index) {
    if(ip[index] == '\0') {
        op[0][0] = '\0';
        return 1;
    }

    int smallOpSize = subsequences(ip, op, index + 1);

    int i, j;
    for(i = 0; i < smallOpSize; i++) {
        op[i + smallOpSize][0] = ip[index];
        for(j = 0; op[i][j] != '\0'; j++) {
            op[i + smallOpSize][j + 1] = op[i][j];
        }
        op[i + smallOpSize][j + 1] = '\0';
    }

    return 2 * smallOpSize;
}


int main() {
    
    char ip[20], op[100][20];
    cout<<"Enter the string: "<<endl;
    cin>>ip;
    int size = subsequences(ip, op, 0);

    cout<<"The output is as follows: "<<endl;
    for(int i = 0; i < size; i++) {
        cout<<op[i]<<endl;
    }

return 0;
}
