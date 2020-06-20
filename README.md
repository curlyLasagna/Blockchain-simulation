# Blockchain-simulation
- A class assignment where the concept of binary search trees and its search algorithms are implemented to simulate a block-chain at a high level.

# Block Object
#### Genesis Block
```    
block:block(
  long id,
  long nonce,
  long timeId,
  std::string theHash,
  std::string previousHash)
```     
#### Generated Blocks from the genesis block
```
block::block(
  long id,
  long nonce,
  long timeId,
  std::string previousHash) {
  this->theHash = generateHash(previousHash, nonce)
}
```
# Difficulty
- The program accepts a single intereger argument representing the difficulty.
- The difficulty being the number of zeroes padded before the actual hash

# Compiling
- Run `make` to compile the program
- Run `make clean` to remove object files and executables

# Running
- `./blockChain` runs the program with the default difficulty of 2
- `./blockChain 4` runs the program with the difficult of 4
