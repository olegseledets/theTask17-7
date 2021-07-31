#include <iostream>

void fillingBoolBubble(bool bubble[][12]){
  for(int i = 0; i < 12; ++i){
    for(int j = 0; j < 12; ++j){
      bubble[i][j] = true;
    }
  }
}

int showBubbleSheet(bool bubb[][12], int count){
  std::cout << "\nСостояние пленки" << std::endl;
  for(int i = 0; i < 12; ++i){
    for(int j = 0; j < 12; ++j){
      bubb[i][j] == true ? std::cout << "O\t" : (++count, std::cout << "X\t");
    }
    std::cout << std::endl;
  }
  return count;
}

int coordCheck(std::string varName){
  int var = -1;
  while (var < 0 || var > 11){
    std::cout << "Введите " << varName << ": ";
    std::cin >> var;  
  }
  return var;
}

void burstBubble(int x, int y, int x1, int y1, bool bubb[][12]){
  int k, l;     // k - мин. верт. l - макс верт
  int m, n;     // m - мин. горю  n - макс гор
  x <= x1 ? (k = x, l = x1) : (k = x1, l = x); 
  y <= y1 ? (m = y, n = y1) : (m = y1, n = y); 
  
  for(int i = k; i <= l; ++i){
    for(int j = m; j <= n; ++j){
      if(bubb[i][j] == true){
        std::cout << "Pop!" << std::endl;
        bubb[i][j] = false;
      }
    }
  }

}

void burstCoord(int x, int y, int x1, int y1, bool bubb[][12]){
  std::cout << "Введите область лопания" << std::endl;
  std::cout << "Введите координаты Начала региона" << std::endl;
  x = coordCheck("X");
  y = coordCheck("Y");
  std::cout << "Введите координаты Конца региона" << std::endl;
  x1 = coordCheck("X1");
  y1 = coordCheck("Y1");
  //функция лопания
  burstBubble(x, y, x1, y1, bubb);
}


int main() {
  
  bool boolBubbleSheet[12][12];
  int x, y, x1, y1;
  int counter = 0;
  //функция инициализации массива
  fillingBoolBubble(boolBubbleSheet);
  while(counter < 144){
    //функция проверки координат для лопания
    burstCoord(x, y, x1, y1, boolBubbleSheet);
    //показать всю пленку
    counter = showBubbleSheet(boolBubbleSheet, counter);
  }
  //showBubbleSheet(boolBubbleSheet, counter);
  std::cout << "Пленка лопнута!" << std::endl;
}

/*
После посылки из Китая осталась спец. плёнка для бережной перевозки груза — пупырка. Всего в пупырке 12 на 12 шариков-пузырьков. Состояние любого пузырька — это всегда либо он целый, либо нет, т.е. true или false (тип массива bool). Для начала, требуется реализовать отдельную функцию инициализации пупырки начальным состоянием — полностью целая пупырка, т.е. все элементы true. Но это только самое начало.

Программа заключается в последовательном лопанье целых регионов пузырьков. Перед каждым таким лопаньем надо показывать пользователю полностью всю плёнку: o — это целый пузырёк, x — лопнутый. Это тоже надо выделить в отдельную функцию. Итак, как выглядит само лопанье. Пользователь вводит две координаты: координаты начала региона и конца прямоугольного региона. Сама процедура лопанья пузырей должна быть реализована с помощью отдельной функции, все аргументы должны проверяться на их валидность, что они в в рамках диапазона возможных значений — иначе должна быть выведена ошибка. После лопанья каждого пузыря, который не был ещё лопнут до того, в консоль должно выводиться сообщение “Pop!”.

Лопанье должно продолжаться до последнего пузырька. Как только вся пупырка потрачена, программа заканчивает выполнение. В принципе, вы можете подсчитать окончание в самой функции по отображению пузырьков плёнки, т.к. она выполняется после каждого лопанья.
*/