#include<bits/stdc++.h>
using namespace std;

int length(char* s) {
    int i = 0;
    while(s[i] != '\0') {
        i++;
    }
    return i;
}

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

bool palindrome(char* s, int & a, int index) {
    if(s[index] == '\0')
        return true;
    bool temp = palindrome(s, a, index + 1);
    if(!temp)
        return temp;
    if(s[a] == s[index]) {
        a++;
        return true;
    }
    else
        return false;
}

void anagramSubstringSearch(char* s, char* t) {
    int n = length(s);
    int m = length(t);
    int z = 0;

    int freq[300] = {0};
    for(int i = 0; i < m; i++) {
        freq[t[i]]++;
        freq[s[i]]--;
    }
    for(int i = 0; i < 300; i++) {
        if(freq[i] != 0)
            z++;
    }



    
    

}

int main() {
    
   /* char ip[20], op[100][20];
    cout<<"Enter the string: "<<endl;
    cin>>ip;
    int size = subsequences(ip, op, 0);

    cout<<"The output is as follows: "<<endl;
    for(int i = 0; i < size; i++) {
        cout<<op[i]<<endl;
    }*/
    /*char s[10] = "nitin";
    int a = 0, index = 0;
    cout<<palindrome(s, a, index)<<endl;*/





return 0;
}
