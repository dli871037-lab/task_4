/*******************************
* Автор: Ли Даниил             *
* Задание: Циклы с ветвлениями *
* Вариант: 13                  *
*******************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {

  double tempIn, tempOver, wideIn, wideOver,
         lambdaIn, lambdaOver, tempCoordinates,
         wallCoordinates, finishStep, thermalConductanceIn,
         thermalConductanceOver, step, temperatureBetween;

  cout << "Inner wall temperature, C: ";
  cin >> tempIn;
  cout << "Outer wall temperature, C: ";
  cin >> tempOver;
  cout << "Inner layer thickness, centimeters: ";
  cin >> wideIn;
  cout << "Outer layer thickness, centimeters: ";
  cin >> wideOver;
  cout << "Inner layer thermal conductivity: ";
  cin >> lambdaIn;
  cout << "Outer layer thermal conductivity: ";
  cin >> lambdaOver;

  // проводимость 1-го слоя
  thermalConductanceIn = lambdaIn / wideIn;

  // проводимость 2-го слоя
  thermalConductanceOver = lambdaOver / wideOver;

  // Температура на границе слоёв
  temperatureBetween = (thermalConductanceIn * tempIn + thermalConductanceOver * tempOver) /
                       (thermalConductanceIn + thermalConductanceOver);

  // фиксируем 3 цифры после точки и делаем вывод 
  cout << fixed << setprecision(3)
       << "Temperature at the layer interface: " << temperatureBetween << endl
       << " x" << endl;

  // шаг первого цикла
  step = 100.0;

  // граница: 1-й цикл работает пока t > 300
  finishStep = 300.0;

  // стартовая температура для 1-го цикла
  tempCoordinates = 500.0;

  while (tempCoordinates > finishStep) {

    if (tempCoordinates > temperatureBetween) {
      wallCoordinates = (tempCoordinates - tempIn) / (temperatureBetween - tempIn) * wideIn;
    }

    else {
       wallCoordinates = (tempCoordinates - temperatureBetween) / (tempOver - temperatureBetween) * wideOver + wideIn;
    }

    // выводим координату, также переводим ее в метры
    cout << wallCoordinates / 100.0 << endl;

    tempCoordinates -= step;
    }

  // шаг 2-го цикла
  step = 100.0;

  // старт 2-го цикла            
  tempCoordinates = 250.0;

  do {

    if (tempCoordinates > temperatureBetween) {
      wallCoordinates = (tempCoordinates - tempIn) / (temperatureBetween - tempIn) * wideIn;
    }

    else {
      wallCoordinates = (tempCoordinates - temperatureBetween) / (tempOver - temperatureBetween) * wideOver + wideIn;
    }

    // выводим координату, также переводим ее в метры
    cout << wallCoordinates / 100.0 << endl;

    tempCoordinates -= step;
  } while (tempCoordinates >= 150.0);

    return 0;
}