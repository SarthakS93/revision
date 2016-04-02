#include<iostream>
#include<unordered_map>
using namespace std;

int length(char* s) {
    int i = 0;
    while(s[i] != '\0') {
        i++;
    }
    return i;
}


int bruteForce(char* text, char* pattern) {
    int n = length(text);
    int m = length(pattern);

    int i, j;

    for(i = 0; i < n - m + 1; i++) {
        for(j = 0; j < m; j++) {
            if(text[i + j] != pattern[j])
                break;
        }
        if(j == m) {
            return i;
        }
    }
    return -1;
}

int BoyerMoore(char* text, char* pattern) {
    int n = length(text);
    int m = length(pattern);

    unordered_map<char, int> last_indices;
    for(int i = 0; i < m; i++) {
        last_indeces[pattern[i]] = i;
    }

    int i = m - 1;

    while(i < n) {
        int j = 0;
        for(; j < m; j++) {
            int smallerIndex = m - 1 - j;
            if(text[i - j] != pattern[smallerIndex]) {
                char badChar = text[i - j];
                unordered_map<char, int>::iterator it;
                it = last_indices.find(badChar);
                if(it == last_indices.end()) {
                    i = i + smallerIndex + 1;
                }
            }
        }
    }
    
}

int main() {

    char s1[10], s2[10];
    cout<<"Enter the strings: "<<endl;
    cin>>s1>>s2;

    cout<<"Output: "<<bruteForce(s1, s2)<<endl;

return 0;
}
