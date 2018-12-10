#include "DNA.h"
class RNA;
class Protein;


using namespace std;
DNA :: DNA () {
    startIndex = -1;
    endIndex = -1;
    complementary_strand = NULL;
    seq = NULL;
    this->type = promoter ;
}
DNA :: DNA (char * aseq , DNA_Type atype ) : Sequence(aseq) {
    this->type = atype;
    startIndex = 0;
    endIndex = len - 1;
}
DNA::DNA(char * seq): Sequence(seq){

}
DNA :: DNA(const DNA & rhs ){
    this->seq = rhs.seq;
    /// this->complementary_strand = new DNA(rhs.complementary_strand)    ;/// want to check this again
    this->endIndex =rhs.endIndex ;
    this->startIndex = rhs.startIndex;
    this->type = rhs.type;
    /// this->BuildComplementaryStrand();
}
void DNA:: Print(){
    cout<<"TYPE : "<<this->type <<'\n';
    cout<<"strand  : "<<this->seq <<'\n';
    cout<<"start index : " <<this->startIndex <<" - end index : "<<this->endIndex<<'\n';
}
void DNA::setStartIndex(int idx)
{
    startIndex = idx;
}
void DNA::setEndIndex(int idx)
{
    endIndex = idx;
}
int DNA::getStartIndex() const
{
    return startIndex;
}
int DNA::getEndIndex() const
{
    return endIndex;
}

DNA :: ~DNA(){
    delete [] complementary_strand;
}
void DNA ::BuildComplementaryStrand(){ /// each A to T  , each C to G and vice versa
    char *  retseq = new char[len +1 ] ; ///
    strcpy(retseq , seq);
    int l = startIndex , r = endIndex;
    while(l <r){            /// reversing the seq first
        char temp = retseq[l];
        retseq[l] = retseq[r];
        retseq[r] = temp ;
        l++,r++;
    }
    /// changing characters
    for(int i = startIndex ; i < endIndex ; ++i){
        if(retseq[i] =='T' ||retseq[i] == 't')
            retseq[i] = 'A';
        else if(retseq[i] =='A' ||retseq[i] == 'a')
            retseq[i]='T';
        else if(retseq[i] =='C' ||retseq[i] == 'c')
            retseq[i]='G';
        else if(retseq[i] =='G' ||retseq[i] == 'g')
            retseq[i] = 'C';
    }
    complementary_strand =new DNA(retseq , promoter);
    return ;  /// no return the complementary is allocated in the heap no need to return anything
}
DNA DNA::getCSDNA() const
{
    return *complementary_strand;
}
RNA* DNA ::ConvertToRNA(){/// change the complementary strand to RNA by replacing each T by U
    char * retseq = new char[complementary_strand->len +1];
    strcpy(retseq , complementary_strand->seq); /// copying the complementary seq then converting it
    for(int i = startIndex ; i < endIndex ; ++i){
        if(retseq[i] =='T' || retseq[i] =='t')
            retseq[i] = 'U';
    }
//    RNA ret(retseq , mRNA);         /// mRNA came from converting the DNA
//    return ret;
}
/// done with class if you need templates you need to add here the data types  used
/// for e.q vector <int >
/// note by the TA