#pragma once
#include <functional>
#include <string>

class block {
	private:
		long id, nonce, timeId;
		std::string theHash, previousHash;
	
	public: 
		// Empty constructor
		block(); 									

		// Constructor with all fields
		block(long id, long nonce, long timeId, std::string theHash, std::string previousHash);	

		// Constructor that has a function that generates a hash
		block(long id, long nonce, long timeId, std::string previousHash);				

		// Mining function
		long mineBlock(int difficulty);

		// Hash function
		std::string generateHash(std::string previousHash, long nonce); 

		// Setters
		void setId(long);
		void setNonce(long);
		void setTimeId(long);
		void setHash(std::string);
		void setPreviousHash(std::string);

		// Getters
		long getID() const;
		long getNonce() const ;
		long getTimeId() const;
		std::string getHash();
		std::string getPreviousHash();
		void printObj();
};
