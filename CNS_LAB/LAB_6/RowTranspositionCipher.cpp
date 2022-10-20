#include <bits/stdc++.h>
using namespace std;

string rowTranspositionCipher(string text, string key) {
    string encryptedText;
    int n = text.length(), m = key.size(), k = 0;
    vector<int> order(m, 0);
    vector<vector<char>> table(5, vector<char>(7, '\0'));

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 7; j++)
            table[i][j] = k < n ? text[k++] : '\0';
    }

    for(int i = 0; i < m; i++)
        order[key[i] - '0' - 1] = i;

    for(int j : order) {
        for(int i = 0; i < 5; i++)
            if(table[i][j] != '0')
                encryptedText += table[i][j]; 
    }
    
    return encryptedText;
}

int main() {
    string text, key;
    cout<<"Enter the text : ";
    cin>>text;
    cout<<"Enter the key : ";
    cin>>key;

    cout<<"Encrypted Text : "<<rowTranspositionCipher(text, key)<<endl;
}