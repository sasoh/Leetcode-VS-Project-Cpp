//  Codon	            Amino Acid
//  AUG	                Methionine
//  UUU, UUC	        Phenylalanine
//  UUA, UUG	        Leucine
//  UCU, UCC, UCA, UCG	Serine
//  UAU, UAC	        Tyrosine
//  UGU, UGC	        Cysteine
//  UGG	                Tryptophan
//  UAA, UAG, UGA	    STOP
//  If you encounter any of the stop codons, ignore the rest of the sequence — the protein is complete.

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std::string_literals;

namespace {
    using std::string;
    using std::map;
    static map<string, string> ctoa{
        {"AUG"s, "Methionine"},
        {"UUU"s, "Phenylalanine"},
        {"UUC"s, "Phenylalanine"},
        {"UUA"s, "Leucine"},
        {"UUG"s, "Leucine"},
        {"UCU"s, "Serine"},
        {"UCC"s, "Serine"},
        {"UCA"s, "Serine"},
        {"UCG"s, "Serine"},
        {"UAU"s, "Tyrosine"},
        {"UAC"s, "Tyrosine"},
        {"UGU"s, "Cysteine"},
        {"UGC"s, "Cysteine"},
        {"UGG"s, "Tryptophan"}
    };

    static bool isStop(const string& s) {
        return s == "UAA"s || s == "UAG"s || s == "UGA"s;
    }
}

namespace protein_translation {
    using std::string;
    using std::vector;

    auto proteins(const string& input) {
        vector<string> r{};

        for (auto i{ 0 }; i < input.size(); i += 3)
        {
            auto substring = input.substr(i, 3);
            if (isStop(substring)) {
                break;
            }
            r.push_back(ctoa[substring]);
        }

        return r;
    }
}  // namespace protein_translation

int main() {
    //std::vector<std::string> p = protein_translation::proteins("AUG");
    //std::vector<std::string> expected{ "Methionine" };
    protein_translation::proteins("UGGUGUUAUUAAUGGUUU");
    return 0;
}