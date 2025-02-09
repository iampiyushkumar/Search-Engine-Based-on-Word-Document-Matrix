#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <set>
#include <algorithm>
#include <iomanip>
using namespace std;

// Function to convert a string to lowercase
string toLowerCase(const string &s) {
    string result = s;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

// Function to tokenize a string (split into words)
vector<string> tokenize(const string &text) {
    vector<string> words;
    stringstream ss(text);
    string word;
    while (ss >> word) {
        words.push_back(toLowerCase(word));
    }
    return words;
}

// Function to remove stopwords
vector<string> removeStopWords(const vector<string> &words, const set<string> &stopWords) {
    vector<string> filtered;
    for (const auto &word : words) {
        if (stopWords.find(word) == stopWords.end()) {
            filtered.push_back(word);
        }
    }
    return filtered;
}

// Function to build the Word-Document matrix
unordered_map<string, vector<int>> buildWordDocumentMatrix(const vector<string> &documents, const set<string> &stopWords, bool removeStops) {
    unordered_map<string, vector<int>> matrix;
    int docID = 0;
    for (const auto &doc : documents) {
        vector<string> words = tokenize(doc);
        if (removeStops) words = removeStopWords(words, stopWords);
        
        for (const auto &word : words) {
            matrix[word].resize(documents.size(), 0);
            matrix[word][docID]++;
        }
        docID++;
    }
    return matrix;
}

// Function to print matrix
void printMatrix(const unordered_map<string, vector<int>> &matrix, int docCount) {
    cout << "\nWord-Document Frequency Matrix:\n";
    cout << left << setw(15) << "Word";
    for (int i = 0; i < docCount; i++) {
        cout << "Doc " << i + 1 << " ";
    }
    cout << endl;
    for (const auto &entry : matrix) {
        cout << left << setw(15) << entry.first;
        for (int count : entry.second) {
            cout << setw(5) << count << " ";
        }
        cout << endl;
    }
}

// Function to search words and display matrix
void searchQueryMatrix(const unordered_map<string, vector<int>> &matrix, const vector<string> &queryWords, int docCount) {
    cout << "\nSearch Query Matrix:\n";
    cout << left << setw(15) << "Word";
    for (int i = 0; i < docCount; i++) {
        cout << "Doc " << i + 1 << " ";
    }
    cout << endl;
    vector<int> andResult(docCount, 1);
    vector<int> orResult(docCount, 0);
    
    for (const auto &word : queryWords) {
        cout << left << setw(15) << word;
        if (matrix.find(word) != matrix.end()) {
            for (int i = 0; i < docCount; i++) {
                cout << setw(5) << matrix.at(word)[i] << " ";
                if (matrix.at(word)[i] > 0) {
                    orResult[i] = 1;
                } else {
                    andResult[i] = 0;
                }
            }
        } else {
            for (int i = 0; i < docCount; i++) {
                cout << "0    ";
                andResult[i] = 0;
            }
        }
        cout << endl;
    }
    
    cout << "\nAND Search Result (Documents containing all words): ";
    bool foundAnd = false;
    for (int i = 0; i < docCount; i++) {
        if (andResult[i]) {
            cout << "Doc " << i + 1 << " ";
            foundAnd = true;
        }
    }
    if (!foundAnd) cout << "None";
    cout << endl;
    
    cout << "\nOR Search Result (Documents containing at least one word): ";
    bool foundOr = false;
    for (int i = 0; i < docCount; i++) {
        if (orResult[i]) {
            cout << "Doc " << i + 1 << " ";
            foundOr = true;
        }
    }
    if (!foundOr) cout << "None";
    cout << endl;
}

int main() {
    vector<string> documents;
    set<string> stopWords = {"the", "is", "and", "are", "a", "an"};
    int N;
    cout << "Enter number of documents: ";
    cin >> N;
    cin.ignore();
    
    cout << "Enter documents:\n";
    for (int i = 0; i < N; i++) {
        string doc;
        getline(cin, doc);
        documents.push_back(doc);
    }
    
    unordered_map<string, vector<int>> matrixBefore = buildWordDocumentMatrix(documents, stopWords, false);
    printMatrix(matrixBefore, N);
    
    unordered_map<string, vector<int>> matrixAfter = buildWordDocumentMatrix(documents, stopWords, true);
    printMatrix(matrixAfter, N);
    
    while (true) {
        cout << "\nEnter search query (OR type 'exit' to quit): ";
        string query;
        getline(cin, query);
        if (query == "exit") break;
        
        vector<string> queryWords = tokenize(query);
        queryWords = removeStopWords(queryWords, stopWords);
        searchQueryMatrix(matrixAfter, queryWords, N);
    }
    return 0;
}
