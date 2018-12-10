//
// Created by MostafaOmar on 12/5/2018.
//

#ifndef CODONSTABLE_H
#define CODONSTABLE_H
// struct representing a codon of 3 DNA/RNA characters and ï؟½\0ï؟½
struct Codon
{
    char value[4];    	    // 4th location for null character
    char AminoAcid;  	    // corresponding AminoAcid according to Table
};

// need to create one object of that class to load the AminoAcids table
// into memory
class CodonsTable
{
private:
    Codon codons[64];
public:
    // constructors and destructor
    CodonsTable();
    ~CodonsTable();
    // function to load all codons from the given text file
    void LoadCodonsFromFile(char* codonsFileName);
    char getAminoAcid(char * value);
    void setCodon(char * value, char AminoAcid, int index);
};


#endif //PROG2_ASSIGNMENT4_CODONSTABLE_H
