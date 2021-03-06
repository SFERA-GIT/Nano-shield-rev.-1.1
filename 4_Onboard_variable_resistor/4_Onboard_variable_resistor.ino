/*
   https://github.com/SFERA-GIT/Nano-shield
   СФЕРА ЗНАНИЙ (г.Челябинск) http://сферазнаний.рф/
   Пример работы с переменными резисторами (A6,A7)
   Для работы с переменными резисторами необходимо установить
   перемычки на верхней гребенке между зеленым и желтыми
   пинами напротив соответствующей ножки A6 или A7.
*/

//Объявляем константы с помощью оператора #define
#define white 5
#define blue 6
#define LVR A6
#define RVR A7

//Обязательная функция setup (выполняется один раз перед функцией loop)
void setup()
//Тело функции setup
{
  pinMode(white, OUTPUT);  //настройка контакт white(5) на выход
  pinMode(blue, OUTPUT);   //настройка контакт blue(6) на выход
  pinMode(LVR, INPUT);     //настройка контакт LVR(A6) на вход
  pinMode(RVR, INPUT);     //настройка контакт RVR(A7) на вход
}

//Обязательная функция loop (бесконечно повторяющаяся функция)
void loop()
//Тело функции loop
{
  int x = analogRead(LVR);     // создаем пееременную x типа int и присваеваем ей аналоговые значения с порта A6
  int y = analogRead(RVR);     // создаем пееременную y типа int и присваеваем ей аналоговые значения с порта A7
  x = map(x, 0, 1023, 0, 254); // для полученных значений переменной x применяем маску преобразуя диапазон 0-1023 к 0-254
  y = map(y, 0, 1023, 0, 254); // для полученных значений переменной y применяем маску преобразуя диапазон 0-1023 к 0-254
  analogWrite(white, x);       // преобразованные значения записываем на контакт(с ШИМ) white(5)
  analogWrite(blue, y);        // преобразованные значения записываем на контакт(с ШИМ) blue(6)
}
