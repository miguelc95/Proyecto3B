//Autores: Carmelo Rmz A01175987 y Miguel Cuellar A01280736
//Fecha: 29/04/2016
//Proyecto: Sparko's Birthday II

#include<iostream>
#include <queue>
#import <cmath>
using namespace std;

int iMat[50][50], iNumCasas, nivel=0;
int mejorCamino=32000;
struct Nodo
{
    int iCostoPosible, iAnterior,inivel;
    int iPasados[20];
};

struct compare
{
    bool operator()(Nodo l, Nodo r)
    {
        return l.iCostoPosible > r.iCostoPosible;
    }
};

priority_queue<Nodo,vector<Nodo>, compare > filaPriorizada;;

void inicializarMatriz(int iNumCasas)
{
    for(int i=0; i<iNumCasas; i++)
    {
        for(int j=0; j<iNumCasas; j++)
        {
            if(i == j)
                iMat[i][j] = 0;
            else
                iMat[i][j] = 32000;
        }
    }
    
}

/*int calcularCostoPosible()
{
    //for()
}*/

void crearArbol()
{
    Nodo nNodo1;
    
   
}

void primerNodo(){
    Nodo nodo1;
    int imenor=32000, iacum=0;
    
    for (int i=0; i<iNumCasas; i++) {
        imenor=32000;
        for (int j=0; j<iNumCasas; j++) {
            if (i!=j)imenor= min(imenor,iMat[i][j]);
        }
        iacum+=imenor;
        
    }
    nodo1.iCostoPosible=iacum;
    nodo1.inivel=0;
    nivel++;
    filaPriorizada.push(nodo1);
}

void menor(int ilower){
    Nodo nodo;
    while (!filaPriorizada.empty()) {
        if (ilower<mejorCamino) {
            nodo.inivel=nivel++;
        }
        if (nivel==iNumCasas-1) {
            <#statements#>
        }
    }
}

int main()
{
    int iNumCaminos, iDist;
    char cCasa1, cCasa2;
    //Ingresamos los datos de el numero de casas y caminos
    cin>>iNumCasas>>iNumCaminos;
    
    inicializarMatriz(iNumCasas);
    //Ingresamos las distancias entre las casa
    for(int i=1; i<=iNumCaminos; i++)
    {
        cin>>cCasa1>>cCasa2>>iDist;
        iMat[cCasa1 - 65][cCasa2 - 65] = iDist;
        iMat[cCasa2 - 65][cCasa1 - 65] = iDist;
    }
    
    for(int i=0; i<iNumCasas; i++)
    {
        for(int j=0; j<iNumCasas; j++)
            cout<<iMat[i][j]<<" ";
        cout<<endl;
    }
    primerNodo();
    
    
    
    
    return 0;
}