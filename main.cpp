/* Include files */
#include <iostream>
#include <array>
#include <ctime>
#include <time.h>

/* Header files */
#include "block.h"
#include "BinaryTree.h"

/* Macros */
#define MAX_SIZE 100

/* Function prototypes */
void part1(std::array<block, MAX_SIZE>, std::time_t time);
void part2(std::array<block, MAX_SIZE>, std::time_t time, int difficulty);
void part3(std::array<block, MAX_SIZE> blockChain);

int main(int argc, char** argv) {
	/* Accepts an unsigned integer argument as difficulty 
	 * If no argument is accepted, the default difficulty of 2 is used*/
	int difficulty = 2;

	if (argc == 2) {
		difficulty = atoi(argv[1]);
		if(difficulty < 0) {
			std::cerr << "Argument must be posiitve\n";
			exit(-1);
		}
	}

	else if (argc > 2) {
		std::cerr << "Error occured\n";
		std::cerr << "Usage: " << argv[0] << " [int]\n";
		exit(-1);
	}

	std::array<block, MAX_SIZE> blockChain;
	std::time_t time = std::time(0);

	/* Genesis block */
	blockChain[0] = block(0, 0, time, "");

	/* Part 1: 
	 * Simple blockchain, where nonce 
	 * is a randomly generated number */
	part1(blockChain, time);

	/* Part 2:
	 * Adding a mining method that 
	 * returns a nonce, which, if you
	 * supply it as an argument to 
	 * the generateHash function, will return
	 * a hash that starts with n amount of 
	 * zeroes at the very start of the hash */
	part2(blockChain, time, difficulty);
	part3(blockChain);
	return 0;
}

void part1(std::array<block, MAX_SIZE> blockChain, std::time_t time) {
	/* Seed time */
	srand(std::time(nullptr));

	/* Generate the rest of the blocks */
	for(int x = 1; x < MAX_SIZE; x++) {
		int randNum = rand();
		blockChain[x] = block(x, randNum, time, blockChain[x-1].getHash());	
	}
}

void part2(std::array<block, MAX_SIZE> blockChain, std::time_t time, int difficulty) {
	srand(std::time(nullptr));
	for(int x = 1; x < MAX_SIZE; x++) {
		blockChain[x] = block();
		blockChain[x].setId(x);
		blockChain[x].setTimeId(time);
		blockChain[x].setPreviousHash(blockChain[x-1].getHash()); 	
		blockChain[x].setNonce(blockChain[x].mineBlock(difficulty));
	}
}

void part3(std::array<block, MAX_SIZE> blockChain) {
	// Prints the result of bfs and inorder searches
	BinaryTree<block> *blockTree = new BinaryTree<block>();

	for(size_t x = 0; x < MAX_SIZE; x++) 
		blockTree->add(blockChain[x]);

	std::cout << "Depth first traversal\n";
	blockTree->inOrder(blockTree->root);

	std::cout << std::endl;

	std::cout << "Breadth first traversal\n";
	blockTree->bfs();
}
