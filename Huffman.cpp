#include<iostream>
#include<string.h>
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

float getMenorProbabilidade(vector<float> &prob);

typedef struct nodeArvore
{
    float freq;
    char c;
    struct nodeArvore *esquerda;
    struct nodeArvore *direita;
} nodeArvore;


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
    int numOcurrences[tam];

    for (int i = 0; i < tam; i++) {
        numOcurrences[i] = qtdLetters(alphabet[i], input);
        prob[i] = (float)numOcurrences[i] / sizeof(input);
    }

    print(numOcurrences, tam);
    print(prob, tam);

    sortByProb(prob, alphabet, tam);

    print(prob, tam);
    printAlphabet(alphabet);
    

    // while (alphabet.size() > 1){
    //     float s0 = getMenorProbabilidade(prob);
    //     float s1 = getMenorProbabilidade(prob);
    //     nodeArvore x;
    //     x.esquerda = s0;
    // }


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

float getMenorProbabilidade(vector<float> &prob){
    vector<float>::iterator it = prob.end();
    float aux = prob[prob.size() - 1];
    prob.pop_back();

    return aux;
}