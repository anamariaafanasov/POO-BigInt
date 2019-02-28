#ifndef NUMEREMARI_H
#define NUMEREMARI_H
#define SIZE 1000;
#include <ostream>
#include <istream>

class NumereMari
{
    int *p;
    int n, max_size;

  public:
    NumereMari();
    NumereMari(int n, char *numar);
    NumereMari(const NumereMari &arr);
    ~NumereMari();

    void elimin_zero();
    char* paritate();
    char* palindrom();
    int suma_cifrelor();
    NumereMari putere(int exp);


    int operator<(const NumereMari &num);
    NumereMari operator+(const NumereMari &num);
    NumereMari operator-(const NumereMari &num);
    NumereMari& operator=(const NumereMari&num);
    NumereMari operator*(const NumereMari &num);
    NumereMari operator/(const NumereMari &num);
    friend std::ostream& operator<<(std::ostream &out,const NumereMari &val);
    friend std::istream& operator>>(std::istream &in,const NumereMari&val);
};

#endif // NUMEREMARI_H
