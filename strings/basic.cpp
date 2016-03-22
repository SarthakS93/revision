#include<bits/stdc++.h>
using namespace std;

int length(char* s) {
    int l = 0;
    while(s[l] != '\0') {
        l++;
    }
    return l;
}

void reverseString(char* s) {
    int l = length(s);
    cout<<"Length of the string is: "<<l<<endl;
    for(int i = 0; i < l/2; i++) {
        swap(s[i], s[l - 1 - i]);
    }
}

void reverseString(char* s, int start, int end) {
    for(int i = 0; i < (end - start + 1)/2; i++) {
        swap(s[i + start], s[end - i]);
    }
}


void checkIfStringsPermutation() {
    cout<<"Enter the strings: "<<endl;
    char s1[10], s2[10];
    cin>>s1>>s2;
    int a1[256] = {0}, a2[256] = {0};
    int l1 = length(s1), l2 = length(s2);
    if(l1 != l2) {
        cout<<"No"<<endl;
        return;
    }
    for(int i = 0; i < l1; i++)
        a1[s1[i]]++;
    for(int i = 0; i < l2; i++)
        a2[s2[i]]++;
    for(int i = 0; i < 256; i++) {
        if(a1[i] != a2[i]) {
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
}

void toLower() {
    cout<<"Enter the string: "<<endl;
    char s[10];
    cin>>s;
    int l = length(s);
    for(int i = 0; i < l; i++) {
        if(s[i] >= 'A' && s[i] <= 'Z') {
            s[i] += 32;
        }
    }
    cout<<"The output is: "<<s<<endl;
}

void rotateString() {
    cout<<"Enter the string: "<<endl;
    char s1[10], s2[10];
    cin>>s1;
    int n;
    cout<<"Enter the rotating factor: "<<endl;
    cin>>n;
    int i, l = length(s1);
    for(i = 0; i < l; i++) {
        s2[i] = s1[(l - n + i) % l];
    }
    s2[i] = '\0';
    cout<<"The output is: "<<s2<<endl;
}

void splReverse() {
    cout<<"Enter the string: "<<endl;
    char s[10];
    cin>>s;
    int l = length(s);
    int low = 0, high = l - 1;
    while(low < high) {
        if(isalpha(s[low]) && isalpha(s[high])) {
            swap(s[low], s[high]);
            low++;
            high--;
        }
        else if(!isalpha(s[low])) {
            low++;
        }
        else {
            high--;
        }
    }
    cout<<"The output is: "<<s<<endl;
}

void reverseSentenceWords() {
    cout<<"Enter the sentence and press $ to stop input: "<<endl;
    char s[100], x;
    char op[100];
    int index = 0, l = 0;
    bool word = false;
    x = cin.get();
    if(x == '\0') {
        cout<<"You entered a null string"<<endl;
        return;
    }
    while(x != '$') {
        s[l++] = x;
        x = cin.get();
    }
    s[l] = '\0';

    reverseString(s); // comment this line for another question
    cout<<"intermediate step: "<<s<<endl;

    int start = 0, end = 0;
    while(s[index] != '\0') {
        if(s[index] == ' ') {
            if(!word) {
                index++;
            }
            else {
                reverseString(s, start, end);
                index++;   
                word = false;
            }
        }
        else {
            if(!word) {
                start = index;
                end = index;
                word = true;
                index++;
            }
            else {
                end = index;
                index++;
            }
        }    
    }

    if(word) {
        reverseString(s, start, end);
    }

    cout<<"The output is given below: "<<endl<<s<<endl;
    
}

int main() {

//checkIfStringsPermutation();
//toLower();
//rotateString();
//splReverse();
reverseSentenceWords();

return 0;
}
