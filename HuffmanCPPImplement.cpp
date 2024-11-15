// HuffmanCPPImplement.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <utility>
#include <string>
#include <map>

using namespace std;


struct HufftreeNode {
    char character;
    int charFreq;
    
    HufftreeNode* left;
    HufftreeNode* right;

    HufftreeNode *next;
    //HufftreeNode constructor
    HufftreeNode() : 
        character(), charFreq(0) {};
    HufftreeNode(char charctr, int chFreq) :
        character(charctr), charFreq(chFreq), next(nullptr) {};
    HufftreeNode(char charctr, int chFreq, HufftreeNode* nextNode) :
        character(charctr), charFreq(chFreq), next(nextNode) {};

};


//Primary Helper Functions 

map<char, int> charFrequency(string inputStr) {
    map <char, int> freqList;
//"read the string and document the characters and their number of occurences
//store in a map as a pair

    for (char strChar : inputStr) {     //traverses through string char by char
        freqList[strChar]++;
    }

    return freqList;
}

//Heap and Binary Tree Constructors
HufftreeNode* createPriorityQueue(map<char, int> strFreqList) {
    HufftreeNode* huffmanQueue = new HufftreeNode();
    int queueSize = 0;
    for (const auto& pair : strFreqList) {
        huffmanQueue->next = new HufftreeNode(pair.first, pair.second);
        queueSize++;
    }

    cout << "Priority Queue Size: " << queueSize << "\n";
    return huffmanQueue;
}

HufftreeNode* createHuffmanTree(HufftreeNode* current, int freq) {
 //Implementation by recursion

    if (current == nullptr) {                                      //basket case conditiona;
        HufftreeNode* newLeaf = new HufftreeNode();
        newLeaf->charFreq = freq;
        return newLeaf;
}                                                                 //Recursion will sort the binary tree by frequency

    if (freq < current->charFreq) {                               //entries with frequencies less than the given node are now the left child
        current->left = createHuffmanTree(current->left, freq);
    }
    
    else {                                                       //all other entries become the right child
        current->right = createHuffmanTree(current->right, freq);

    }
                                        

    return current;
}

//FIX, THIS CODE STINKS AND SO DO YOU
HufftreeNode* populateHuffTree(HufftreeNode* queueHead, map<int, char> freqList) {
    HufftreeNode* huffRoot = nullptr;

    for (const auto& pair : freqList) {
        queueHead = createHuffmanTree(queueHead, pair.second);
    }
    huffRoot = queueHead;
    
    return huffRoot;
    
}

//encoding and decryption functions
string static stringEncode() {
    string encodedStr = "";

    return encodedStr;
}

string static stringDecode() {
    string decodedStr = "";

    return decodedStr;
}

int main()
{
    //principle string
    string readStr = "EMUFPHZLRFAXYUSDJKZLDKRNSHGNFIVJYQTQUXQBQVYUVLLTREVJYQTMKYRDMFDVFPJUDEEHZWETZYVGWHKKQETGFQJNCEGGWHKK ? DQMCPFQZDQMMIAGPFXHQRLIMVMZJANQLVKQEDAGDVFRPJUNGEUNAQZGZLECGYUXUEENJTBJLBQCRTBJDFHRRYIZETKZEMVDUFKSJHKFWHKUWQLSZFTIHHDDDUVH ? DWKBFUFPWNTDFIYCUQZEREEVLDKFEZMOQQJLTTUGSYQPFEUNLAVIDXFLGGTEZ ? FKZBSFDQVGOGIPUFXHHDRKFFHQNTGPUAECNUVPDJMQCLQUMUNEDFQELZZVRRGKFFVOEEXBDMVPNFQXEZLGREDNQFMPNZGLFLPMRJQYALMGNUVPDXVKPENDYAHROHNLSRHEOCPTEOIBIDYSHNAIACHTNREYULDSLLSLLNOHSNOSMRWXMNETPRNGATIHNRARPESLNNELEBLPIIACAEWMTWNDITEENRAHCTENEUDRETNHAEOETFOLSEDTIWENHAEIOYTEYQHEENCTAYCREIFTBRSPAMHHEWENATAMATEGYEERLBTEEFOASFIOTUETUAEOTOARMAEERTNRTIBSEDDNIAAHTTMSTEWPIEROAGRIEWFEBAECTDDHILCEIHSITEGOEAOSDDRYDLORITRKLMLEHAGTDHARDPNEOHMGFMFEUHEECDMRIPFEIMEHNLSSTTRTVDOHW ? OBKRUOXOGHULBSOLIFBBWFLRVQQPRNGKSSOTWTQSJQSSEKZZWATJKLUDIAWINFBNYPVTTMZFPKWGDKZXTJCDIGKUHUAUEKCARABCDEFGHIJKLMNOPQRSTUVWXYZABCDAKRYPTOSABCDEFGHIJLMNQUVWXZKRYPBRYPTOSABCDEFGHIJLMNQUVWXZKRYPTCYPTOSABCDEFGHIJLMNQUVWXZKRYPTODPTOSABCDEFGHIJLMNQUVWXZKRYPTOSETOSABCDEFGHIJLMNQUVWXZKRYPTOSAFOSABCDEFGHIJLMNQUVWXZKRYPTOSABGSABCDEFGHIJLMNQUVWXZKRYPTOSABCHABCDEFGHIJLMNQUVWXZKRYPTOSABCDIBCDEFGHIJLMNQUVWXZKRYPTOSABCDEJCDEFGHIJLMNQUVWXZKRYPTOSABCDEFKDEFGHIJLMNQUVWXZKRYPTOSABCDEFGLEFGHIJLMNQUVWXZKRYPTOSABCDEFGHMFGHIJLMNQUVWXZKRYPTOSABCDEFGHINGHIJLMNQUVWXZKRYPTOSABCDEFGHIJLOHIJLMNQUVWXZKRYPTOSABCDEFGHIJLPIJLMNQUVWXZKRYPTOSABCDEFGHIJLMQJLMNQUVWXZKRYPTOSABCDEFGHIJLMNRLMNQUVWXZKRYPTOSABCDEFGHIJLMNQSMNQUVWXZKRYPTOSABCDEFGHIJLMNQUTNQUVWXZKRYPTOSABCDEFGHIJLMNQUVUQUVWXZKRYPTOSABCDEFGHIJLMNQUVWVUVWXZKRYPTOSABCDEFGHIJLMNQUVWXWVWXZKRYPTOSABCDEFGHIJLMNQUVWXZXWXZKRYPTOSABCDEFGHIJLMNQUVWXZKYXZKRYPTOSABCDEFGHIJLMNQUVWXZKRZZKRYPTOSABCDEFGHIJLMNQUVWXZKRYABCDEFGHIJKLMNOPQRSTUVWXYZABCD ";
    cout << readStr << "\n";

    //initialize main function maps and data stucts
    map<char, int> freqTable;
    freqTable = charFrequency(readStr);                      //assign frequency table to the one storing character frequencies

    createPriorityQueue(freqTable);
                                                                    //print and iterate through map
    for (const auto& pair : freqTable) {
        if (pair.first == ' ') {
            cout << "Char: SPACE";
            cout << " Frequency: " << pair.second << "\n";
        }
        else {
            cout << "Char: " << pair.first;

            cout << "     Frequency: " << pair.second << "\n";
        }
    }
}
    
