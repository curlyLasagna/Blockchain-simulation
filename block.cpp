#include "block.h"
#include <iostream>
#include <stdio.h>

// Default constructor
block::block() {
	id = 0; 
	nonce = 0; 
	timeId = 0; 
	theHash = ""; 
	previousHash = "";
} 

// A constructor with all properties as arguments
block::block(long id, 
		long nonce, 
		long timeId, 
		std::string theHash, 
		std::string previousHash) {
	this->id = id;
	this->nonce = nonce;
	this->timeId = timeId;
	this->theHash = theHash;
	this->previousHash = previousHash;
}

// A Constructor that calls generateHash 
block::block(long id, long nonce, long timeId, std::string previousHash) 
	: block(id, nonce, timeId, theHash, previousHash) {
	this->theHash = generateHash(previousHash, nonce);
}

// Generates a hash by appending nonce to previousHash and hashing it
std::string block::generateHash(std::string previousHash, long nonce) {
	std::hash<std::string> ptr_hash;
	char *temp = new char;
	std::string nonceString = std::to_string(nonce);
	long unsigned hashBrowns = ptr_hash(previousHash.append(nonceString));
	sprintf(temp, "%020lu", hashBrowns);
	std::string hashToString = temp;  
	return hashToString;
}

long block::mineBlock(int difficulty) {
	std::string bingo (difficulty, '0');
	std::string curr = generateHash(previousHash, nonce);
	while(curr.substr(0, difficulty).compare(bingo) != 0) {
		curr = generateHash(previousHash, nonce);
		nonce++;
	}
	std::cout << "Succesfully mined block with hash: " << curr << std::endl;
	setHash(curr);
	return nonce;
}

// Setters 
void block::setId(long id) { this->id = id; }
void block::setNonce(long nonce) { this->nonce = nonce; }
void block::setTimeId(long timeId) { this->timeId = timeId; }
void block::setHash(std::string hash) { this->theHash = hash; }
void block::setPreviousHash(std::string previousHash) { this->previousHash = previousHash; }

// Getters
long block::getID() const { return id; }
long block::getNonce() const { return nonce; }
long block::getTimeId() const { return timeId; }
std::string block::getHash() { return theHash; }
std::string block::getPreviousHash() { return previousHash; }
