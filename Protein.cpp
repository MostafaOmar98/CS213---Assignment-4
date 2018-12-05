//
// Created by MostafaOmar on 12/5/2018.
//

/*
 * TODO:
 * implement templates
 */

#include "Protein.h"
#include "DNA.h"
#include "CodonsTable.h"

Protein::Protein()
{
    type = Cellular_Function;
}
Protein::Protein(char * p)
{
    type = Cellular_Function;

    seq = new char[MAX_SIZE]; // add MAX_SIZE to sequence ya hanafy
    int i;
    for (i = 0; p[i] != 0; ++i)
        seq[i] = p[i];
    seq[i] = 0;
}
Protein::~Protein() {}
Protein::DNA* GetDNAStrandsEncodingMe(const DNA & bigDNA)
{
    CodonsTable table;
    int idx = 0;
    DNA* DNAEncoders= new DNA[MAX_SIZE];
    for (int i = bigDNA.getStartIndex(); i <= bigDNA.getEndIndex(); ++i) // Implement getters in DNA ya hanafy
    {
        for (int j = i + 1; j <= bigDNA.getEndIndex(); ++i)
        {
            DNA tempDNA = bigDNA; // implement assignment operator ya hanafy
            tempDNA.setStartIndex(i); // implement setters ya hanafy
            tempDNA.setEndIndex(j);
            Protein tempProtein = (tempDNA.ConvertToRNA()).ConvertToProtein(table);
            if (tempProtein.seq == seq)
            {

                DNAEncoders[idx++] = tempDNA;
            }
        }
    }
}