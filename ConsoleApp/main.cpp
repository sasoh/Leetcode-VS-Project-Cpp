//  Your task is to determine the RNA complement of a given DNA sequence.
//  Both DNA and RNA strands are a sequence of nucleotides.
//  The four nucleotides found in DNA are adenine(A), cytosine(C), guanine(G), and thymine(T).
//  The four nucleotides found in RNA are adenine(A), cytosine(C), guanine(G), and uracil(U).
//  Given a DNA strand, its transcribed RNA strand is formed by replacing each nucleotide with its complement :
//  G->C
//  C->G
//  T->A
//  A->U

#include <iostream>
#include <string>
using namespace std;

namespace rna_transcription {
    char to_rna(char input) {
        if (input == 'G') return 'C';
        if (input == 'C') return 'G';
        if (input == 'T') return 'A';
        return 'U';
    }

    std::string to_rna(const std::string& input) {
        std::string r{};
        for (const auto&c : input) {
            r.push_back(to_rna(c));
        }
        return r;
    }
}  // namespace rna_transcription

int main() {
    return 0;
}