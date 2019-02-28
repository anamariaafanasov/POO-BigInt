#include "NumereMari.h"
#include <iostream>
using namespace std;
NumereMari::NumereMari()
{//constructor

    max_size = SIZE;//max_size e un nr maxim de caractere ce il poate avea o variabila de tipul NumereMari
    p = new int[max_size];

    for(int i = 0; i < max_size; ++i) {
        p[i] = 0;
    }
}


NumereMari::NumereMari(int n, char *numar)
{//constructor cu parametri ce poate fi folosit cu siruri de caractere
    p = new int[n];
    this->n = n;
    max_size = n;

    for (int i = 0; i < n; i++)
    {
        p[i] = numar[i]-'0';
    }
}
NumereMari::NumereMari(const NumereMari& nr)
{//constructor copiere
    n = nr.n;
    p = new int[nr.n];
    for (int i = 0; i < this->n; i++)
        this->p[i] = nr.p[i];
}

NumereMari::~NumereMari()
{//destructor
    delete[] p;
}


void NumereMari::elimin_zero()
   {//aceasta functie elimina zero-urile din fata unui numar; ex: pentru suma si diferenta e posibil sa se aloce mai mult spatiu decat e necesar,spatii ce vor fi initializate cu 0
    int gasit_cifra_nenula;

   if(p[0]==0)
    gasit_cifra_nenula=0;
   else
    gasit_cifra_nenula=1;

   while(gasit_cifra_nenula==0 and n>1)

       {
               for(int j=0;j<n-1;j++)
                    p[j]=p[j+1];
               n--;

               if(p[0]!=0)
                   gasit_cifra_nenula=1;
       }
   }



NumereMari NumereMari::operator+(const NumereMari &num)
            {//supraincarcarea operatorului +
            int transport = 0, s, size1, size2, sizes;//size1=size-ul primului numar, size2 -al celui de al doilea, iar sizes va fi size-ul sumei
            NumereMari suma;

            size1 = this->n;
            size2 = num.n;
            //size-ul sumei va fi initializat cu size-ul maxim dintre size1 si size2
            if (size1 >= size2)
                sizes = size1 + 1;

            else
                sizes = size2 + 1;

            suma.p = new int[sizes];
            suma.n = sizes;

            for (int i = 0; i < sizes; i++)//suma a fost initializata cu 0
                suma.p[i] = 0;
            //se vor parcuge cele doua numere,memorate ca vectori,de la pozitia finala spre cea initiala
            if(size1>=size2)//se alege numarul de dimensiune mai mica
                {
                    while(size2>0)
                        {
                          s=this->p[--size1]+num.p[--size2]+transport;//se face suma dintre cifrele unitatilor,zecilor,sutelor,etc.cat timp avem elemente in al doilea vector(num.p);la aceasta suma se adauga si transportul


                        //se adauga ultima cifra a variabilei s in vadiabila suma de tip NumereMari,iar daca s>10,se va duce o unitate mai departe(transport=1)
                        if(s<10)
                            {suma.p[--sizes]=s;

                            transport=0;
                            }
                        else
                            {suma.p[--sizes]=s%10;
                            transport=1;
                            }


                        }

                    while(size1>0)//cat timp nu am parcurs toate cifrele primului numar
                        {
                        s=this->p[--size1]+transport;//retinem in s suma dintre cifra de pe pozitia curenta+transportul
                        //urmand sa actualizam variabila suma de tip NumereMari
                        if(s<10)
                            {suma.p[--sizes]=s;
                            transport=0;
                            }
                        else
                            {
                            suma.p[--sizes]=s%10;
                            transport=1;
                            }
                        }
                if(transport==1)//daca la final transportul e 1, aceata cifra trebuie adaugata la inceputul sumei
                    suma.p[--sizes]=1;


    }
            else//analog pentru cazul in care primul numar citit are dimensiunea(size-ul) mai mica decat al doilea
                {
                while(size1>0)
                    {
                    s=this->p[--size1]+num.p[--size2]+transport;


                    if(s<10)
                        {suma.p[--sizes]=s;
                        transport=0;
                        }
                    else
                        {suma.p[--sizes]=s%10;
                        transport=1;
                        }
                    }
                while(size2>0)
                    {
                     s=num.p[--size2]+transport;
                     if(s<10)
                        {suma.p[--sizes]=s;
                        transport=0;
                        }
                    else
                        {
                        suma.p[--sizes]=s%10;
                        transport=1;
                        }
                    }
            if(transport==1)
            suma.p[--sizes]=1;
                }
    return suma;
        }


