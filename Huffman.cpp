#include <bits/stdc++.h>
#include<vector>
#include<fstream>

using namespace std;

bool isInAlphabet(char x, vector<char> a);

void printAlphabet(vector<char> a);

void getAlphabet(char input[], vector<char> &alphabet);

int qtdLetters(char x, char a[]);

template<class T>
void print(T arr, int tam);

void sortByProb(vector<float> &xa, vector<char> &alph, int tam);

//float getMenorProbabilidade(vector<float> &prob);

struct MinHeapNode { 
  
    // One of the input characters 
    char data; 
  
    // Frequency of the character 
    unsigned freq; 
  
    // Left and right child 
    MinHeapNode *left, *right; 
  
    MinHeapNode(char data, unsigned freq) 
  
    { 
  
        left = right = NULL; 
        this->data = data; 
        this->freq = freq; 
    } 
}; 
  
// For comparison of 
// two heap nodes (needed in min heap) 
struct compare { 
  
    bool operator()(MinHeapNode* l, MinHeapNode* r) 
  
    { 
        return (l->freq > r->freq); 
    } 
}; 
  
// Prints huffman codes from 
// the root of Huffman Tree. 
void printCodes(struct MinHeapNode* root, string str) 
{ 
  
    if (!root) 
        return; 
  
    if (root->data != '$') 
        cout << root->data << ": " << str << "\n"; 
  
    printCodes(root->left, str + "0"); 
    printCodes(root->right, str + "1"); 
} 
  
// The main function that builds a Huffman Tree and 
// print codes by traversing the built Huffman Tree 
void HuffmanCodes(vector<char> data, int freq[], int size) 
{ 
    struct MinHeapNode *left, *right, *top; 
  
    // Create a min heap & inserts all characters of data[] 
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap; 
  
    for (int i = 0; i < size; ++i) 
        minHeap.push(new MinHeapNode(data[i], freq[i])); 
  
    // Iterate while size of heap doesn't become 1 
    while (minHeap.size() != 1) { 
  
        // Extract the two minimum 
        // freq items from min heap 
        left = minHeap.top(); 
        minHeap.pop(); 
  
        right = minHeap.top(); 
        minHeap.pop(); 
  
        // Create a new internal node with 
        // frequency equal to the sum of the 
        // two nodes frequencies. Make the 
        // two extracted node as left and right children 
        // of this new node. Add this node 
        // to the min heap '$' is a special value 
        // for internal nodes, not used 
        top = new MinHeapNode('$', left->freq + right->freq); 
  
        top->left = left; 
        top->right = right; 
  
        minHeap.push(top); 
    } 
  
    // Print Huffman codes using 
    // the Huffman tree built above 
    printCodes(minHeap.top(), ""); 
} 


int main(){

    // ifstream file;
    // string in;
    // string lines[32];

    // file.open("input.txt");

    // int i = 0;
    // while(!file.eof()){
    //     getline(file, in);

    //     lines[i] = in;

    //     //cout << in << endl;

    // }

    // // char [lines[i].size() + 1];
    // // strcpy(cstr, lines[i].c_str());

    char input[] = "hhhadjhhaaaeeajj";
    vector<char> alphabet;

    alphabet.push_back('$');

    getAlphabet(input, alphabet);

    vector<char>::iterator it = alphabet.begin();
    alphabet.erase(it);

    int tam = alphabet.size();
    vector<float> prob(tam);
    int freq[tam];

    for (int i = 0; i < tam; i++) {
        freq[i] = qtdLetters(alphabet[i], input);
        prob[i] = (float)freq[i] / sizeof(input);
    }

    print(freq, tam);
    print(prob, tam);

    // sortByProb(prob, alphabet, tam);

    // print(prob, tam);
    // printAlphabet(alphabet);

    int size = alphabet.size() / sizeof(alphabet[0]);

    HuffmanCodes(alphabet, freq, size);

    //file.close();
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////
bool isInAlphabet(char x, vector<char> a){
    for (int i = 1; i < a.size(); i++){
        if (x == a[i])
            return true;
    }
    return false;
}

void printAlphabet(vector<char> a){
    for (int i = 0; i < a.size(); i++){
        cout << a[i];
    }
    cout << endl;
}

void getAlphabet(char input[], vector<char> &alphabet){
    for (int i = 0; i < strlen(input); i++) {
        if (isInAlphabet(input[i], alphabet)){
            ;
        }
        else{
            alphabet.push_back(input[i]);
            cout << "Adicionando letra: " << input[i] << endl;
            printAlphabet(alphabet);
        }
    }
}

int qtdLetters(char x, char a[]){
    int count = 0;
    for (int i = 0; i < strlen(a); i++) {
        if(x == a[i])
            count++;
    }
    return count;
}

template<class T>
void print(T arr, int tam){
    for (int i = 0; i < tam; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sortByProb(vector<float> &a, vector<char> &alph, int tam){
    float aux;
    char buff;

    for(int i = tam - 1; i >= 0 ; i--) {
        for(int j = tam - i - 1; j >= 0; j--) {
            if(a[j] < a[j + 1]) {
                aux = a[j + 1];
                a[j + 1] = a[j];
                a[j] = aux;

                buff = alph[j + 1];
                alph[j + 1] = alph[j];
                alph[j] = buff;
            }
        }
    }
}

// float getMenorProbabilidade(vector<float> &prob){
//     vector<float>::iterator it = prob.end();
//     float aux = prob[prob.size() - 1];
//     prob.pop_back();

//     return aux;
// }