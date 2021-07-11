#include <iostream>

class stack
{
public:
    //constructori
    stack(){}
    stack(stack& stiva)
    {
        int valori[100],lungime=0;
        int valoare;
        while(!(!*this))
        {
            *this>>valoare;
        }
        while(!(!stiva))
        {
            stiva>>valoare;
            valori[lungime] = valoare;
            lungime++;
        }
        for(int i=lungime-1;i>=0;i++)
        {
            *this<<valori[i];
            stiva<<valori[i];
        }
    }
    //destructor
    virtual ~stack(){}
    //metode publice
    void operator-()
    {
        int valoare;
        while(!*this)
        {
            *this>>valoare;
        }
    }
    bool operator==(stack& stackDeComparat)
    {
        int valoare1,valoare2;
        while(!(!*this))
        {
            *this>>valoare1;
            stackDeComparat>>valoare2;
            if(valoare1 != valoare2)
                return false;
        }
        if(!(!stackDeComparat))
            return false;
        return true;
    }
    bool operator!=(stack& stackDeComparat)
    {
        int valoare1,valoare2;
        while(!(!*this))
        {
            *this>>valoare1;
            stackDeComparat>>valoare2;
            if(valoare1 != valoare2)
                return true;
        }
        if(!(!stackDeComparat))
            return true;
        return false;
    }
    stack& operator=(stack& stackDeComparat)
    {
        int valori[100],lungime=0;
        int valoare;
        while(!(!*this))
        {
            *this>>valoare;
        }
        while(!(!stackDeComparat))
        {
            stackDeComparat>>valoare;
            valori[lungime] = valoare;
            lungime++;
        }
        for(int i=lungime-1;i>=0;i++)
        {
            *this<<valori[i];
            stackDeComparat<<valori[i];
        }
        return *this;
    }
    //metode pure publice
    virtual stack& operator<<(const int valoareDeIntrodus) = 0;//push
    virtual stack& operator>>(int& valoareDeExtras) = 0;//pull
    virtual bool operator!() = 0;//test vid 1-vid 0-nevid
};
//overload la << si >> ptr stack
std::ostream& operator<<(std::ostream& out,stack& stiva)
{
    int valoare;
    int valori[100],lungime=0;
    while(!(!stiva))
    {
        stiva>>valoare;
        valori[lungime] = valoare;
        lungime++;
    }
    for(int i=lungime-1;i>=0;i--)
    {
        std::cout<<valori[i]<<' ';
        stiva<<valori[i];
    }
    std::cout<<std::endl;
    return out;
}
std::istream& operator>>(std::istream& in, stack& stiva)
{
    std::cout<<"Introdu numere pana introduci 0"<<std::endl;
    int numar;
    std::cin>>numar;
    while(numar!=0)
    {
        stiva<<numar;
        std::cin>>numar;
    }
    return in;
}
class list
{
public:
    //constructori
    list(){}
    list(list& lista)
    {

        int contor = 0;
        int lungime = 0;
        while(!lista.end())
        {
            lista.next();
            contor++;
        }
        lista.reset();
        while(!lista.end())
        {
            lista.next();
            lungime++;
        }
        lista.reset();
        -*this;//vidam lista
        reset();
        int valoare,i;
        for(i=0;i<lungime;i++)
        {
            lista.get_next(valoare);
            ins_next(valoare);
            next();
            lista.next();
        }
        reset();
        for(i=0;i<lungime-contor;i++)
        {
            next();
        }
    }
    //destructori
    virtual ~list(){}
    //metode publice
    void operator-()//videaza lista
    {
        reset();
        while(!end())
        {
            del_next();
        }
    }
    bool operator==(list& listDeComparat)//test egal lista
    {
        int contor = 0;
        int lungime = 0;
        int valoare1,valoare2;
        while(!end())
        {
            next();
            contor++;
        }
        reset();
        while(!end())
        {
            next();
            lungime++;
        }
        reset();
        listDeComparat.reset();
        while(!end())
        {
            get_next(valoare1);
            get_next(valoare2);
            if(valoare1 != valoare2)
            {
                reset();
                for(int i=0;i<lungime;i++)
                {
                    next();
                }
                return false;
            }
        }
        if(!listDeComparat.end())
        {
            return false;
        }
        reset();
        for(int i=0;i<lungime;i++)
        {
            next();
        }
        return true;
    }
    bool operator!=(list& listDeComparat)//test diferit
    {
        int contor = 0;
        int lungime = 0;
        int valoare1,valoare2;
        while(!end())
        {
            next();
            contor++;
        }
        reset();
        while(!end())
        {
            next();
            lungime++;
        }
        reset();
        listDeComparat.reset();
        while(!end())
        {
            get_next(valoare1);
            get_next(valoare2);
            if(valoare1 != valoare2)
            {
                reset();
                for(int i=0;i<lungime;i++)
                {
                    next();
                }
                return true;
            }
        }
        if(!listDeComparat.end())
        {
            return true;
        }
        reset();
        for(int i=0;i<lungime;i++)
        {
            next();
        }
        return false;
    }
    list& operator=(list& listDeComparat)//atribuire
    {
        int contor = 0;
        int lungime = 0;
        while(!listDeComparat.end())
        {
            listDeComparat.next();
            contor++;
        }
        listDeComparat.reset();
        while(!listDeComparat.end())
        {
            listDeComparat.next();
            lungime++;
        }
        listDeComparat.reset();
        -*this;//vidam lista
        reset();
        int valoare,i;
        for(i=0;i<lungime;i++)
        {
            listDeComparat.get_next(valoare);
            ins_next(valoare);
            next();
            listDeComparat.next();
        }
        reset();
        for(i=0;i<lungime-contor;i++)
        {
            next();
        }
        return *this;
    }

