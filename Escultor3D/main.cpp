#include <iostream>
#include "sculptor.h"
#include <string>

using namespace std;

int main()
{
    Sculptor *obj;
    int nx,ny,nz;
    float r,g,b,a;
    int opt;
    cout << "Digite as dimensoes da escultura:\nEm X: ";
    cin >> nx;
    cout << "Em Y: ";
    cin >> ny;
    cout << "Em Z: ";
    cin >> nz;

    obj = new Sculptor(nx,ny,nz);

    cout << "Defina a cor do objeto a desenhar no formato RGB:\n[0-1] Red: ";
    cin >> r;
    cout << "[0-1] Green: ";
    cin >> g;
    cout << "[0-1] Blue: ";
    cin >> b;
    cout << "\nDefina o grau de opacidade [0-1]: ";
    cin >> a;

    obj->setColor(r,g,b,a);

    do{
        system("cls");//Limpar tela

        cout << "ESCOLHA UMA DAS SEGUINTES ACOES\n\n";
        cout << "1- Redefinir Cor e Opacidade" << endl;
        cout << "2- Criar Voxel         3-Apagar Voxel" << endl;
        cout << "4- Criar Bloco         5-Apagar Bloco" << endl;
        cout << "6- Criar Esfera        7-Apagar Esfera" << endl;
        cout << "8- Criar Elipsoide     9-Apagar Elipsoide" << endl;
        cout << "10- Gravar em formato VECT" << endl;
        cout << "11- Gravar em formato OFF" << endl;
        cout << "12- Finalizar Programa" << endl;

        cin >> opt; // colocar condições para limitar os valores de 1 a 12...

       if(opt == 1){
           cout << "Defina a cor do objeto a desenhar no formato RGB:\n[0-1] Red: ";
           cin >> r;
           cout << "[0-1] Green: ";
           cin >> g;
           cout << "[0-1] Blue: ";
           cin >> b;
           cout << "\nDefina o grau de opacidade [0-1]: ";
           cin >> a;

       } else if (opt == 2) {
           int x,y,z;
           cout << "Informe a posicao do voxel:\n[0-"<<nx-1<<"] X: ";
           cin >> x;
           cout << "[0-"<<ny-1<<"] Y: ";
           cin >> y;
           cout << "[0-"<<nz-1<<"] Z: ";
           cin >> z;
           obj->putVoxel(x,y,z);

       } else if (opt == 3) {
           int x,y,z;
           cout << "Informe a posicao do voxel:\n[0-"<<nx-1<<"] X: ";
           cin >> x;
           cout << "[0-"<<ny-1<<"] Y: ";
           cin >> y;
           cout << "[0-"<<nz-1<<"] Z: ";
           cin >> z;
           obj->cutVoxel(x,y,z);

       } else if (opt == 4) {
           int x0,x1,y0,y1,z0,z1;
           cout << "Informe o inicio e o fim do bloco em X:\nX0: ";
           cin >> x0;
           cout << "X1: ";
           cin >> x1;
           cout << "Informe o inicio e o fim do bloco em Y:\nY0: ";
           cin >> y0;
           cout << "Y1: ";
           cin >> y1;
           cout << "Informe o inicio e o fim do bloco em Z:\nZ0: ";
           cin >> z0;
           cout << "Z1: ";
           cin >> z1;
           obj->putBox(x0,x1,y0,y1,z0,z1);

       } else if (opt == 5) {
           int x0,x1,y0,y1,z0,z1;
           cout << "Informe o inicio e o fim do corte(bloco) em X:\nX0: ";
           cin >> x0;
           cout << "X1: ";
           cin >> x1;
           cout << "Informe o inicio e o fim do corte(bloco) em Y:\nY0: ";
           cin >> y0;
           cout << "Y1: ";
           cin >> y1;
           cout << "Informe o inicio e o fim do corte(bloco) em Z:\nZ0: ";
           cin >> z0;
           cout << "Z1: ";
           cin >> z1;
           obj->cutBox(x0,x1,y0,y1,z0,z1);

       } else if (opt == 6) {
            int xc,yc,zc,r;
            cout << "Informe o centro da esfera:\nXc: ";
            cin >> xc;
            cout << "Yc: ";
            cin >> yc;
            cout << "Zc: ";
            cin >> zc;
            cout << "Informe o raio da esfera:\nRx: ";
            cin >> r;

            obj->putSphere(xc,yc,zc,r);
       } else if (opt == 7) {
           int xc,yc,zc,r;
           cout << "Informe o centro da esfera:\nXc: ";
           cin >> xc;
           cout << "Yc: ";
           cin >> yc;
           cout << "Zc: ";
           cin >> zc;
           cout << "Informe o raio da esfera:\nRx: ";
           cin >> r;

           obj->cutSphere(xc,yc,zc,r);

       } else if (opt == 8) {
            int xc,yc,zc,rx,ry,rz;
            cout << "Informe o centro da elipsoide:\nXc: ";
            cin >> xc;
            cout << "Yc: ";
            cin >> yc;
            cout << "Zc: ";
            cin >> zc;
            cout << "Informe os raios da elipsoide:\nRx: ";
            cin >> rx;
            cout << "Ry: ";
            cin >> ry;
            cout << "Rz: ";
            cin >> rz;

            obj->putEllipsoid(xc,yc,zc,rx,ry,rz);

       } else if (opt == 9) {
           int xc,yc,zc,rx,ry,rz;
            cout << "Informe o centro da elipsoide:\nXc: ";
            cin >> xc;
            cout << "Yc: ";
            cin >> yc;
            cout << "Zc: ";
            cin >> zc;
            cout << "Informe os raios da elipsoide:\nRx: ";
            cin >> rx;
            cout << "Ry: ";
            cin >> ry;
            cout << "Rz: ";
            cin >> rz;

            obj->cutEllipsoid(xc,yc,zc,rx,ry,rz);
       } else if (opt == 10) {
            string arq;
            cout << "Nome do arquivo (sem extensao): ";
            cin >> arq;
            arq += ".vect";
            obj->writeVECT(arq);

       } else if (opt == 11) {
           string arq;
           cout << "Nome do arquivo (sem extensao): ";
           cin >> arq;
           arq += ".off";
           obj->writeOFF(arq);
       }

    }while(opt != 12);

    //TESTE | Mostrar camadas do objeto
    for(int i = 0; i<nx; i++){
        for(int j = 0; j<ny; j++){
            for(int k = 0; k<nz; k++){
                obj->getP(i,j,k);
            }
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}
