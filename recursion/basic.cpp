#include<bits/stdc++.h>
using namespace std;

int multiply(int a, int b) {
    if(b == 0)
        return 0;
    return (a + multiply(a, b - 1));
}

int divide(int a, int b) {
    if(a < b)
        return 0;
    return (1 + divide(a - b, b));
}

int countZeroesInNumber(int a) {
    if(a == 0)
        return 0;
    return (a % 10 == 0) ? (1 + countZeroesInNumber(a / 10)) : (countZeroesInNumber(a / 10));
}

float geometricSum(int k, float a) {
    if(k == 0)
        return 0;
    return (a + geometricSum(k - 1, a/2));
}

int length(char *s) {
    if(s[0] == '\0')
        return 0;
    return (1 + length(s + 1));
}

void reverseString(char* s, int index, int len) {
    if(index >= len/2)
        return;
    swap(s[index], s[len - 1 - index]);
    return reverseString(s, index + 1, len);
    
}

int getNumberFromString(char* s, int i) {
    if(s[i] == '\0')
        return 0;
    return ((s[i] - '0') * pow(10, i) + getNumberFromString(s, i + 1));
}

int sumOfDigits(int n) {
    if(n == 0)
        return 0;
    return (n % 10 + sumOfDigits(n/10));
}

int checkIfReverseHelper(char* s1, char* s2, int i, int n) {
    if(i == n)
        return 1;

    if(s1[i] != s2[n - 1 - i])
        return 0;
    return checkIfReverseHelper(s1, s2, i + 1, n);
}

int checkIfReverse(char* s1, char* s2) {
   int l1 = length(s1);
   int l2 = length(s2);
   if(l1 != l2)
       return 0;
   return checkIfReverseHelper(s1, s2, 0, l1);
}



int main() {

//cout<<multiply(-3, 3)<<endl;
//cout<<divide(5, 2)<<endl;
//cout<<countZeroesInNumber(102020)<<endl;
//cout<<geometricSum(3, 1)<<endl;
//cout<<length("abc")<<endl;

/*char s[10] = "123";
reverseString(s, 0, length(s));
int a = getNumberFromString(s, 0);
cout<<++a<<endl;*/

//cout<<sumOfDigits(512)<<endl;

/*char s1[10] = "abc";
char s2[10] = "dba";
cout<<checkIfReverse(s1,s2)<<endl;*/


return 0;
}
