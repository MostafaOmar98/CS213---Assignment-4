//
// Created by MostafaOmar on 12/5/2018.
//

#ifndef PROTEIN_H
#define PROTEIN_H
#include "CodonsTable.h"
//#include "DNA.h"
#include "Sequence.h"
class DNA;
using namespace std;
enum Protein_Type {Hormon, Enzyme, TF, Cellular_Function};


class Protein : public Sequence
{
private:
    Protein_Type type;
public:
    // constructors and destructor
    Protein();
    Protein(char * p);
    void Print();
    ~Protein();
    // return an array of DNA sequences that can possibly
    // generate that protein sequence
    DNA* GetDNAStrandsEncodingMe(const DNA & bigDNA);    /// PROBLEM HERE NEED TO BE FIXED
};



#endif //PROG2_ASSIGNMENT4_PROTEIN_H
