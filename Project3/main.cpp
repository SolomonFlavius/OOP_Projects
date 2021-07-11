#include <iostream>
#include <fstream>
#include <set>
#include <utility>
#include <string>
std::ifstream fisierDate("dateIntrare.in");
std::ofstream fisierIesire("date.out");
class Automobil
{
private:
    bool sh;
    float lungime;
    int locuri;
    float capacitateMotor;
    int caiPutere;
    bool esteDiesel;// diesel = true   benzina = false
    std::string nume;
    int pret;
public:
    //constructori
    Automobil()
    {
    }
    //destructor
    ~Automobil()
    {
    }
    // operatorul =
    Automobil& operator=(const Automobil& automobilDeAtribuit)
    {
        this->sh = automobilDeAtribuit.sh;
        this->lungime = automobilDeAtribuit.lungime;
        this->locuri = automobilDeAtribuit.locuri;
        this->capacitateMotor = automobilDeAtribuit.capacitateMotor;
        this->caiPutere = automobilDeAtribuit.caiPutere;
        this->esteDiesel = automobilDeAtribuit.esteDiesel;
        this->nume = automobilDeAtribuit.nume;
        return *this;
    }
    //setteri
    void SetSH(bool sh)
    {
        this->sh = sh;
    }
    void SetLungime(float lungime)
    {
        this->lungime = lungime;
    }
    void SetLocuri(int locuri)
    {
        this->locuri = locuri;
    }
    void SetCapacitateMotor(float capacitateMotor)
    {
        this->capacitateMotor = capacitateMotor;
    }
    void SetCaiPutere(int caiPutere)
    {
        this->caiPutere = caiPutere;
    }
    void SetEsteDiesel(bool esteDiesel)
    {
        this->esteDiesel = esteDiesel;
    }
    void SetNume(std::string nume)
    {
        this->nume = nume;
    }
    void SetPret(int pret)
    {
        this->pret = pret;
    }
    //getteri
    bool GetSH()
    {
        return sh;
    }
    int GetPret()
    {
        return pret;
    }
    float GetLungime()
    {
        return lungime;
    }
    int GetLocuri()
    {
        return locuri;
    }
    float GetCapacitateMotor()
    {
        return capacitateMotor;
    }
    int GetCaiPutere()
    {
        return caiPutere;
    }
    bool GetEsteDiesel()
    {
        return esteDiesel;
    }
    std::string GetNume()
    {
        return nume;
    }
    //functii virtaule
    virtual void AfisareAutomobil(){}
    virtual void CitireAutomobil(){}
    //functii prieten
    //  citire
    friend std::istream& operator>>(std::istream& in, Automobil& automobil)
    {
        in>>automobil.nume>>automobil.lungime>>automobil.locuri>>automobil.capacitateMotor>>automobil.caiPutere;
        int ok;
        in>>ok>>automobil.pret;
        if(ok == 0)
            automobil.esteDiesel = false;
        else
            automobil.esteDiesel = true;
        return in;
    }
    //   afisare
    friend std::ostream& operator<<(std::ostream& out, Automobil& automobil)
    {
        out<<"Nume: "<<automobil.nume<<'\n';
        out<<"Capacitate Motor: "<<automobil.capacitateMotor<<'\n';
        out<<"Cai Putere: "<<automobil.caiPutere<<'\n';
        if(automobil.esteDiesel)
        out<<"Diesel\n";
        else
        out<<"Benzina\n";
        out<<"Pret: "<<automobil.pret<<'\n';
        return out;
    }

};
class Mini : public Automobil
{
public:
    Mini()
    {
        SetSH(false);
    }
    ~Mini()
    {

    }
    Mini& operator=(Mini& automobilDeAtribuit)
    {
        SetSH(automobilDeAtribuit.GetSH());
        SetLungime(automobilDeAtribuit.GetLungime());
        SetLocuri(automobilDeAtribuit.GetLocuri());
        SetCapacitateMotor(automobilDeAtribuit.GetCapacitateMotor());
        SetCaiPutere(automobilDeAtribuit.GetCaiPutere());
        SetEsteDiesel(automobilDeAtribuit.GetEsteDiesel());
        SetNume(automobilDeAtribuit.GetNume());
        return *this;
    }
    friend std::istream& operator>>(std::istream& in, Mini& automobil)
    {
        std::string NewNume;
        float NewLungime;
        int NewLocuri;
        float NewCapacitateMotor;
        int NewCaiPutere;
        int NewPret;
        in>>NewNume>>NewLungime>>NewLocuri>>NewCapacitateMotor>>NewCaiPutere;
        int ok;
        in>>ok>>NewPret;
        if(ok == 0)
            automobil.SetEsteDiesel(false);
        else
            automobil.SetEsteDiesel(true);
        automobil.SetNume(NewNume);
        automobil.SetLungime(NewLungime);
        automobil.SetLocuri(NewLocuri);
        automobil.SetCapacitateMotor(NewCapacitateMotor);
        automobil.SetCaiPutere(NewCaiPutere);
        automobil.SetPret(NewPret);
        return in;
    }
    //   afisare
    friend std::ostream& operator<<(std::ostream& out, Mini& automobil)
    {
        out<<"Nume: "<<automobil.GetNume()<<'\n';
        out<<"Capacitate Motor: "<<automobil.GetCapacitateMotor()<<'\n';
        out<<"Cai Putere: "<<automobil.GetCaiPutere()<<'\n';
        if(automobil.GetEsteDiesel())
        out<<"Diesel\n";
        else
        out<<"Benzina\n";
        out<<"Pret: "<<automobil.GetPret()<<'\n';
        return out;
    }
    void CitireAutomobil()
    {
        Automobil automobil;
        fisierDate>>automobil;
        SetLungime(automobil.GetLungime());
        SetLocuri(automobil.GetLocuri());
        SetCapacitateMotor(automobil.GetCapacitateMotor());
        SetCaiPutere(automobil.GetCaiPutere());
        SetEsteDiesel(automobil.GetEsteDiesel());
        SetNume(automobil.GetNume());
        SetPret(automobil.GetPret());
    }
    void AfisareAutomobil()
    {
        std::cout<<*this;
        std::cout<<"Masina de tip MINI\n";
    }
};
class Mica : public Automobil
{
    public:
    Mica()
    {
        SetSH(false);
    }
    ~Mica()
    {

    }
    Mica& operator=(Mica& automobilDeAtribuit)
    {
        SetSH(automobilDeAtribuit.GetSH());
        SetLungime(automobilDeAtribuit.GetLungime());
        SetLocuri(automobilDeAtribuit.GetLocuri());
        SetCapacitateMotor(automobilDeAtribuit.GetCapacitateMotor());
        SetCaiPutere(automobilDeAtribuit.GetCaiPutere());
        SetEsteDiesel(automobilDeAtribuit.GetEsteDiesel());
        SetNume(automobilDeAtribuit.GetNume());
        return *this;
    }
    friend std::istream& operator>>(std::istream& in, Mica& automobil)
    {
        std::string NewNume;
        float NewLungime;
        int NewLocuri;
        float NewCapacitateMotor;
        int NewCaiPutere;
        int NewPret;
        in>>NewNume>>NewLungime>>NewLocuri>>NewCapacitateMotor>>NewCaiPutere;
        int ok;
        in>>ok>>NewPret;
        if(ok == 0)
            automobil.SetEsteDiesel(false);
        else
            automobil.SetEsteDiesel(true);
        automobil.SetNume(NewNume);
        automobil.SetLungime(NewLungime);
        automobil.SetLocuri(NewLocuri);
        automobil.SetCapacitateMotor(NewCapacitateMotor);
        automobil.SetCaiPutere(NewCaiPutere);
        automobil.SetPret(NewPret);
        return in;
    }
    //   afisare
    friend std::ostream& operator<<(std::ostream& out, Mica& automobil)
    {
        out<<"Nume: "<<automobil.GetNume()<<'\n';
        out<<"Capacitate Motor: "<<automobil.GetCapacitateMotor()<<'\n';
        out<<"Cai Putere: "<<automobil.GetCaiPutere()<<'\n';
        if(automobil.GetEsteDiesel())
        out<<"Diesel\n";
        else
        out<<"Benzina\n";
        out<<"Pret: "<<automobil.GetPret()<<'\n';
        return out;
    }
    void CitireAutomobil()
    {
        Automobil automobil;
        fisierDate>>automobil;
        SetLungime(automobil.GetLungime());
        SetLocuri(automobil.GetLocuri());
        SetCapacitateMotor(automobil.GetCapacitateMotor());
        SetCaiPutere(automobil.GetCaiPutere());
        SetEsteDiesel(automobil.GetEsteDiesel());
        SetNume(automobil.GetNume());
        SetPret(automobil.GetPret());
    }
    void AfisareAutomobil()
    {
        fisierIesire<<*this;
        fisierIesire<<"Masina de tip MICA\n";
    }
};
class Compacta : public Automobil
{
private:
    char* model;
public:
    Compacta()
    {
        model = new char[50];
        SetSH(false);
    }
    ~Compacta()
    {
        delete model;
    }
    Compacta& operator=(Compacta& automobilDeAtribuit)
    {
        SetSH(automobilDeAtribuit.GetSH());
        SetLungime(automobilDeAtribuit.GetLungime());
        SetLocuri(automobilDeAtribuit.GetLocuri());
        SetCapacitateMotor(automobilDeAtribuit.GetCapacitateMotor());
        SetCaiPutere(automobilDeAtribuit.GetCaiPutere());
        SetEsteDiesel(automobilDeAtribuit.GetEsteDiesel());
        SetNume(automobilDeAtribuit.GetNume());
        return *this;
    }
    friend std::istream& operator>>(std::istream& in, Compacta& automobil)
    {
        std::string NewNume;
        float NewLungime;
        int NewLocuri;
        float NewCapacitateMotor;
        int NewCaiPutere;
        int NewPret;
        in>>NewNume>>NewLungime>>NewLocuri>>NewCapacitateMotor>>NewCaiPutere;
        int ok;
        in>>ok>>NewPret;
        if(ok == 0)
            automobil.SetEsteDiesel(false);
        else
            automobil.SetEsteDiesel(true);
        automobil.SetNume(NewNume);
        automobil.SetLungime(NewLungime);
        automobil.SetLocuri(NewLocuri);
        automobil.SetCapacitateMotor(NewCapacitateMotor);
        automobil.SetCaiPutere(NewCaiPutere);
        automobil.SetPret(NewPret);
        return in;
    }
    //   afisare
    friend std::ostream& operator<<(std::ostream& out, Compacta& automobil)
    {
        out<<"Nume: "<<automobil.GetNume()<<'\n';
        out<<"Capacitate Motor: "<<automobil.GetCapacitateMotor()<<'\n';
        out<<"Cai Putere: "<<automobil.GetCaiPutere()<<'\n';
        if(automobil.GetEsteDiesel())
        out<<"Diesel\n";
        else
        out<<"Benzina\n";
        out<<"Pret: "<<automobil.GetPret()<<'\n';
        return out;
    }
    void CitireAutomobil()
    {
        Automobil automobil;
        fisierDate>>automobil;
        SetLungime(automobil.GetLungime());
        SetLocuri(automobil.GetLocuri());
        SetCapacitateMotor(automobil.GetCapacitateMotor());
        SetCaiPutere(automobil.GetCaiPutere());
        SetEsteDiesel(automobil.GetEsteDiesel());
        SetNume(automobil.GetNume());
        SetPret(automobil.GetPret());
        fisierDate>>model;
    }
    void AfisareAutomobil()
    {
        std::cout<<*this;
        std::cout<<"Masina de tip "<<model<<'\n';
    }
};
class Monovolum : public Automobil
{
    int anFabricatie;
    public:
    Monovolum()
    {
        if(this->GetSH() == true)
        {
            this->SetPret(this->GetPret()-this->GetPret()*(2021-anFabricatie)/10);
        }
    }
    ~Monovolum()
    {

    }
    Monovolum& operator=(Monovolum& automobilDeAtribuit)
    {
        SetSH(automobilDeAtribuit.GetSH());
        SetLungime(automobilDeAtribuit.GetLungime());
        SetLocuri(automobilDeAtribuit.GetLocuri());
        SetCapacitateMotor(automobilDeAtribuit.GetCapacitateMotor());
        SetCaiPutere(automobilDeAtribuit.GetCaiPutere());
        SetEsteDiesel(automobilDeAtribuit.GetEsteDiesel());
        SetNume(automobilDeAtribuit.GetNume());
        return *this;
    }
    friend std::istream& operator>>(std::istream& in, Monovolum& automobil)
    {
        std::string NewNume;
        float NewLungime;
        int NewLocuri;
        float NewCapacitateMotor;
        int NewCaiPutere;
        int NewPret;
        in>>NewNume>>NewLungime>>NewLocuri>>NewCapacitateMotor>>NewCaiPutere;
        int ok;
        in>>ok>>NewPret;
        if(ok == 0)
            automobil.SetEsteDiesel(false);
        else
            automobil.SetEsteDiesel(true);
        automobil.SetNume(NewNume);
        automobil.SetLungime(NewLungime);
        automobil.SetLocuri(NewLocuri);
        automobil.SetCapacitateMotor(NewCapacitateMotor);
        automobil.SetCaiPutere(NewCaiPutere);
        automobil.SetPret(NewPret);
        return in;
    }
    //   afisare
    friend std::ostream& operator<<(std::ostream& out, Monovolum& automobil)
    {
        out<<"Nume: "<<automobil.GetNume()<<'\n';
        out<<"Capacitate Motor: "<<automobil.GetCapacitateMotor()<<'\n';
        out<<"Cai Putere: "<<automobil.GetCaiPutere()<<'\n';
        if(automobil.GetEsteDiesel())
        out<<"Diesel\n";
        else
        out<<"Benzina\n";
        out<<"Pret: "<<automobil.GetPret()<<'\n';
        return out;
    }
    void CitireAutomobil()
    {
        Automobil automobil;
        fisierDate>>automobil;
        SetLungime(automobil.GetLungime());
        SetLocuri(automobil.GetLocuri());
        SetCapacitateMotor(automobil.GetCapacitateMotor());
        SetCaiPutere(automobil.GetCaiPutere());
        SetEsteDiesel(automobil.GetEsteDiesel());
        SetNume(automobil.GetNume());
        SetPret(automobil.GetPret());
        int sh;
        fisierDate>>sh;
        if(sh == 0)
        SetSH(false);
        else
        {SetSH(true);
        fisierDate>>anFabricatie;}
    }
    void AfisareAutomobil()
    {
        std::cout<<*this;
        if(this->GetSH() == true)
            std::cout<<"Stare masina: SH\n";
        else
            std::cout<<"Stare masina: NOUA\n";
        std::cout<<"Masina de tip MONOVOLUM\n";
    }
};

