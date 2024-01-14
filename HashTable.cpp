/**
 * @file HashTable.cpp
 * @brief Implementation of a HashTable class
 * @author Yinhe Chen
 * @version 12.27
 */
#include "HashTable.h"
#include<iostream>
using namespace std;

/**
 * @brief Default constructor for the HashTable class
 */
HashTable::HashTable() {
    tablesize = 10;
    table = new HashNode[10];
}

/**
 * @brief Parameterized constructor for the HashTable class
 * @param size The size of the hash table
 */
HashTable::HashTable(int size) {
    tablesize = size;
    table = new HashNode[size];
}

/**
 * @brief Destructor for the HashTable class
 */
HashTable::~HashTable() {
    delete [] table;
}

/**
 * @brief Hash function for generating an index from a key
 * @param k The key to be hashed
 * @return The hashed index
 */
int HashTable::hashFunction(string k){
    int hashValue = 0;
    for (char c: k) {
        hashValue += static_cast<int>(c);
    }
    return hashValue % tablesize;
}

/**
 * @brief Inserts a new key-value pair into the HashTable.
 * @param k The key
 * @param v The value
 * @return true if successful, false if the key already exists or the table is full
 */
bool HashTable::insert(string k, string v){
    int index = hashFunction(k);
    HashNode newNode(k, v);
    while (table[index].getKey() != "") {
        index = (index + 1) % tablesize;
        if (index == hashFunction(k)) {
            return false;
        }
    }
    table[index] = newNode;
    return true;
}

/**
 * @brief Searches for the index of a key in the HashTable.
 * @param k The key to search for
 * @return The index of the key if found, -1 if not found
 */
int HashTable::search(string k){
    int index = hashFunction(k);
    while (table[index].getKey() != "") {
        if (table[index].getKey() == k) {
            return index;
        }
        index = (index + 1) % tablesize;
    }
    return -1; // Key not found
}

/**
 * @brief Updates the value of an existing key in the HashTable.
 * @param k The key to update
 * @param v The new value
 * @return true if successful, false if the key does not exist
 */
bool HashTable::update(string k, string v){
    int index = search(k);

    if (index != -1) {
        table[index].setValue(v);
        return true;
    }

    return false;
}

/**
 * @brief Looks up the value associated with a key in the HashTable.
 * @param k The key to look up
 * @return The value associated with the key if found, an empty string if not found
 */
string HashTable::lookup(string k){
    int index = search(k);

    if (index != -1) {
        return table[index].getValue();
    }

    return "";
}

/**
 * @brief Overloaded stream insertion operator to print the HashTable.
 * @param output The output stream
 * @param ht The HashTable to be printed
 * @return The output stream after printing the HashTable
 */
ostream& operator<<(ostream &output, const HashTable &ht) {
    for (int i = 0; i < ht.tablesize; i++) {
        output << i << ": ";
        if (ht.table[i].getKey() != "") {
            output << ht.table[i];
        }
        output << endl;
    }
    return output;
}