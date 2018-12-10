#ifndef RNA_H
#define RNA_H



#include "Sequence.h"
#include "CodonsTable.h"


#include "DNA.h"
#include "Protein.h"


#include <bits/stdc++.h>
using namespace std;

enum RNA_Type {mRNA, pre_mRNA, mRNA_exon, mRNA_intron};

class RNA : public Sequence
{
private:
    RNA_Type type;
public:
    // constructors and destructor
    RNA();
    RNA(char *_seq, RNA_Type atype);
    RNA(const RNA& rhs);
    ~RNA();
    // function to be overridden to print all the RNA information
    void Print();
    // function to convert the RNA sequence into protein sequence
    // function to convert the RNA sequence back to DNA
    DNA ConvertToDNA();
    // using the codonsTable object
    Protein ConvertToProtein( CodonsTable & table);
};
#endif // RNA_H
