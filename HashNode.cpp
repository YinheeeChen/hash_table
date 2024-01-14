/**
 * @file HashNode.cpp
 * @brief Implementation of a HashNode class
 * @author Yinhe Chen
 * @version 12.27
 */
#include<iostream>
#include "HashNode.h"

/**
 * @brief Default constructor for the HashNode class
 */
HashNode::HashNode() {
    // No need for initialization since default values for string members are empty
}

/**
 * @brief Parameterized constructor for the HashNode class
 * @param k The key
 * @param v The value
 */
HashNode::HashNode(string k, string v) {
    key = k;
    value = v;
}

/**
 * @brief Getter function for the key
 * @return The key
 */
string HashNode::getKey() {
    return key;
}

/**
 * @brief Setter function for the value
 * @param v The new value
 */
void HashNode::setValue(string v) {
    value = v;
}

/**
 * @brief Getter function for the value
 * @return The value
 */
string HashNode::getValue() {
    return value;
}

/**
 * @brief Overloaded output operator to print HashNode
 * @param output The output stream
 * @param hn The HashNode to be printed
 * @return The output stream after printing the HashNode
 */
ostream& operator<<(ostream &output, const HashNode &hn) {
    output << "(" << hn.key << ": " << hn.value << ")";
    return output;
}
