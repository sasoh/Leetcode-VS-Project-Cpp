#include <algorithm>
#include <format>
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <cstdint>
#include <cstdio>
#include <sstream>
#include <ios>
using namespace std;

//  A simple 8 - bit CPU emulator must be debugged.The CPU has 4 registers(R0, R1, R2, R3) initialized to 0.
//  Instructions are encoded as hexadecimal bytes :
//      01 X V : MOV - Load value V into register RX
//      02 X Y : ADD - Add register RY to register RX
//      03 X Y : SUB - Subtract register RY from register RX
//      04 X Y : MUL - Multiply register RX by register RY
//      05 X : INC - Increment register RX by 1
//      06 X : DEC - Decrement register RX by 1
//      FF : HLT - Halt execution
//  Where X and Y are register indices(0 - 3), and V is an immediate byte value.
//  All arithmetic wraps at 256 (8 - bit unsigned).Overflow wraps to 0, underflow wraps to 255.
//  The first instruction is not guaranteed to be 01 (MOV).Programs may start with any instruction, including 05 (INC) or 06 (DEC).
//  The smallest valid program is just FF(HLT).
//  Execute the program and output the final register values.

static void processProgram(const string& p, vector<uint8_t>& registers) {
    int op{0};
    int x{0};
    int v{0};
    istringstream ss{ p };
    do {
        ss >> hex >> op;
        if (op == 0x1) {
            // X V : MOV - Load value V into register RX
            ss >> hex >> x;
            ss >> hex >> v;
            registers[x] = v;
        }
        else if (op == 0x2) {
            // X Y : ADD - Add register RY to register RX
            ss >> hex >> x;
            ss >> hex >> v;
            registers[x] += registers[v];
        }
        else if (op == 0x3) {
            // X Y : SUB - Subtract register RY from register RX
            ss >> hex >> x;
            ss >> hex >> v;
            registers[x] -= registers[v];
        }
        else if (op == 0x4) {
            // X Y : MUL - Multiply register RX by register RY
            ss >> hex >> x;
            ss >> hex >> v;
            registers[x] *= registers[v];
        }
        else if (op == 0x5) {
            // X : INC - Increment register RX by 1
            ss >> hex >> x;
            registers[x]++;
        }
        else if (op == 0x6) {
            // X : DEC - Decrement register RX by 1
            ss >> hex >> x;
            registers[x]--;
        }
        else if (op == 0xFF) {
            // HLT - Halt execution
            break;
        }
    } while(1);
}

int main()
{
    //string program;
    //getline(cin, program); // Space-separated hex bytes representing CPU instructions
    //string program = "01 00 0A 01 01 05 02 00 01 03 00 01 FF"s;
    //string program = "01 00 F0 01 01 20 02 00 01 FF"s;
    string program = "FF"s;
    vector<uint8_t> registers(4, 0);
    processProgram(program, registers);
    for (int i{0}; i < registers.size(); ++i) {
        cout << static_cast<int>(registers[i]) << "\n";
    }
    //cout << "Registers = ";
    //ostream_iterator<unsigned int> out{cout, " "};
    //ranges::copy(registers, out);
    //cout << "\n";
}