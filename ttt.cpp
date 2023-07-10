#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int i,zr,xnr,onr,var[8],fin[5];
char temp[1];

int main()
{
    // initializare
	std::ifstream inFisier("ttt.txt");
	std::ofstream outFisier("ttt.out");
    xnr=0; onr=0;
//    for(zr=1;zr<=4;zr++)
//        outFisier<<fin[zr]<<" ";
//    outFisier<<"\n";

    // configurare si verificare joc(uri)
    while(getline(inFisier,temp," "))
    {
        if(strcmp(temp,"X")==0)
        {
            var[i]=1;
            xnr++;
        }
        if(strcmp(temp,"0")==0)
        {
            var[i]=2;
            onr++;
        }
//        outFisier<<var[i]<<" ";
        i++;

        // determinare joc
        // fin[1]=jocul e invalid, 2=incomplet, 3=primul castiga, 4=al doilea castiga
        if(i==9)
        {
//            outFisier<<"\n";
//            for(zr=0;zr<=3;zr++)
//                outFisier<<fin[zr]<<" ";
//            outFisier<<"\n";
            if(onr+xnr<9)
                fin[1]=1;
            if(onr>xnr)
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

            zr=0;
            for(i=4;i>=1;i--)
            {
                if(fin[4]==fin[3] && fin[4]==1)
                {
                    outFisier<<"Jocul este invalid."<<"\n";
                    break;
                }
                if(fin[i]==1)
                {
                    if(i==1)
                        outFisier<<"Jocul este in progres."<<"\n";
                    if(i==2)
                        outFisier<<"Jocul este invalid."<<"\n";
                    if(i==3)
                        outFisier<<"Primul jucator a castigat."<<"\n";
                    if(i==4)
                        outFisier<<"Al doilea jucator a castigat."<<"\n";
                    break;
                }
                else
                    zr++;
                if(zr==4)
                {
                    outFisier<<"Egalitate."<<"\n";
                    break;
                }
            }
//            outFisier<<"xnr="<<xnr<<" onr="<<onr<<"\n";

            //reinitializare pentru jocul urmator
            for(i=0;i<=8;i++)
            {   var[i]=0;
                fin[i]=0;   }
            i=0;
            xnr=0;
            onr=0;
        }
    }
    return 0;
}
