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

// A constructor with all of the properties as arguments.
// This serves as the genesis or starting block
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

// A Constructor that calls generateHash for any block after the genesis
block::block(long id, long nonce, long timeId, std::string previousHash) 
	: block(id, nonce, timeId, theHash, previousHash) {
	this->theHash = generateHash(previousHash, nonce);
}

// Generates a hash by appending nonce to previousHash and hashing it
std::string block::generateHash(std::string previousHash, long nonce) {
	/* Hashes the string. std::hash returns a size_t representation 
	 * of the hash value passed parameter */
	std::hash<std::string> ptr_hash;
	char *temp = new char;
	// Store the nonce as a string to be appended for the generated hash
	std::string nonceString = std::to_string(nonce);
	// hashBrowns contains the hashed version of the previousHash with the nonce appended 
	long unsigned hashBrowns = ptr_hash(previousHash.append(nonceString));
	// 20 padded zeroes is the limit 
	sprintf(temp, "%020lu", hashBrowns);
	std::string hashToString = temp;  
	return hashToString;
}

long block::mineBlock(int difficulty) {
	// Compares 
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
