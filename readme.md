# 02155 Computer Architecture and Engineering 
This is a RISC-V instruction set simulator, supporting the RV32I instruction subset. The simulator provides 1048576 bytes of memory and execute RISC-V binary files.

## Input and Output
The simulator is run using the static ```Simulator::run```. This method takes the binary file containing the program and a debug-flag. If the debug-flag is set, the simulator outputs program-counter, instruction value, and a register dump for every instruction. After all executions a register dump is printed to stanard out.

Assuming that the ```main``` function is run, a binary result file is dumped in the project root.

## Compiling & Executing
### Compiling with g++
The simulator can be compiled *without* tests using g++ by
```
g++ src/main.cpp src/simulator.cpp include/register.h include/simulator.h -o main
```
Execute by ```./main```
### Compiling using CMake 
The complete project including unit tests can be compiled using CMake by 
```
mkdir build
cd build
cmake ..
cmake --build .
```
Execute by ```./main``` or run the tests using ```ctest```.

## Tests
The project include unit-tests for all instructions along with some more advanced tests. The tests are the provided tests, i.e. task1-task4 along with selected tests from [here](https://github.com/TheAIBot/RISC-V_Sim/tree/master/RISC-V_Sim/InstructionTests)