    //metode pure publice
    virtual void reset() = 0;
    virtual bool next() = 0;
    virtual bool end() = 0;
    virtual bool ins_next(int numarInserat) = 0;
    virtual bool del_next() = 0;
    virtual bool get_next(int& numarDeFurnizat) = 0;
};

class vector
{
    int* buf;//adresa zonei cu elementele
    int n;
public:
    vector()
    {
        this->buf = new int;
        this->n = 0;
    }
    vector(const int numar)
    {
        this->buf = new int[1];
        this->n = 1;
        this->buf[0] = numar;
    }
    vector(const vector& vectorDeCopiat)
    {
        this->buf = new int[vectorDeCopiat.n];
        this->n = vectorDeCopiat.n;
        for(int i=0;i<vectorDeCopiat.n;i++)
        {
            this->buf[i] = vectorDeCopiat.buf[i];
        }
    }
    ~vector()
    {
        delete[] buf;
        buf = nullptr;
    }
    int& operator[](const int indice)
    {
        if(indice <= this->n)
        {
            return this->buf[indice];
        }
        else
        {
            //delete[] buf;
            buf = new int[indice];
        }
    }
    vector& operator=(const vector& vectorAtribuit)
    {
        delete buf;
        this->buf = new int[vectorAtribuit.n];
        this->n = vectorAtribuit.n;
        for(int i=0;i<vectorAtribuit.n;i++)
        {
            this->buf[i] = vectorAtribuit.buf[i];
        }
        return *this;
    }
    bool truncate(const int dimensiune)
    {
        if(dimensiune>=0)
        {
            this->n = dimensiune;
            return true;
        }
        else
        {
            return false;
        }
    }
    int length()
    {
        return this->n;
    }
    void SetBufDeI(int i, int numar)
    {
        buf[i] = numar;
    }
    int GetBufDeI(int i)
    {
        return buf[i];
    }
    void SetN(int newN)
    {
        n= newN;
    }
};

class stack_list : public stack, private list
{

public:
    //constructori
    stack_list(){}
    stack_list(stack_list& stackList)
    {
        *this = stackList;
    }
    //DESTRUCTOR
    virtual ~stack_list(){}

    //cu implementare
    stack& operator<<(const int valoareDeIntrodus)//push
    {
        reset();
        while(!end())
        {
            next();
        }
        ins_next(valoareDeIntrodus);
        return *this;
    }
    stack& operator>>(int& valoareDeExtras)//pop
    {
        reset();
        int contor=0;
        while(!end())
        {
            next();
            contor++;
        }
        reset();
        while(contor>1)
        {
            contor--;
            next();
        }
        get_next(valoareDeExtras);
        del_next();
        return *this;
    }
    bool operator!()//test stiva vida
    {
        reset();
        if(end())
        {
            return true;
        }
        return false;
    }

    virtual void reset() = 0;
    virtual bool next() = 0;
    virtual bool end() = 0;
    virtual bool ins_next(int numarInserat) = 0;
    virtual bool del_next() = 0;
    virtual bool get_next(int& numarDeFurnizat) = 0;

};

