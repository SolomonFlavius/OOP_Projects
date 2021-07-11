#include <iostream>
#include <stdlib.h> // rand abs
#include <time.h> // time

const double energieDefault = 100;
const int varstaMaxima = 30;
const double energiePierdutaLaImbatranire = 7;
const double enrgiePierdutaPentruUnFiu = 57.5;

class Tabla;

class Individ
{
    ///membri privati
    int i, j; ///pozitii tabela
    char tip;///+ sau 0
    int varsta;///incepe cu 0 pana la varstaMaxima
    double energie;///energia
    unsigned char viu;///'1' ptr viu , '0' ptr mort

    ///-----metode------


    void Hraneste(Tabla &tabla);


    void Inmulteste(Tabla &tabla);


    void Ataca(Tabla &tabla);


    void Imbatraneste(Tabla &tabla);

    void Moare();

public:

    Individ(int pozI, int pozJ, char type)
    {
        i = pozI;
        j = pozJ;
        tip = type;
        varsta = 0;
        energie = energieDefault;
        viu = '1';
    }
    Individ()
    {
        i = 0;
        j = 0;
        tip = '0';
        varsta = 0;
        energie = energieDefault;
        viu = '1';
    }
    ~Individ(){}

    ///Getteri

    int GetI()
    {
        return i;
    }

    int GetJ()
    {
        return j;
    }

    char GetTip()
    {
        return tip;
    }

    int GetVarsta()
    {
        return varsta;
    }

    double GetEnergie()
    {
        return energie;
    }

    unsigned char GetViu()
    {
        return viu;
    }

    ///Setteri

    void SetI(int pozI)
    {
        i = pozI;
    }

    void SetJ(int pozJ)
    {
        j = pozJ;
    }

    void SetTip(char type)
    {
        tip = type;
    }

    void SetVarsta(int age)
    {
        varsta = age;
    }

    void SetEnergie(double energy)
    {
        energie = energy;
    }

    void SetViu(unsigned char alive)
    {
        viu = alive;
    }

    /// >>

    friend std::istream& operator>>(std::istream& in, Individ& individ)
    {
        in >> individ.i >> individ.j >> individ.tip;
        //individ.SetVarsta(0);
        individ.varsta = 0;
        individ.SetEnergie(energieDefault) ;
        individ.SetViu('1');
        return in;
    }

    /// <<

    friend std::ostream& operator<<(std::ostream& out, Individ& individ)
    {

        out << individ.i << ' ' << individ.j<<' '<<individ.tip<<' '<<individ.varsta<<' '<<individ.energie<<' '<<individ.viu;
        return out;
    }

    void Actualizare(Tabla &tabla)
    {
        Hraneste(tabla);
        Inmulteste(tabla);
        Ataca(tabla);
        Imbatraneste(tabla);
    }
    unsigned int EsteViu()
    {
        if(viu == '1')
            return 1;
        else
            return 0;
    }

};

class Tabla
{
    Individ individ[20][70];
    bool liber[20][70];
    bool fiuNou[20][70];
public:
    Tabla()
    {
        int i,j;
        for(i=0; i<20; i++)
            for(j=0; j<70; j++)
            {
                liber[i][j] = true;///liber == true   nu se afla individ pe acel loc
                fiuNou[i][j] = false;///fiuNou == true   acest individ este abia "nascut", nu se actualizeaza in aceasta tura
            }
    }