NumereMari NumereMari::operator-(const NumereMari &num)
 {//supraincarcarea operatorului -
    int  size1, size2, sizedif,cpysize1,cpysize2;
    NumereMari dif,cpynr1,cpynr2;//creem copii ale numerelor ale caror diferenta vrem sa o calculam,diferenta ce va fi returnata prin intermediul variabilei dif

    size1 = this->n;
    size2 = num.n;

     if (size1 >= size2)
        sizedif = size1;

     else
        sizedif = size2;

    dif.p = new int[sizedif];
    dif.n = sizedif;

    for (int i = 0; i < sizedif; i++)
        dif.p[i] = 0;
    //am initializat diferenta cu 0

    for(int i=0;i<size1;i++)
            cpynr1.p[i]=p[i];
    //am copiat primul nr
     for(int i=0;i<size2;i++)
            cpynr2.p[i]=num.p[i];
    //am copiat al doilea nr

    if(size2<=size1)//size1=copie a dimensiunii primului numar,iar size2= copie a dimensiunii celui de al doilea numar
    {
        while(size2>0)
                {//facem diferenta,incepand de la sfarsitul numerelor
                    if(cpynr1.p[--size1]>=cpynr2.p[--size2])//daca diferenta este >=0, o retinem in dif
                            {dif.p[--sizedif]=cpynr1.p[size1]-cpynr2.p[size2];
                            }
                    else//daca nu, imprumutam de la ordinul mai mare
                        {
                        dif.p[--sizedif]=cpynr1.p[size1]+10-cpynr2.p[size2];
                        cpysize1=size1 - 1;
                        while(cpynr1.p[cpysize1]==0)//cat timp ordinul de la care am imprumutat era 0
                                cpynr1.p[cpysize1--]=9;//aceasta devine 9
                        cpynr1.p[cpysize1]--;//scadem prima cifra nenula pe care o gasim mai la stanga celei pentru care am facut imprumut
                        }

                }

        while(size1>0)//cat timp au ramas cifre neparcurse pentru primul numar,le copiem in dif, de la pozitia la care am ramas in dif inspre pozitia initiala
            dif.p[--sizedif]=cpynr1.p[--size1];
    }
    else// daca primul numar introdus este mai mic decat al doilea, calculam diferenta dintre al doilea si primul, aceasta diferenta fiind afisata in final cu minus
       {//diferenta se va calcula in mod analog cu cazul in care primul numar era mai mare decat al doilea
         while(size1>0)
                {
                    if(cpynr2.p[--size2]>=cpynr1.p[--size1])
                            {dif.p[--sizedif]=cpynr2.p[size2]-(cpynr1.p[size1]);
                            }
                    else
                        {
                        dif.p[--sizedif]=cpynr2.p[size2]+10-(cpynr1.p[size1]);
                        cpysize2=size2 - 1;
                        while(cpynr2.p[cpysize2]==0)
                                cpynr2.p[cpysize2--]=9;
                        cpynr2.p[cpysize2]--;
                        }

                }
                while(size2>0)
                     dif.p[--sizedif]=cpynr2.p[--size2];
      }

    return dif;

 }

NumereMari& NumereMari::operator=(const NumereMari &val)
{//supraincarcarea operatorului =
    if(this==&val)
        return *this;

    n=val.n;
    p=new int[val.n];

    for(int i=0;i<n;i++)
        p[i]=val.p[i];

    return *this;

}

NumereMari NumereMari:: operator*(const NumereMari& num)

{    //supraincarcarea operatorului *
     int size1,size2,size_result,size_temp,cpysizetemp,transport=0,prod,contor=1,cpycontor;

    NumereMari result,temp;//in result vom obtine rezultatul final al inmultirii, iar in temp va fi produsul dintre una din cifrele celui de-al doilea numar si primul numar

    size1=this->n;
    size2=num.n;

    size_result=size1+size2+1;
    result.n=size_result;
    result.p=new int[size_result];

    for(int i=0;i<size_result;i++)
        result.p[i]=0;
    //am initializat result cu 0

    size_temp=size1+size2+1;

    temp.n=size_temp;
    temp.p=new int[size_temp];

        for(int j=size2-1;j>=0;j--)//parcurgere de la coada a celui de al doilea numar
            {
                for(int a=0;a<size_temp;a++)
                    temp.p[a]=0;
                    //de fiecare data cand am terminat de inmultit o cifra a celui de al doilea numar cu nr1, se reinitializeaza temp cu 0
                cpycontor=contor;//contorul,respectiv cpycontor numara la a cata cifra de la coada ne aflam in parcurgerea celui de-al doilea numar,urmand sa fie lasate atatea pozitii pe care va fi inserata valoarea 0 in vectorul temp,la final
                cpysizetemp=size_temp;

                while(cpycontor!=1)
                    {
                    cpysizetemp--;
                    cpycontor=cpycontor/10;
                    }//aici se "adauga" numarul de 0-uri
                for(int i=size1-1;i>=0;i--)//parcurgere de la coada a primului numar
                    {
                     prod=num.p[j]*(this->p[i])+transport;//calculam produsul cifrelor la care adunam transportul
                     temp.p[--cpysizetemp]=prod%10;//retinem ultima cifra a produsului
                     transport=prod/10;//actualizam transportul
                    }
                if(transport!=0)
                    {temp.p[--cpysizetemp]=transport;
                     transport=0;
                    }
                 //in cazul in care la final transportul de diferit de 0, il lipim la inceputul lui temp
                contor=contor*10;//contorul se pregateste pentru creerea urmatorului temp
                result=result+temp;//se actualizeaza result-ul
            }
        return result;




}
int NumereMari::operator<(const NumereMari &num)
            {//supraincarcarea operatorului <

                if(this->n<num.n)
                    return 1;
                else if(num.n<this->n)
                    return 0;
                else
                { for(int i=0;i<n;i++)
                        if(p[i]<num.p[i])
                            return 1;
                        else if(p[i]>num.p[i])
                            return 0;
                        return 0;

                }
            }
