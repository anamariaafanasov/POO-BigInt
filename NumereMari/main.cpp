#include <iostream>
#include <cstring>
#include "NumereMari.h"

using namespace std;

int main()
{

    char chrnr1[200] , chrnr2[200] ;

    NumereMari nr1(5,"79879"),nr2(2,"98"),sumanr,diferentanr,prodNr,pow,pow2,cat;

    char s[2]="3";

    cout<<nr1<<" "<<nr2<<endl;
    cout<<nr1.paritate()<<" "<<nr2.paritate()<<endl;
    cout<<nr1.palindrom()<<" "<<nr2.palindrom()<<endl;
    cout<<"suma cifre nr1="<<nr1.suma_cifrelor()<<";  suma cifre nr2="<<nr2.suma_cifrelor()<<endl;

      sumanr=nr1+nr2;
      sumanr.elimin_zero();

      diferentanr=nr1-nr2;
      diferentanr.elimin_zero();

      prodNr=nr1*nr2;

     prodNr.elimin_zero();

    cout << "suma " << sumanr;
    cout<<endl;
    cout<<"diferenta ";
    if(nr1<nr2)
        cout<<"-";
    cout<<diferentanr;
    cout<<endl;
    cout<<"produsul "<<prodNr;
    cout<<endl;
    pow=nr1.putere(s[0]-'0');
    pow.elimin_zero();
    cout<<"nr1 la puterea"<<s<<"="<<pow<<endl;

    pow2=nr2.putere(s[0]-'0');
    pow2.elimin_zero();
    cout<<"nr2 la puterea"<<s<<"="<<pow2<<endl;
    cat=nr1/nr2;
    cat.elimin_zero();
    cout<<"catul impartirii="<<cat;


    return 0;
}
