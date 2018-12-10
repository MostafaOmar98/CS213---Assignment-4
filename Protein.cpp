//
// Created by MostafaOmar on 12/5/2018.
//

/*
 * TODO:
 * implement templates
 */
class DNA;
#include "Protein.h"
#define MAX_SIZE 10000
Protein::Protein()
{
    type = Cellular_Function;
}
Protein::Protein(char * p) : Sequence (p)
{
    type = Cellular_Function;
}
Protein::~Protein() {
}
DNA* Protein::GetDNAStrandsEncodingMe(const DNA & bigDNA)
{
    CodonsTable table;
    int idx = 0;
    DNA* DNAEncoders= new DNA[MAX_SIZE];
    for (int i = bigDNA.getStartIndex(); i <= bigDNA.getEndIndex(); ++i) // Implement getters in DNA ya hanafy
    {
        for (int j = i + 1; j <= bigDNA.getEndIndex(); ++i)
        {
            DNA tempDNA(bigDNA);
            tempDNA.setStartIndex(i);
            tempDNA.setEndIndex(j);
//            Protein tempProtein = (tempDNA.ConvertToRNA()).ConvertToProtein(table);
//            if (tempProtein.seq == seq)
//            {
//                DNAEncoders[idx++] = tempDNA;
//            }
        }
    }
}

void Protein::Print()
{
    cout << "Type: " << type << endl;
    cout << seq << endl;
}
