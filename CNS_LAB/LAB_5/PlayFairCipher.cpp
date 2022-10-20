#include<bits/stdc++.h>
using namespace std;

char keyTable[5][5];

void fillKeyTable(string key) {
    int i = 0, j = 0;
    vector<bool> taken(26, false);

    for(int c = 0; c < key.size(); c++) {
        int index = key[c] - 'a';
        if(!taken[index] && index != ('j' - 'a')) {
            taken[index] = 1;
            keyTable[i][j] = key[c];
            j = (j + 1) % 5;
            if(j == 0)
                i = (i + 1) % 5;
        }
    }

    for(int c = 0; c < 26; c++) {
        if(!taken[c] && c != ('j'-'a')) { 
            keyTable[i][j] = 'a' + c;
            j = (j + 1)%5;
            if(j == 0)
                i = (i + 1)%5;
        }
    }
    
    // cout<<"Key Table :\n";

    // for(int i = 0; i < 5; i++) {
    //     for(int j = 0; j < 5; j++)
    //         cout<<keyTable[i][j]<<" ";
    //     cout<<endl;
    // }
}

void getPositionInKeyTable(char c, int &row, int &col) {
    if(c == 'j')
        c = 'i';
    for(int i = 0; i < 5; i++) {
        for(int j = 0;j < 5; j++) {
            if(keyTable[i][j] == c) {
                row = i, col = j;
                return;
            }
        }
    }
}

string playFairCipher(string key, string text) {

    fillKeyTable(key);

    if(text.length()%2) 
        text.push_back('z');

    int n = text.size();
    string encryptedText(text);
    
    for(int i = 0; i < n; i = i + 2) {
        int r1, c1, r2, c2;
        char elem1 = text[i], elem2 = text[i+1];
        
        getPositionInKeyTable(elem1, r1, c1);
        getPositionInKeyTable(elem2, r2, c2);
        
        if(c1 == c2) {
            encryptedText[i] = keyTable[(r1 + 1)%5][c1];
            encryptedText[i + 1] = keyTable[(r2 + 1)%5][c2];
        } else if(r1 == r2) {
            encryptedText[i] = keyTable[r1][(c1 + 1)%5];
            encryptedText[i + 1] = keyTable[r2][(c2 + 1)%5];
        } else {
            encryptedText[i] = keyTable[r1][c2];
            encryptedText[i + 1] = keyTable[r2][c1];
        }
    }

    return encryptedText;
}

int main() {
    string key, text;

    cout<<"Enter key : ";
    cin>>key;

    cout<<"Enter message : ";
    cin>>text;
    
    cout<<"Encrypted message : "<<playFairCipher(key, text)<<endl;
}