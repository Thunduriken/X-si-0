#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class stareJoc{
public:
    int zr;
    int xnr;
    int onr;
};

int main()
{
    // initializare
    stareJoc variabileTabla;
    int i,var[8],fin[5];
    string linieJoc;
    ifstream inFisier("ttt.in");
    ofstream outFisier("ttt.out");
    if(inFisier.is_open())
    {
        // citeste joc
        while(getline(inFisier,linieJoc))
        {
            // seteaza inceput joc
            for(i=0;i<=8;i++)
            {
                var[i]=0;
                fin[i]=0;
            }
            i=0;
            variabileTabla.zr=0;
            variabileTabla.xnr=0;
            variabileTabla.onr=0;

int tmp; //efectiv nu functioneaza daca nu numara aceasta variabila

            // detecteaza pozitii si simboluri
            for(char& temp : linieJoc)
            {
                tmp++; //lasat pentru functionalitatea programului pana fix
                if(temp=='X')
                {
                    var[i]=1;
                    variabileTabla.xnr++;
                    i++;
                }
                if(temp=='0')
                {
                    var[i]=2;
                    variabileTabla.onr++;
                    i++;
                }
                if(temp=='-')
                    i++;
            }

            // seteaza regulile
            // fin[1]=invalid, 2=incomplet, 3=I castiga, 4=II castiga
            if(variabileTabla.onr+variabileTabla.xnr<9)
                fin[1]=1;
            if(variabileTabla.onr>variabileTabla.xnr)
                fin[2]=1;
            if(var[0]>0 && var[0]==var[3] && var[3]==var[6])
                fin[var[0]+2]=1;
            if(var[1]>0 && var[1]==var[4] && var[4]==var[7])
                fin[var[1]+2]=1;
            if(var[2]>0 && var[2]==var[5] && var[5]==var[8])
                fin[var[2]+2]=1;
            if(var[0]>0 && var[0]==var[1] && var[1]==var[2])
                fin[var[0]+2]=1;
            if(var[3]>0 && var[3]==var[4] && var[4]==var[5])
                fin[var[3]+2]=1;
            if(var[6]>0 && var[6]==var[7] && var[7]==var[8])
                fin[var[6]+2]=1;
            if(var[0]>0 && var[0]==var[4] && var[4]==var[8])
                fin[var[0]+2]=1;
            if(var[2]>0 && var[2]==var[4] && var[4]==var[6])
                fin[var[2]+2]=1;

            //verificare joc
            for(i=4;i>=1;i--)
            {
                if(fin[4]==fin[3] && fin[4]==1)
                {
                    outFisier<<"Jocul este invalid."<<endl;
                    break;
                }
                if(fin[i]==1)
                {
                    if(i==1)
                        outFisier<<"Jocul este in progres."<<endl;
                    if(i==2)
                        outFisier<<"Jocul este invalid."<<endl;
                    if(i==3)
                        outFisier<<"Primul jucator a castigat."<<endl;
                    if(i==4)
                        outFisier<<"Al doilea jucator a castigat."<<endl;
                    break;
                }
                else
                    variabileTabla.zr++;
                if(variabileTabla.zr==4)
                {
                    outFisier<<"Egalitate."<<endl;
                    break;
                }
            }
        }
    }
    else
        cout<<"Fisierul de intrare nu a putut fi deschis ori nu exista."<<endl;

    return 0;
}
