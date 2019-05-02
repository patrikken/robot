#include <iostream>
typedef enum{Nord,Sud,Ouest,Est} Orientation;

using namespace std;

class Robot{
public:
    int X;
    int Y;
    Orientation O;
    static int Nbcre;
    static int Nbdec;
    Robot(int x,int y,Orientation o){
        X=x;
        Y=x;
        O=o;
        Nbcre++;
    }
    ~Robot()
    {
         cout << "un robot détruit" << this->X <<endl;
         Nbdec++;
    }
   void avancer();
   void tournerAdroit();
   static int Combien(){ return Nbcre;}
   static int Combiendec(){return Nbdec;}
};
      int Robot:: Nbcre(0);
      int Robot:: Nbdec(0);
void Robot::avancer(){

    switch(O){
        case Nord: Y=Y+1; break;
        case Sud: Y=Y-1;break;
        case Ouest: X=X-1;break;
        case Est: X=X+1;break;
    }

}

void Robot::tournerAdroit(){

    switch(O){

        case Nord: O=Est;
        case Sud: O=Ouest;
        case Ouest: O=Nord;
        case Est: O=Sud;

    }


}

int main()
{
    Robot zorzor(1,5,Est);
    Robot tubor(0,0,Est);
    Robot mantor(0,0,Est);
    Robot* tortor=new Robot(9,0,Est);

    cout << "moi c'est zorzor j'ai les coordonées "<< zorzor.X << " et "<< zorzor.Y << endl;
    zorzor.avancer();
    cout << "maintennant zorzor j'ai les coordonées "<< zorzor.X << " et "<< zorzor.Y << endl;
    delete tortor;
    zorzor.tournerAdroit();
    zorzor.avancer();
cout << "maintennant zorzor j'ai les coordonées "<< zorzor.X << " et "<< zorzor.Y << endl;
    cout << "\n\n il existe en tout " << Robot:: Combien() << "  Robot(s)"<<  endl;
    cout << "\n\n il existe en tout " << Robot:: Combiendec() << "  Robot(s) détruit"<<  endl;
    return 0;
}