    void InitializareAleatoare()
    {
        ///maxim 10 indivizi pe tabla
        int random = rand() % 10 +1;
        int i;
        for(i = 1; i<=random; i++)
        {
            int randomTip = rand()%2 +1;/// 1 pentru + 2 pentru 0
            int randomI = rand() % 20;
            int randomJ = rand() % 70;
            liber[randomI][randomJ]=false;
            if(randomTip == 1)
                AlocareIndivid(randomI,randomJ,'+');
            else
                AlocareIndivid(randomI,randomJ,'0');
        }
    }
    void Afisare()
    {
        int i,j;
        for(i = 0; i<20; i++)
        {
            for(j=0; j<70; j++)
            {
                if(liber[i][j]==false)
                    std::cout<<individ[i][j].GetTip();
                if(liber[i][j]==true)
                    std::cout<<' ';
            }
            std:: cout<<'\n';
        }
        for(int i=0;i<70;i++)
            std::cout<<"-";///delimitare ptr table
        std::cout<<'\n';
    }
    void Actualizare(Tabla &tabla)
    {
        int i, j;
        for(i=0; i<20; i++)
            for(j=0; j<70; j++)
                if(liber[i][j]==false&&fiuNou[i][j]==false)
                    {
                        individ[i][j].Actualizare(tabla);
                    }
        for(i=0; i<20; i++)
            for(j=0; j<70; j++)
                fiuNou[i][j]=false;
    }
    bool MaiExistaIndivizi()
    {
        bool ok=false;
        int i,j;
        for(i=0; i<20; i++)
            for(j=0; j<70; j++)
                if(individ[i][j].EsteViu()==1)
                    ok=true;
        return ok;
    }
    void AlocareIndivid(int i,int j,char tip)
    {
        Individ individNou(i,j,tip); ///declaram noul individ
        individ[i][j] = individNou;  ///il atribuim in matrice
        liber[i][j] = false;         ///punem locul lui ca "ocupat"
        fiuNou[i][j] = true;         ///fiu abia pus pe tabla
    }

    void EliminareIndivid(int i,int j)
    {

        liber[i][j]=true;
    }
    Individ GetIndivid(int i ,int j)
    {
        return individ[i][j];
    }

    double GetEnergieIndivid(int i,int j)
    {
        return individ[i][j].GetEnergie();
    }

    char GetTipIndivid(int i,int j)
    {
        return individ[i][j].GetTip();
    }
    int GetAportEnergetic(int i,int j)
    {
        int aportEnergetic = 1;
        if(i>0&&liber[i-1][j]==true)
        {
            aportEnergetic++;
        }
        if(i<19&&liber[i+1][j]==true)
        {
            aportEnergetic++;
        }
        if(j>0&&liber[i][j-1]==true)
        {
            aportEnergetic++;
        }
        if(j<69&&liber[i][j+1]==true)
        {
            aportEnergetic++;
        }
        return aportEnergetic;
    }
    bool GetLiber(int i, int j)
    {
        return liber[i][j];
    }
    void ResetareTabla()
    {
        int i,j;
        for(i=0; i<20; i++)
            for(j=0; j<70; j++)
            {
                liber[i][j] = true;///liber == true   nu se afla individ pe acel loc
                fiuNou[i][j] = false;///fiuNou == true   acest individ este abia "nascut", nu se actualizeaza in aceasta tura
            }
    }
};

void Individ::Moare()
{
    viu = '0';
}

void Individ::Ataca(Tabla &tabla)
{
    if(i>0&&tabla.GetTipIndivid(i-1,j)!=tip&&energie>tabla.GetEnergieIndivid(i-1,j))
    {
        energie-=tabla.GetEnergieIndivid(i-1,j);
        tabla.GetIndivid(i-1,j).Moare();
        tabla.EliminareIndivid(i-1,j);
    }
    else if(i<19&&tabla.GetTipIndivid(i+1,j)!=tip&&energie>tabla.GetEnergieIndivid(i+1,j))
    {
        energie-=tabla.GetEnergieIndivid(i+1,j);
        tabla.GetIndivid(i+1,j).Moare();
        tabla.EliminareIndivid(i+1,j);
    }
    else if(j>0&&tabla.GetTipIndivid(i,j-1)!=tip&&energie>tabla.GetEnergieIndivid(i,j-1))
    {
        energie-=tabla.GetEnergieIndivid(i,j-1);
        tabla.GetIndivid(i,j-1).Moare();
        tabla.EliminareIndivid(i,j-1);
    }
    else if(j<69&&tabla.GetTipIndivid(i,j+1)!=tip&&energie>tabla.GetEnergieIndivid(i,j+1))
    {
        energie-=tabla.GetEnergieIndivid(i,j+1);
        tabla.GetIndivid(i,j+1).Moare();
        tabla.EliminareIndivid(i,j+1);
    }

}

