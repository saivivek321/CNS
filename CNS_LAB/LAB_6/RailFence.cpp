#include <bits/stdc++.h>
using namespace std;

string railFenceCipher(string text, int key) {
    string encryptedText;
    bool traverseDown = true;
    int n = text.length(), i = 0, j = 0;
    vector<vector<char>> table(key, vector<char>(n, '\0'));

    for(int k = 0; k < n; k++){
        if(traverseDown)
            table[i++][j++] = text[k];
        else table[i--][j++] = text[k];
        
        if(i == key)
            traverseDown = false, i--;
        else if(i == -1)
            traverseDown = true, i++;
    }

    for(int i = 0; i < key; i++) {
        for(int j = 0; j < n; j++) {
            if(table[i][j] != '\0')
                encryptedText += table[i][j];
        }
    }

    return encryptedText;
}

int main() {
    int key;
    string text;
    cout<<"Enter the text : ";
    cin>>text;
    cout<<"Enter the key : ";
    cin>>key;
    cout<<"Encrypted Text : "<<railFenceCipher(text, key)<<endl;
}