class stack_list_vector : public stack_list, private vector
{
    int k;//pozitia curenta pentru list
    static int numarDeStackListVectori;
public:
    //constructori
    stack_list_vector()
    {
        numarDeStackListVectori++;
    }
    stack_list_vector(stack_list_vector& stackListVector)
    {
        int valoare;
        int valori[100],lungime=0;
        while(!(!*this))
        {
            *this>>valoare;
        }
        while(!(!stackListVector))
        {
            stackListVector>>valoare;
            valori[lungime] = valoare;
            lungime++;
        }
        for(int i=lungime-1;i>=0;i--)
        {
            *this<<valori[i];
            stackListVector<<valori[i];
        }
    }
    //destructor
    ~stack_list_vector()
    {
        numarDeStackListVectori--;
    }
    //se implementeaza
    void reset()
    {
        k=-1;
    }
    bool next()
    {
        if(k<length()-1)
        {
            k++;
            return true;
        }
        return false;
    }
    bool end()
    {
        if(k == length()-1)
            return true;
        return false;
    }
    bool ins_next(int numarInserat)
    {
        truncate(length()+1);
        SetBufDeI(k+1, numarInserat);
        return true;
        return false;
    }
    bool del_next()
    {
        if(k<length()-1)
        {
           truncate(k+1);
            return true;
        }
        return false;
    }
    bool get_next(int& numarDeFurnizat)
    {
        if(k<length()-1)
        {
            //numarDeFurnizat = buf[k+1];
            numarDeFurnizat = GetBufDeI(k+1);
            return true;
        }
        return false;
    }

    bool operator==(stack_list_vector& stackListVectorDeComparat)
    {
        int valoare1,valoare2;
        while(!(!*this))
        {
            *this>>valoare1;
            stackListVectorDeComparat>>valoare2;
           // std::cout<<valoare1<<' '<<valoare2<<std::endl;
            if(valoare1 != valoare2)
                return false;
        }
        if(!(!stackListVectorDeComparat))
            return false;
        return true;
    }
    bool operator!=(stack_list_vector& stackListVectorDeComparat)
    {
        int valoare1,valoare2;
        while(!(!*this))
        {
            *this>>valoare1;
            stackListVectorDeComparat>>valoare2;
            if(valoare1 != valoare2)
                return true;
        }
        if(!(!stackListVectorDeComparat))
            return true;
        return false;
    }
    stack_list_vector& operator=(stack_list_vector& stackListVectorDeComparat)
    {
        int valoare;
        int valori[100],lungime=0;
        while(!(!*this))
        {
            *this>>valoare;
        }
        while(!(!stackListVectorDeComparat))
        {
            stackListVectorDeComparat>>valoare;
            valori[lungime] = valoare;
            lungime++;
        }
        for(int i=lungime-1;i>=0;i--)
        {
            *this<<valori[i];
            stackListVectorDeComparat<<valori[i];
        }
        return *this;
    }


};

int stack_list_vector::numarDeStackListVectori = 0;

void Demo()
{
    stack_list_vector s,t;
    std::cin >> s;
    std::cout<<s;
    t= s;
    std::cout<<t<<t;
    // se inverseaza t intr un Stack r
    stack_list_vector r;
    int valoare;
    while(!(!t))
    {
        t>>valoare;
        r<<valoare;
    }
    std::cout<<r;
    if(s==r)
        std::cout<<"egale";
    else
        std::cout<<"nu sunt egale";
    std::cout<<std::endl;
}

void MeniuInteractiv()
{
    int optiune=1;
    stack_list_vector element1,element2;
    while(optiune)
    {
    std::cout<<"Apasa 1 pentru a scrie un stack_list_vector"<<std::endl;
    std::cout<<"Apasa 2 pentru a da un push"<<std::endl;
    std::cout<<"Apasa 3 pentru a da un pull"<<std::endl;
    std::cout<<"Apasa 4 pentru a scrie un alt stack_list_vector"<<std::endl;
    std::cout<<"Apasa 5 pentru a compara cele doua stack_list_vector"<<std::endl;
    std::cout<<"Apasa 6 pentru Demo"<<std::endl;
    std::cout<<"Apasa 0 pentru a inchide"<<std::endl;
    std::cin>>optiune;
    if(optiune==1)
    {
        std::cin>>element1;
        std::cout<<element1;
    }
    else if(optiune==2)
    {
        int numarPentruPush;
        std::cout<<"Cu ce numar vrei sa dai push?"<<std::endl;
        std::cin>>numarPentruPush;
        element1<<numarPentruPush;
        std::cout<<element1;
    }
    else if(optiune==3)
    {
        int numarPentruPull;
        element1>>numarPentruPull;
        std::cout<<"S a extras numarul "<<numarPentruPull<<std::endl;
        std::cout<<element1;
    }
    else if(optiune==4)
    {
        std::cin>>element2;
        std::cout<<element2;
    }
    else if(optiune==5)
    {
        if(element1==element2)
            std::cout<<"egale";
        else
            std::cout<<"nu sunt egale";
        std::cout<<std::endl;
    }
    else if(optiune==6)
    {
        Demo();
    }
    else if(optiune==0)
    {
        return;
    }
    else
    {
        std::cout<<"Nu ai introdus un numar bun, mai incearca"<<std::endl;
    }
    }
}

int main()
{
    //Demo();
    MeniuInteractiv();
    return 0;
}