void Individ::Hraneste(Tabla &tabla)
{
    int aportEnergeticTotal=0;
    if(i>0&&tabla.GetLiber(i-1,j)==true)
    {
        aportEnergeticTotal+=tabla.GetAportEnergetic(i-1,j);
    }
    if(i<19&&tabla.GetLiber(i+1,j)==true)
    {
        aportEnergeticTotal+=tabla.GetAportEnergetic(i+1,j);
    }
    if(j>0&&tabla.GetLiber(i,j-1)==true)
    {
        aportEnergeticTotal+=tabla.GetAportEnergetic(i,j-1);
    }
    if(j<69&&tabla.GetLiber(i,j+1)==true)
    {
        aportEnergeticTotal+=tabla.GetAportEnergetic(i,j+1);
    }
    energie+=0.5*aportEnergeticTotal+(20-0.1*(abs(varstaMaxima/2-varsta)));
}

void Individ::Inmulteste(Tabla &tabla)///formula nr fii: (120+varstaMaxima/2-varsta)/100
{
    int numarFii = (120+varstaMaxima/2-varsta)/100;
    if(numarFii>4)
        numarFii = 4;
    if(i>0&&tabla.GetLiber(i-1,j)==true&&energie>enrgiePierdutaPentruUnFiu&&numarFii>0)
    {
        energie-=enrgiePierdutaPentruUnFiu;
        tabla.AlocareIndivid(i-1,j,tip);
        numarFii--;
    }
    if(i<19&&tabla.GetLiber(i+1,j)==true&&energie>enrgiePierdutaPentruUnFiu&&numarFii>0)
    {
        energie-=enrgiePierdutaPentruUnFiu;
        tabla.AlocareIndivid(i+1,j,tip);
        numarFii--;
    }
    if(j>0&&tabla.GetLiber(i,j-1)==true&&energie>enrgiePierdutaPentruUnFiu&&numarFii>0)
    {
        energie-=enrgiePierdutaPentruUnFiu;
        tabla.AlocareIndivid(i,j-1,tip);
        numarFii--;
    }
    if(j<69&&tabla.GetLiber(i,j+1)==true&&energie>enrgiePierdutaPentruUnFiu&&numarFii>0)
    {
        energie-=enrgiePierdutaPentruUnFiu;
        tabla.AlocareIndivid(i,j+1,tip);
        numarFii--;
    }
}
void Individ::Imbatraneste(Tabla &tabla)
{
    varsta++;
    energie-=energiePierdutaLaImbatranire;
    if(varsta>=varstaMaxima || energie <= 0)
        {
            Moare();
            tabla.EliminareIndivid(i,j);
        }
}

void MeniuInteractiv(Tabla &tabla)
{
    std::cout<<"Introdu 1 pentru random, 2 pentru tabla initializata, 0 pentru a iesi din program:\n";
    tabla.ResetareTabla();
    int n;
    std::cin>>n;
    if(n==1)
    {
        int pasi;
        std::cout<<"Cati pasi doresti?";
        std::cin>>pasi;
        tabla.InitializareAleatoare();
        tabla.Afisare();
        while(pasi>1)
        {
            tabla.Actualizare(tabla);
            if(tabla.MaiExistaIndivizi())
                tabla.Afisare();
            else
                pasi=0;
            pasi--;
        }
        MeniuInteractiv(tabla);
    }
    else if(n==0)
        return;
    else if(n==2)
    {
        int pasi;
        std::cout<<"Cati pasi doresti?";
        std::cin>>pasi;
        std::cout<<"Cati indivizi doresti?\n";
        int numarIndivizi;
        std::cin>>numarIndivizi;
        int i;
        for(i=1;i<=numarIndivizi;i++)
        {
            Individ individ;
            std::cin>>individ;
            tabla.AlocareIndivid(individ.GetI(),individ.GetJ(),individ.GetTip());
        }
        tabla.Afisare();
        while(pasi>1)
        {
            tabla.Actualizare(tabla);
            if(tabla.MaiExistaIndivizi())
                tabla.Afisare();
            else
                pasi=0;
            pasi--;
        }
        MeniuInteractiv(tabla);
    }
}

int main()
{
    srand (time(NULL));
    Tabla tabla;
    MeniuInteractiv(tabla);
    return 0;
}
