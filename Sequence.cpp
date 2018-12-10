#include "Sequence.h"
#include <bits/stdc++.h>
using namespace std;
//Sequence :: Sequence (char * strand){
//    int sz = (sizeof strand) / (sizeof strand[0]) ;
//    this->strand = new char[sz];
//    for(int i = 0 ; i < sz ; ++i)
//        this->strand[i] = strand [i];
//}
Sequence :: Sequence (){
    seq = new char('\0');
    len = 0;
}
Sequence::Sequence(int length  ){
//    this->strand = strand ;
    this->seq = new char[length +1];
    len = length;

}
Sequence :: Sequence (char * s){
    this->seq = new char [strlen(s) + 1];
    strcpy(seq , s);
    len = strlen(s);
}
Sequence :: Sequence (string s){
    this->seq = new char [s.size() +1];
    strcpy(seq , s.c_str());
    len = s.size();
}
Sequence :: Sequence (Sequence & rhs){
    if (seq)
    {
        delete [] seq;
        seq = 0;
    }
    this->seq = new char[strlen(rhs.seq) + 1];
    strcpy(this->seq , rhs.seq );
    len = rhs.len;
}
///template<class T>
Sequence& Sequence:: operator= (Sequence& rhs)
{
    if (seq != 0)
    {
        delete [] seq;
        seq = 0;
    }
    seq = new char [rhs.len];
    len = rhs.len;
    strcpy(seq, rhs.seq);
    return rhs;
}


Sequence :: ~Sequence(){
    delete [] seq;
    seq = 0;
}
void  Sequence ::Print() {
    cout << seq << '\n';
    return;
}