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
    Vector3()
    {
        this->X = 0;
        this->Y = 0;
        this->Z = 0;
        Update();
    }
};
class CFrame{
    public:
        //Postion
        double X,Y,Z;
        //Vector Pointer
        Vector3 Vector;
        //Euler Angles
        double Alpha;
        double Beta;
        double Gamma;
        // Rotation Matrix
        double RotationMatrix[3][3];
        //Deafult Constructor
        CFrame(){
            this->Vector = Vector3(X,Y,Z);
        }
        //Constructor without angles
        CFrame(double NX,double NY,double NZ,double){
            this->X = NX;
            this->Y = NY;
            this->Z = NZ;

            this->Vector = Vector3(X,Y,Z);
        }
        //Constructor with Angles
        CFrame(double NX,double NY,double NZ,double Alpha,double Beta,double Gamma){
            this->X = NX;
            this->Y = NY;
            this->Z = NZ;

            this->Alpha = Alpha;
            this->Beta = Beta;
            this->Gamma = Gamma;
            this->Vector = Vector3(X,Y,Z);
        }
        //Constructor using a vector3
        CFrame(Vector3 Vector){
            SetPos(Vector);
            this->Vector = Vector;
        }
        //Sets Postion Using a vector
        void SetPos(Vector3 Vector){
            this->X = Vector.X;
            this->Y = Vector.Y;
            this->Z = Vector.Z;
        }
        //Adds Vector to CFrame (non directional)
        void AddPos(Vector3 Vector){
            this->Vector.Add(Vector);
            SetPos(this->Vector);
        }
        //Turns the euler angles stored into a rotation matrix set in the Za Xb Yg formation

        void UpdateMatrix(){
            double ca = cos(Alpha), sa = sin(Alpha);
            double cb = cos(Beta), sb = sin(Beta);
            double cy = cos(Gamma), sy = sin(Gamma);

            double Temp[3][3] = {
                {ca*cy-sa*sb*sy,-cb*sa,ca*sy+cy*sa*sb},
                {cy*sa+ca*sb*sy,ca*cb,sa*sy-ca*cy*sb},
                {-cb*sy,sb,cb*cy}
            };
            std::copy(&Temp[0][0], &Temp[0][0] + 9, &this->RotationMatrix[0][0]);
        }
        void UpdateEuler(){
            //this->Alpha = atan();
        }
};




#include <iostream>

int main()
{
    Vector3 Car(15, 165, 21);
    Car.Add(Vector3(10,10,10));
    CFrame Testaaa;
    Testaaa.UpdateMatrix();
    printf("%f",Testaaa.RotationMatrix[1][1]);
    return 0;
}
