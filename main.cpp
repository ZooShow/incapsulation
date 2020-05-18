#include <iostream>
#include <string>

using namespace std;

class Car{
protected:
    float countOfGas;
    unsigned int speed;
public:
   string typeOfCar; //Отсутсвие инкапсуляции

    Car(string typeOfCar){
        countOfGas = 10;
        speed = 0;
        this->typeOfCar = typeOfCar;
    }

    float get_count_of_gas(){ //Инкапсуляция с помощью set/get
        return countOfGas;
    }

    unsigned int get_speed(){ //Инкапсуляция с помощью set/get
        return speed;
    }

    void press_on_the_gas(){ //Инкапсуляция с помощью специализированных протоколов/методов
        speed += 10;
    }

    void add_gasoline(int money){ //Инкапсуляция с помощью специализированных протоколов/методов
        if (countOfGas <= 100){
            countOfGas += money / 54.36;
        } else {
            throw "Your gas-tank full"; //механизм исключения, если нарушается инвариант или не соблюдаются пост/пред-условия
        }
    }
};

class TurikVeshka: public Car{
    bool turbine;
public:
    TurikVeshka(string typeOfCar, bool turbine) : Car(typeOfCar) {
        this-> typeOfCar = typeOfCar;
        countOfGas = 10;
        speed = 0;
        this->turbine = turbine;
    }

    virtual void add_gasoline(int money){ //За счёт позднего связывания
        if (countOfGas <= 150){
            countOfGas += money / 55.12;
        } else{
            throw "Your Turik gotov namativat'sya na stolb";
        }
    }

    virtual  void press_on_the_gas(){ //Замена поведения
        speed += 50;
    }

    bool isTurbineHere(){ // расширение поведения
        return turbine;
    }
};

void go_to_gas_station(Car &car, unsigned int money){
    car.add_gasoline(money);
}

int main(){
    try{
        string answer;
        cout << "Are you living in Vladivostok? (y/n)" << endl;
        cin >> answer;
        if (answer == "y"){
            cout << "vot tachka s turbinoy" << endl;
            TurikVeshka *car = new TurikVeshka("mark II", true);
            cout << "your car: " << car->typeOfCar<< endl;
            cout << "ti nazhal nemnogo na gaz i tvoya skorost' = ";
            car->press_on_the_gas();
            cout << car->get_speed() << endl;
            cout << "est' turbina? ";
            if (car->isTurbineHere() == 1){
                cout << "yes" << endl;
            } else {
                cout << "nop" << endl;
            }
            go_to_gas_station(*car, 1500);
            cout << "gaz status: " << car->get_count_of_gas() << endl;
        } else {
            cout << "vot tachka bez turbini" << endl;
            Car *car = new Car("prius");
            cout << "your car: " << car->typeOfCar<< endl;
            cout << "ti nazhal nemnogo na gaz i tvoya skorost' = ";
            car->press_on_the_gas();
            cout << car->get_speed() << endl;
            cout << "est' turbina? ";
            cout << "nop" << endl;
            go_to_gas_station(*car, 1500);
            cout << "gaz status: " << car->get_count_of_gas() << endl;
        }
    } catch(string a) {
        cout << a << endl;
    }
    return 0;
}
