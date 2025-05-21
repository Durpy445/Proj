#include <math.h>

class Vector3
{
public:
    double X;
    double Y;
    double Z;
    double Magnitude;

    void Add(Vector3 NewVector)
    {
        this->X += NewVector.X;
        this->Y += NewVector.Y;
        this->Z += NewVector.Z;
        Update();
    }
    void Subtract(Vector3 NewVector)
    {
        this->X -= NewVector.X;
        this->Y -= NewVector.Y;
        this->Z -= NewVector.Z;
        Update();
    }
    void Mult(double Value){
        this->X *= Value;
        this->Y *= Value;
        this->Z *= Value;
        Update();
    }
    void Div(double Value){
        this->X /= Value;
        this->Y /= Value;
        this->Z /= Value;
        Update();
    }
    void Update(){
        this->Magnitude = std::sqrt(X * X + Y * Y + Z * Z);
    }
    Vector3(double NX, double NY, double NZ)
    {
        this->X = NX;
        this->Y = NY;
        this->Z = NZ;
        Update();
    }
};
class CFrame{
    public:
        //Postion
        double X;
        double Y;
        double Z;
        //Vector Pointer
        pt Vectorptr = nullptr;
        //Euler Angles
        double Alpha;
        double Beta;
        double Gamma;
        // Rotation Matrix
        double RotationMatrix[3][3];


        //Constructor
        CFrame(double NX,double NY,double NZ){
            this->X = NX;
            this->Y = NY;
            this->Z = NZ;
            Update();
        }
        void Update(){

            Vector3* Vectorptr = new Vector3(X,Y,Z);
            
        }




        
};




#include <iostream>

int main(int argc, char const *argv[])
{
    Vector3 Car(15, 165, 21);
    Car.Add(Vector3(10,10,10));
    CFrame Test(12452,125,21512);
    printf("%f", Test.Vectorptr);
    return 0;
}
