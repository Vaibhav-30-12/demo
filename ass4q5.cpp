#include<iostream>
#include<string>
using namespace std;

class suite{
protected:
int numBedrooms;
    int numBathrooms;
    double pricePerBedroom;
    double pricePerBathroom;
    double specialCharges;
public:
suite(int bedrooms,double bathrooms,double bedroomPrice,double bathroomPrice,double charges): numBedrooms(bedrooms), numBathrooms(bathrooms),
          pricePerBedroom(bedroomPrice), pricePerBathroom(bathroomPrice), specialCharges(charges) {}

 double calculatecharges(int numNights){
        return (numBedrooms*pricePerBedroom+numBathrooms*pricePerBathroom+specialCharges)*numNights;

     }
     virtual void displayDetails()const =0;

};

class luxury:public suite{
    private:
    public:
    luxury(int bedrooms,double bathrooms, double bedroomPrice,double bathroomPrice,
    double charges): suite(bedrooms, bathrooms, bedroomPrice, bathroomPrice, charges) {}
    
    double calculatecharges(int numNights){
        return(numBedrooms*pricePerBedroom+numBathrooms*pricePerBathroom+specialCharges)*numNights;

    }
void display(){
    cout<<"luxury suite :"<<numBedrooms<<"bedtooms"<<numBathrooms <<"  bathrooms"<<endl;

}
    

};
class standard:public suite{
    private:
    public:
    standard(int bedrooms,double bathrooms,double bedroomPrice,double bathroomPrice,
    double charges):suite (bedrooms,bathrooms,bedroomPrice,bathroomPrice,
    charges ){}


double calculatecharges(int numNights){
        return(numBedrooms*pricePerBedroom+numBathrooms*pricePerBathroom+specialCharges)*numNights;

    }
void display(){
    cout<<"luxury suite :"<<numBedrooms<<"bedtooms"<<numBathrooms <<"  bathrooms"<<endl;
    
}

};