class ObjectTansformator
{
public:
    Mini CreazaMini(Automobil& automobil)
    {
        Mini mini;
        mini.SetLungime(automobil.GetLungime());
        mini.SetLocuri(automobil.GetLocuri());
        mini.SetCapacitateMotor(automobil.GetCapacitateMotor());
        mini.SetCaiPutere(automobil.GetCaiPutere());
        mini.SetEsteDiesel(automobil.GetEsteDiesel());
        mini.SetNume(automobil.GetNume());
        mini.SetPret(automobil.GetPret());
        return mini;
    }
    Mica CreazaMica(Automobil& automobil)
    {
        Mica mica;
        mica.SetLungime(automobil.GetLungime());
        mica.SetLocuri(automobil.GetLocuri());
        mica.SetCapacitateMotor(automobil.GetCapacitateMotor());
        mica.SetCaiPutere(automobil.GetCaiPutere());
        mica.SetEsteDiesel(automobil.GetEsteDiesel());
        mica.SetNume(automobil.GetNume());
        mica.SetPret(automobil.GetPret());
        return mica;
    }
    Compacta CreazaCompacta(Automobil& automobil)
    {
        Compacta compacta;
        compacta.SetLungime(automobil.GetLungime());
        compacta.SetLocuri(automobil.GetLocuri());
        compacta.SetCapacitateMotor(automobil.GetCapacitateMotor());
        compacta.SetCaiPutere(automobil.GetCaiPutere());
        compacta.SetEsteDiesel(automobil.GetEsteDiesel());
        compacta.SetNume(automobil.GetNume());
        compacta.SetPret(automobil.GetPret());
        return compacta;
    }
    Monovolum CreazaMonovolum(Automobil& automobil)
    {
        Monovolum monovolum;
        monovolum.SetLungime(automobil.GetLungime());
        monovolum.SetLocuri(automobil.GetLocuri());
        monovolum.SetCapacitateMotor(automobil.GetCapacitateMotor());
        monovolum.SetCaiPutere(automobil.GetCaiPutere());
        monovolum.SetEsteDiesel(automobil.GetEsteDiesel());
        monovolum.SetNume(automobil.GetNume());
        monovolum.SetPret(automobil.GetPret());
        return monovolum;
    }
};
class Parc
{
    ObjectTansformator objtr;
    std::set<std::pair<Automobil*, bool>> masiniStoc;
    std::set<std::pair<Automobil*, bool>> masiniVandute;
    Automobil masiniStoc2[100];
    Automobil masiniVandute2[100];
    int tipMasini[100];
    int tipMasini2[100];
    int numarMasiniStoc,numarMasiniVandute;
public:
    Parc()
    {
        numarMasiniStoc = 0;
        numarMasiniVandute = 0;
        int tipMasina;
        while(fisierDate>>tipMasina)
        {
            if(tipMasina == 0)
            {
                Automobil* pointer;
                Mini mini;
                mini.CitireAutomobil();
                pointer = &mini;
                masiniStoc.insert(std::make_pair(pointer, true));
                masiniStoc2[numarMasiniStoc] = *pointer;
                tipMasini[numarMasiniStoc] = 0;
                numarMasiniStoc++;
            }
            if(tipMasina == 1)
            {
                Automobil* pointer;
                Mica mica;
                mica.CitireAutomobil();
                pointer = &mica;
                masiniStoc.insert(std::make_pair(pointer, true));
                masiniStoc2[numarMasiniStoc] = *pointer;
                tipMasini[numarMasiniStoc] = 1;
                numarMasiniStoc++;
            }
            if(tipMasina == 2)
            {
                Automobil* pointer;
                Compacta compacta;
                compacta.CitireAutomobil();
                pointer = &compacta;
                masiniStoc.insert(std::make_pair(pointer, true));
                masiniStoc2[numarMasiniStoc] = *pointer;
                tipMasini[numarMasiniStoc] = 2;
                numarMasiniStoc++;
            }
            if(tipMasina == 3)
            {
                Automobil* pointer;
                Monovolum monovolum;
                monovolum.CitireAutomobil();
                pointer = &monovolum;
                masiniStoc.insert(std::make_pair(pointer, !pointer->GetSH()));
                masiniStoc2[numarMasiniStoc] = *pointer;
                tipMasini[numarMasiniStoc] = 3;
                numarMasiniStoc++;
            }
        }
    }
    ~Parc()
    {
    }
    void AfisareMasiniStoc()
    {
        std::set<std::pair<Automobil*, bool>> :: iterator it1;
        /*for ( it1 = masiniStoc.begin() ; it1 != masiniStoc.end() ; it1++)
        {
            Automobil* automobil;
            automobil = it1->first;
            automobil->AfisareAutomobil();
        }*/
        for (auto const &var : masiniStoc)
            var.first->AfisareAutomobil();
    }
    void AfisareMasiniStoc2()
    {
        for(int i=0;i<numarMasiniStoc;i++)
        {
            if(tipMasini[i] == 0)
            {
                objtr.CreazaMini(masiniStoc2[i]).AfisareAutomobil();
            }
            if(tipMasini[i] == 1)
            {
                objtr.CreazaMica(masiniStoc2[i]).AfisareAutomobil();
            }
            if(tipMasini[i] == 2)
            {
                objtr.CreazaCompacta(masiniStoc2[i]).AfisareAutomobil();
            }
            if(tipMasini[i] == 3)
            {
                objtr.CreazaMonovolum(masiniStoc2[i]).AfisareAutomobil();
            }
        }
    }
    void VindeMasina(int numarOrdine)
    {
        for(int i = numarOrdine;i<numarMasiniStoc-1;i++)
        {
            masiniStoc2[i] = masiniStoc2[i+1];
            tipMasini[i] = tipMasini[i+1];
            masiniVandute2[numarMasiniVandute] = masiniStoc2[i];
            tipMasini2[numarMasiniVandute] = tipMasini[i];
            numarMasiniStoc--;
            numarMasiniVandute++;
        }
    }
    void AdaugaMasina()
    {
        int tipMasinaNoua;
        std::cin>>tipMasinaNoua;
        if(tipMasinaNoua == 0)
            {
                Mini mini;
                std::cin>>mini;
                masiniStoc2[numarMasiniStoc] = mini;
                numarMasiniStoc++;
            }
            if(tipMasinaNoua == 1)
            {
                Mica mica;
                std::cin>>mica;
                masiniStoc2[numarMasiniStoc] = mica;
                numarMasiniStoc++;
            }
            if(tipMasinaNoua == 2)
            {
                Compacta compacta;
                std::cin>>compacta;
                masiniStoc2[numarMasiniStoc] = compacta;
                numarMasiniStoc++;
            }
            if(tipMasinaNoua == 3)
            {
                Monovolum monovolum;
                std::cin>>monovolum;
                masiniStoc2[numarMasiniStoc] = monovolum;
                numarMasiniStoc++;
            }
    }
    void AfisareMasiniVandute()
    {
        for(int i=0;i<numarMasiniVandute;i++)
        {
            if(tipMasini2[i] == 0)
            {
                objtr.CreazaMini(masiniVandute2[i]).AfisareAutomobil();
            }
            if(tipMasini2[i] == 1)
            {
                objtr.CreazaMica(masiniVandute2[i]).AfisareAutomobil();
            }
            if(tipMasini2[i] == 2)
            {
                objtr.CreazaCompacta(masiniVandute2[i]).AfisareAutomobil();
            }
            if(tipMasini2[i] == 3)
            {
                objtr.CreazaMonovolum(masiniVandute2[i]).AfisareAutomobil();
            }
        }
    }
    void NumarMasiniStoc()
    {
        std::cout<<numarMasiniStoc;
    }
    void NumarMasiniVandute()
    {
        std::cout<<numarMasiniVandute;
    }
};
void MeniuInteractiv()
{
    Parc parc;
    int optiune = 1;
    while(optiune)
    {
        std::cout<<"Apasa 1 pentru a afisa toate automobilele din stoc\n";
        std::cout<<"Apasa 2 pentru a vinde un automobil\n";
        std::cout<<"Apasa 3 pentru a adauga un automobil\n";
        std::cout<<"Apasa 4 pentru a afisa toate automobilele vandute\n";
        std::cout<<"Apasa 5 pentru a afisa numarul de masini in stoc\n";
        std::cout<<"Apasa 6 pentru a afisa numarul de masini vandute\n";
        std::cout<<"Apasa 0 pentru a inchide\n";
        std::cin>>optiune;
        if(optiune == 1)
        {
            parc.AfisareMasiniStoc2();
        }
        if(optiune == 2)
        {
            std::cout<<"Introdu numarul de ordine al masinii: ";
            int numarOrdine;
            std::cin>>numarOrdine;
            parc.VindeMasina(numarOrdine);
        }
        if(optiune == 3)
        {
            parc.AdaugaMasina();
        }
        if(optiune == 4)
        {
            parc.AfisareMasiniVandute();
        }
        if(optiune == 5)
        {
            parc.NumarMasiniStoc();
        }
        if(optiune == 6)
        {
            parc.NumarMasiniVandute();
        }
    }
}
void Demo()
{
    MeniuInteractiv();


}
int main()
{
    Demo();
    return 0;
}
