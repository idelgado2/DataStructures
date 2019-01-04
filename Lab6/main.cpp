//
//  main.cpp
//  iofstreamtest
//
//  Created by Isaac Delgado on 2/15/15.
//  Copyright (c) 2015 Isaac Delgado. All rights reserved.
//
#include <fstream>
#include <iostream>
#include "lstacks.h"
#include "listQueue.h"
using namespace std;

bool palindrome(lstacks<char>&, listQueue<char>&, string&);
bool printable(string&);
void pushAdd(lstacks<char>&, listQueue<char>&, string&);
string tolowercase(string &);

int main() {
    lstacks<char> stack;
    listQueue<char> queue;
    
    string word, word2, phrase;
    ifstream numfile;
    numfile.open("lab6.txt");
    
    if (numfile.fail()) {
        cerr << "could not open file" << endl;
        exit(1);
    }
    
    while (getline(numfile, word)) {
        /*for (int i = 0; word[i]; i++) {
         cout << word[i] << " ";
         stack.push(word[i]);
         queue.addQeuue(word[i]);
         
         }*/
        pushAdd(stack, queue, word);
        if (palindrome(stack, queue, word2 = ""))
            cout << word << " Is a palindrome" << endl;
        else
            cout << word << "Not a Palindrome" << endl;
        
        cout<< "Word2 from Queue: " << word2 << endl << endl;
        
    }
    
    cout << endl;
    
    
    cout << "Please enter a word for me to test if it is a palindrome" << endl;
    cin >> phrase;
    if (printable(phrase)) {
        tolowercase(phrase);
        cout << phrase << endl;
        
        pushAdd(stack, queue, phrase);
        
        if (palindrome(stack, queue, word2 = ""))
            cout << phrase << " Is a palindrome" << endl;
        else
            cout << phrase << " Not a Palindrome" << endl;
        
        cout<< "Word2 from Queue: " << word2 << endl << endl;
        
    }
    else
        cerr << "Sorry your input has non-printable characters...GOODBYE\n" << endl;
    
    numfile.close();
}

bool printable(string& word){
    int number = 0;
    for (int i = 0; word[i]; i++){
        if (!isprint(word[i]))
            number++;
    }
    if(number == 0)
        return true;
    else
        return false;
}


string tolowercase(string &word){
    for (int i = 0; word[i]; i++) {
        if (isupper(word[i])) {
            word[i] = tolower(word[i]);
        }
    }
    return word;
}

void pushAdd(lstacks<char>& stack, listQueue<char>& queue, string& word){
    
    for (int i = 0; word[i]; i++) {
        cout << word[i] << " ";
        stack.push(word[i]);
        queue.addQeuue(word[i]);
        
    }
    cout << endl;
}


bool palindrome(lstacks<char>& stack, listQueue<char>& queue, string& holder){
    
    while (!queue.isEmptyQueue() && !stack.isEmptyStack()) {
        
        if (queue.front() == stack.top()) {
            holder += queue.front();
            queue.deleteQueue();
            stack.pop();
            //cout << "in if statment" << endl;
        }
        else{
            while (!queue.isEmptyQueue()) {
                holder+= queue.front();
                queue.deleteQueue();
            }
            return false;
            /*comparison++;
             holder += queue.front();
             queue.deleteQueue();
             stack.pop();
             cout << "in else statment" << endl;*/
        }
    }
    return true;
    
    /*if (comparison == 0)
     return true;
     else
     return false;*/
}






