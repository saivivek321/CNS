#include <bits/stdc++.h>
using namespace std;

string monoAlphabeticCipher(string key, string text) {
    string encryptedText;

    for(char c : text) {
        if(c >= 'a' && c <= 'z')
            c = key[c - 'a'];
        else if(c >= 'A' && c <= 'Z') 
            c = key[c - 'A'];

        encryptedText.push_back(c);
   }

   return encryptedText;
}

int main() {
   string text, key;

   cout<<"Enter key : ";
   cin>>key;

   cout<<"Enter message : ";
   cin>>text;

   cout<<"Encrypted message : "<<monoAlphabeticCipher(key, text)<<endl;
}