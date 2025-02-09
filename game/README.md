# Search Engine Matrix

A console-based search engine built in C++ that creates a **Word-Document Frequency Matrix**, removes stopwords, and supports **Boolean search (AND/OR operations)**.

## Features
- Tokenizes documents and builds a word frequency matrix.
- Removes common stopwords.
- Supports search queries with AND/OR logic.

## Usage
- Enter multiple documents as input.
- View the word-document matrix before and after stopword removal.
- Enter a search query to find relevant documents.

## Run the Program
```sh
g++ search_engine.cpp -o search_engine
./search_engine