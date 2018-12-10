//
// Created by MostafaOmar on 12/5/2018.
//

/*
 * TODO:
 * Implement with templates
 */


#include "CodonsTable.h"
#include <fstream>
using namespace std;
// constructors and destructor
CodonsTable::CodonsTable()
{
    char fileName[] = "RNA_codon_table";
    LoadCodonsFromFile(fileName);
}
CodonsTable::~CodonsTable() {}
// function to load all codons from the given text file
void CodonsTable::LoadCodonsFromFile(char* codonsFileName)
{
    ifstream cFile(codonsFileName);
    char value[4];
    int i = 0;
    while (cFile >> value)
    {
        for (int j = 0; j < 4; ++j)
            codons[i].value[j] = value[j];
        codons[i].value[3] = 0;
        char AminoAcid;
        cFile >> AminoAcid;
        codons[i].AminoAcid = AminoAcid;
        ++i;
    }
}
char CodonsTable::getAminoAcid(char * value)
{
    for (int i = 0; i < 64; ++i)
    {
        if (codons[i].value == value)
            return codons[i].AminoAcid;
    }
    // Throw exception here if not found
}
void CodonsTable::setCodon(char * value, char AminoAcid, int index)
{
    Codon newCodon;
    for (int i = 0; i < 4; ++i)
        newCodon.value[i] = value[i];
    newCodon.value[3] = 0;
    newCodon.AminoAcid = AminoAcid;
    codons[index] = newCodon;
}