NumereMari NumereMari::operator/(const NumereMari &num)
            {//supraincarcarea operatorului /
                NumereMari deimpartit,impartitor,cat,numar_de_adunat;//numarul de adunat va fi initializat cu 1
                //vom calcula impartirea prin intermediul scaderilor repetate, asa ca deimpartitul si impartitorul vor avea rol de dezcazut, respectiv scazator;la fiecare scadere efectuata,catul va creste cu 1

                deimpartit.n=n;
                deimpartit.p=new int[n];
                for(int i=0;i<n;i++)
                    deimpartit.p[i]=this->p[i];


                cat.n=n;
                for(int i=0;i<n;i++)
                    cat.p[i]=0;//initializare cat

                numar_de_adunat.n=n;
                impartitor.n=num.n;
                impartitor.p=new int[impartitor.n];

                for(int i=0;i<impartitor.n;i++)
                    impartitor.p[i]=num.p[i];

                for(int i=0;i<n;i++)
                    {
                    deimpartit.p[i]=this->p[i];
                    cat.p[i]=0;
                    }
                numar_de_adunat.p[n-1]=1;
                //numarul de adunat va fi tot timpul 1
                if(deimpartit<impartitor)
                    return cat;

              while(impartitor<deimpartit)
                    {//impartirea va fi calculata prin scaderi repetate
                        deimpartit=deimpartit-impartitor;
                        cat=cat+numar_de_adunat;
                        while(deimpartit.p[0]==0)//se elimina 0-urile de la inceputul deimpartitului,pentru ca operatorul < sa functioneze
                        {

                         for(int i=0;i<deimpartit.n-1;i++)
                                deimpartit.p[i]=deimpartit.p[i+1];
                         deimpartit.n=deimpartit.n-1;//se actualizeaza lungimea deimpartitului
                        }
                    }
                return cat;
            }

std::ostream &operator<<(std::ostream &out, const NumereMari &val)
{//supraincarcare operator <<
    for (int i = 0; i < val.n; i++)
        out << val.p[i];
    return out;
}
std::istream &operator>>(std::istream &in, const NumereMari &val)
    {//supraincarcare operator >>
        for(int i=0;i<val.n;i++)
            in>> val.p[i];
        return in;
    }

char* NumereMari::paritate()
    {// verificare in functie de ultima cifra
    if(this->p[n-1]%2==0)
        return "par";
    else
        return "impar";
    }




char* NumereMari::palindrom()
    {
    //se porneste o parcurgere a numarului, din ambele parti ,in acelasi timp pana la mijloc. se verifica daca cifra din stanga este egala cu cea din dreapta
    int poz_initiala=0, poz_finala=this->n/2;
      while(p[poz_initiala]==p[poz_finala] && poz_initiala<=n/2 && poz_finala<n)
      {
          poz_finala++;
          poz_initiala++;
      }
      if(poz_initiala==n/2 && poz_finala==n)//daca s-a ajuns cu indicii la mijlocul numarului,sau daca cel care a pornit din stanga a ajuns in jumatatea dreapta, iar cel din dreapta a ajuns in cea stanga,inseamna ca numarul e palindrom
        return "palindrom";
      else
        return "nepalindrom";


    }


int NumereMari::suma_cifrelor()
{//se calculeaza suma cifrelor in variabila sumaC
    int sumaC=0;
    for(int i=0;i<n;i++)
        sumaC=sumaC+p[i];
    return sumaC;
}

NumereMari NumereMari::putere(int exp)
{
  int size_result;
  NumereMari result,nr;//in result vom obtine rezultatul final, iar in nr vom avea o copie a numarului a carui putere vrem sa o calculam

  result.n=this->n;
  size_result=this->n;

  result.p=new int[size_result];

  if(exp==0)//daca exponentul e 0, valoarea returnata va fi 1
  {

   for(int i=0;i<size_result-1;i++)
        result.p[i]=0;
   result.p[size_result-1]=1;
   return result;
  }

  for(int i=0;i<size_result;i++)
    result.p[i]=p[i];
  //result e initializat cu numarul pe care vrem sa il ridicam la putere
    nr=result;
    exp--;//scadem exp cu 1
  //calculam nr la puterea exp, folosindu-ne de inmultire
  while(exp)
  {
   result=result*nr;
   exp--;

  }

  return result;
}

