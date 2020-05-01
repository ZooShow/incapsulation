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

    void go_to_gas_station(int money){ //Инкапсуляция с помощью специализированных протоколов/методов
        if (countOfGas <= 100){
            countOfGas += money / 54.36;
        } else {
            throw "Your gas-tank full"; //механизм исключения, если нарушается инвариант или не соблюдаются пост/пред-условия
        }
    }
};

class TurikVeshka: public Car{ //Инкапсуляция за счёт абстракций
    bool turbine;
public:
    TurikVeshka(string typeOfCar, bool turbine) : Car(typeOfCar) {
        if (typeOfCar != "chaser"){
            throw "Ne ta tachila, bratan";
        }
        countOfGas = 10;
        speed = 0;
        this->turbine = turbine;
    }

    virtual void go_to_gas_station(int money){ //За счёт позднего связывания
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

int main(){
    return 0;
}
