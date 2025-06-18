//=======================================================================
//    Лабораторная №3. Шаблоны функций. Шаблоны классов. Стандартные шаблоны С++.
//                Обработка исключений.
//=======================================================================
//Используйте недостающие файлы из лабораторной 2
#include "stdafx.h"
#include "MyVector.h"
#include "MyString.h"
#include "MyStack.h"
#include <algorithm>
#include "Shape.h"
using std::cout;
using std::endl;
using std::string;


int Shape::Count = 0;
Shape* Shape::shapes[1000];

//============= Шаблон функции для вывода с помощью итератора
template <class T> void pr(T& v, string s)
{
    cout << "\n\n\t" << s << " iterator: \n";

    //итератор 
    typename T::iterator p;
    int i;

    for (p = v.begin(), i = 0; p != v.end(); p++, i++)
        cout << endl << i + 1 << ". " << *p;
    cout << '\n';
}

template<typename T> void Swap(T&, T&);

void Print_Vector(Vector& other);
bool isSumGreaterThanTwo(const Vector& v);
bool startsWithA(string s);
class starObjectWith {
private:
    string prefix;
public:
    starObjectWith(const string& prefix) : prefix(prefix) {};
    bool operator()(const string& str) const {
        return str.find(prefix) == 0;
    }
};

int main()
{

    //===========================================================
    // Шаблоны функций
    //===========================================================
    // Создайте шаблон функции перестановки двух параметров - Swap().
    // Проверьте работоспособность созданного шаблона с помощью
    // приведенного ниже фрагмента.
    {
        int i = 1, j = -1;
        Swap(i, j);

        double a = 0.5, b = -5.5;
        Swap(a, b);

        Vector u(1, 2), w(-3, -4);
        Swap(u, w);

        // Если вы достаточно развили класс MyString в предыдущей работе,
        // то следующий фрагмент тоже должен работать корректно.

        MyString s1("Your fault"), s2("My forgiveness");
        Swap(s1, s2);
    }
    //===========================================================
    // Шаблоны классов
    //===========================================================
    // Создайте шаблон класса MyStack для хранения элементов любого типа T.
    // В качестве основы для стека может быть выбран массив.
    // Для задания максимального размера стека может быть использован
    // параметр-константа шаблона
    // Обязательными операциями со стеком являются "Push" и "Pop","GetSize" и "Capacity"
    // Необязательной - может быть выбор по индексу (operator[]).
    // Для того, чтобы гарантировать корректное выполнение этих операций
    // следует генерировать исключительные ситуации.

    // С помощью шаблона MyStack создайте стек переменных типа int, затем
    // стек переменных типа double и, наконец, стек из переменных типа Vector
    // Если вы подготовите три класса для обработки исключений,
    // то следующий фрагмент должен работать
    try
    {
        cout << "\tTest MyStack\n";
        MyStack <int, 3> stack;

        cout << "\nInteger Stack capacity: " << stack.Capacity();

        stack.Push(1);
        stack.Push(2);
        stack.Push(3);

        cout << "\nInteger Stack has: " << stack.GetSize() << " elements";


        cout << "\nInteger Stack pops: " << stack.Pop();
        cout << "\nInteger Stack pops: " << stack.Pop();

        cout << "\nInteger Stack has: " << stack.GetSize() << " elements";
        stack.Pop();

        stack.Push(2);



        MyStack<Vector, 5> ptStack;

        cout << "\nVector Stack capacity: " << ptStack.Capacity();

        ptStack.Push(Vector(1, 1));
        ptStack.Push(Vector(2, 2));

        cout << "\nVector Stack pops: ";
        // Используйте метод класса Vector для вывода элемента
        ptStack.Pop().Out();

        cout << "\nVector Stack has: " << ptStack.GetSize() << " elements";
    }
    catch (StackOverflow)
    {
        cout << "\nStack overflow";
    }
    catch (StackUnderflow)
    {
        cout << "\nStack underflow";
    }
    catch (StackOutOfRange)
    {
        cout << "\n ye\n";
    }




    //=======================================================================
    // Контейнеры стандартной библиотеки. Последовательности типа vector
    //=======================================================================

    // Создайте пустой вектор целых чисел. Узнайте его размер с помощью метода size(),
    // С помощью метода push_back() заполните вектор какими-либо значениями.
    // Получите новый размер вектора и выведите значения его элементов.
    // В процессе работы с вектором вы можете кроме количества реально заполненных
    // элементов (size()) узнать максимально возможное количество элементов (max_size()),
    // а также зарезервированную память (capacity()).

    vector<int> v = { 1, 2, 3, 4, 5, 6, 7 , 8 };
    size_t n = v.size();
    v.push_back(-1);
    v.push_back(-2);
    cout << "\nn " << n;
    n = v.size();
    cout << "\nn " << n;
    n = v.capacity();
    cout << "\nn " << n;
    n = v.max_size();
    cout << "\nn " << n;

    // Так как мы часто будем выводить последовательности, то целесообразно
    // создать шаблон функции для вывода любого контейнера.
    // Проанализируйте коды такого шабдлона (pr), который приведен выше
    // Используйте его для вывода вашего вектора

    pr(v, "Vector of ints");

    // Используем другой конструктор для создания вектора вещественных
    // с начальным размером в 2 элемента и заполнением (222.).
    // Проверим параметры вектора. Затем изменим размер вектора и его заполнение
    // (метод - resize()) и вновь проверим параметры.

    vector<double> vd = { 1, 2, 3, 4, 5, 6, 7 };
    pr(vd, "Vector of doubles");
    n = vd.size();
    n = vd.capacity();
    n = vd.max_size();

    vd.resize(50);
    pr(vd, "After resize");
    n = vd.size();
    n = vd.capacity();
    n = vd.max_size();

    // Используя метод at(), а также операцию выбора [], измените значения
    // некоторых элементов вектора и проверьте результат.
    vd.at(3) = vd[0];
    pr(vd, "After at");

    // Создайте вектор вещественных, который является копией существующего.
    vector<double> wd = vd;
    pr(wd, "Copy");

    // Создайте вектор, который копирует часть существующей последовательности
    vector<double> ud(wd.begin() + 1, wd.begin() + 3);
    pr(ud, "Copy part");

    // Создайте вектор вещественных, который является копией части обычного массива.
    double ar[] = { 0., 1., 2., 3., 4., 5. };

    vector<double> va(ar + 1, ar + 3);
    pr(va, "Copy part of array");

    // Создайте вектор символов, который является копией части обычной строки
    char s[] = "Array is a succession of chars";

    vector<char> vc(s + 1, s + 5);
    pr(vc, "Copy part of c-style string");

    // Создайте вектор элементов типа Vector и инициализируйте
    // его вектором с координатами (1,1).
    vector<Vector> vv = { Vector(1, 1), Vector(2, 4), Vector(4, 5) };

    cout << "\n\nvector of Vectors\n";
    for (int i = 0; i < vv.size(); i++)
        vv[i].Out();

    // Создайте вектор указателей на Vector и инициализируйте его адресами
    // объектов класса Vector
    Vector first(0, 0);
    Vector second(1, 3);
    Vector third(4, 4);
    vector<Vector*> vp;

    vp.push_back(&first);
    vp.push_back(&second);
    vp.push_back(&third);
    
    cout << "\n\nvector of pointers to Vector\n";

    for (int i = 0; i < vp.size(); i++)
        vp[i]->Out();

    // Научитесь пользоваться методом assign и операцией
    // присваивания = для контейнеров типа vector.
    vector<Vector*> vl;
    vl.assign(vp.begin(), vp.end());
    cout << "\n\nAfter assign\n";

    for (int i = 0; i < vl.size(); i++)
        vl[i]->Out();

    // Декларируйте новый вектор указателей на Vector и инициализируйте его
    // с помощью второй версии assign
    vector<Vector*> vpNew;
    vpNew.assign(vl.begin(), vl.end());

    cout << "\n\nNew vector after assign\n";
    for (int i = 0; i < vpNew.size(); i++)
        vpNew[i]->Out();


    /* На базе шаблона vector создание двухмерный массив и
     заполните его значениями разными способами.
     Первый вариант - прямоугольная матрица
     Второй вариант - ступенчатая матрица*/


    //========= Ступенчатая матрица
    vector<vector<double>> vdd;
    for (int i = 0; i < vdd.size(); i++)
        vdd[i] = vector<double>(i + 1, double(i));

    cout << "\n\n\tTest vector of vector<double>\n";
    for (int i = 0; i < vdd.size(); i++)
    {
        cout << endl;
        for (int j = 0; j < vdd[i].size(); j++)
            cout << vdd[i][j] << "  ";
    }
    

    
    vector<vector<double>> rectangularMatrix;
    int numRows = 3;
    int numCols = 4;

    // Инициализируем прямоугольную матрицу
    rectangularMatrix.resize(numRows);

    for (int i = 0; i < numRows; ++i) {
        rectangularMatrix[i].resize(numCols);
    }

    // Заполняем матрицу значениями
    double value = 1.0;
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            rectangularMatrix[i][j] = value++;
        }
    }

    //===================================
    // Простейшие действия с контейнерами
    //===================================
    //3б. Получение значения первого и последнего элементов последовательности.
    //Получение размера последовательности. Присваивание значений
    //элементов одной последовательности элементам другой - assign().

    //Создайте и проинициализируйте вектор из элементов char. Размер -
    //по желанию.
    vector<char> arr = { 'a', 'b', 'c', 'd' };

    //Создайте и проинициализируйте массив из элементов char. Размер -
    //по желанию.
    char cMas[] = { 'a', 'b', 'c', 'd', 'e', 'f' };

    //Получите значение первого элемента вектора ( front() )
    cout << arr.front() << endl;
    //Получите значение последнего элемента вектора ( back() )

    cout << arr.back() << endl;
    //Получите размер вектора
    cout << arr.size() << endl;

    //Присвойте вектору любой диапазон из значений массива cMas.
    arr.assign(cMas + 1, cMas + 3);

    //Проверьте размер вектора, первый и последний элементы.

    cout << arr.front() << endl;

    cout << arr.back() << endl;

    cout << arr.size() << endl;



    //3в. Доступ к произвольным элементам вектора с проверкой - at()
    //и без проверки - []
    //Создайте неинициализированный вектор из 8 элементов char - vChar2.
    //С помощью at() присвойте четным элементам вектора значения
    //элементов vChar1 из предыдущего задания,
    //а с помощью [] присвойте нечетным элементам вектора vChar2 значения
    //массива {'K','U','K','U'}.
    char vChar3[] = { 'K','U','K','U', 'U', 'U', 'U' };
    vector<char> vChar2(8);
    for (int i = 0; i < 8; i++) {
        if (i % 2 == 0 && i / 2 < arr.size()) {
            vChar2.at(i) = arr[i / 2];
        }
        else {
            vChar2[i] = vChar3[i];
        }
    }



    //Попробуйте "выйти" за границы вектора с помощью at() и
    //с помощью []. Обратите внимание: что происходит при
    //попытке обращения к несуществующему элементу в обоих случаях
//    char a = vChar3[20];
    try {
        char value = vChar2.at(30);
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }





    //3г.Добавьте в конец вектора vChar2  - букву Z (push_back()). Для
    //расширения кругозора можете ее сразу же и выкинуть (pop_back())
    vChar2.push_back('Z');
    vChar2.pop_back();



    //3д. Вставка-удаление элемента последовательности insert() - erase()
    //Очистка последовательности - clear()


    // Вставляем перед каждым элементом 'W'
    for (int i = 0; i < vChar2.size(); i += 2) {
        vChar2.insert(vChar2.begin() + i, 'W');
    }

    // Вставляем перед 5-ым элементом 'X'
    vChar2.insert(vChar2.begin() + 4, 3, 'X');

    // Вставляем перед 2-ым элементом 'aaabbbccc'
    std::string strToInsert = "aaabbbccc";
    vChar2.insert(vChar2.begin() + 1, strToInsert.begin() + 2, strToInsert.begin() + 6);

    // Удаляем с первого по десятый элементы
    if (vChar2.size() >= 10) {
        vChar2.erase(vChar2.begin(), vChar2.begin() + 10);
    }
    else {
        // Обработка случая, если вектор содержит менее 10 элементов
        std::cout << "Vector size is less than 10." << std::endl;
    }


    //Уничтожьте все элементы последовательности - clear()
    vChar2.clear();




    ///////////////////////////////////////////////////////////////////

        //Задание 4. Списки. Операции, характерные для списков.
        //Создайте два пустых списка из элементов Vector - ptList1 и
        //ptList2 доступ медл
    list<Vector> ptList1;
    list<Vector> ptList2;

    //Наполните оба списка значениями с помощью методов push_back(),
    //push_front, insrert()
    ptList1.push_back(Vector(1, 2));
    ptList1.push_back(Vector(0, 0));
    ptList1.push_front(Vector(1, 2));

    ptList2.push_back(Vector(1, 2));
    ptList2.push_back(Vector(0, 0));
    ptList2.push_front(Vector(1, 2));

    ptList1.insert(ptList1.begin(), 3, Vector(3, 4)); //вставляем три элемента со значением 3 перед началом быстрее rem

    //Отсортируйте списки - sort().

    ptList1.sort();
    ptList2.sort();

    //Подсказка: для того, чтобы работала сортировка, в классе Vector
    //должен быть переопределен оператор "<"



    //Объедините отсортированные списки - merge(). Посмотрите: что
    //при этом происходит со вторым списком.

    ptList1.merge(ptList2); // второй список обнуляется
    //Исключение элемента из списка - remove()
    //Исключите из списка элемент с определенным значением.
    //Подсказка: для этого необходимо также переопределить
    ptList1.remove(Vector(0, 0)); // ,быстрее

    ///////////////////////////////////////////////////////////////////

        //Задание 5. Стандартные алгоритмы.Подключите заголовочный файл
        // <algorithm>
        //5а. Выведите на экран элементы ptList1 из предыдущего
        //задания с помощью алгоритма for_each()
    std::for_each(ptList1.begin(), ptList1.end(), Print_Vector);

    //5б.С помощью алгоритма find() найдите итератор на элемент Vector с
    //определенным значением. С помощью алгоритма find_if() найдите
    //итератор на элемент, удовлетворяющий определенному условию,
    //например, обе координаты точки должны быть больше 2.
    //Подсказка: напишите функцию-предикат, которая проверяет условие
    //и возвращает boolean-значение (предикат может быть как глобальной
    //функцией, так и методом класса)
    list<Vector>::iterator result = std::find(ptList1.begin(), ptList1.end(), Vector(1, 2));

    //Создайте список из указателей на элеметы Vector. С помощью
    //алгоритма find_if() и предиката (можно использовать предикат -
    //метод класса Vector, определенный в предыдущем задании) найдите в
    //последовательности элемент, удовлетворяющий условию

    list<Vector>::iterator new_result = std::find_if(ptList1.begin(), ptList1.end(), isSumGreaterThanTwo);

    //5в. Создайте список элементов Vector. Наполните список
    //значениями. С помощью алгоритма replace() замените элемент
    //с определенным значением новым значением. С помощью алгоритма
    //replace_if() замените элемент, удовлетворяющий какому-либо
    //условию на определенное значение. Подсказка: условие
    //задается предикатом.

    std::replace(ptList1.begin(), ptList1.end(), Vector(0, 0), Vector(1, 1));
    std::replace_if(ptList1.begin(), ptList1.end(), isSumGreaterThanTwo, Vector(0, 0));

    //Сформировали значения элементов списка

      //5г. Создайте вектор строк (string). С помощью алгоритма count()
      //сосчитайте количество одинаковых строк. С помощью алгоритма
      //count_if() сосчитайте количество строк, начинающихся с заданной
      //буквы

    vector<string> array = { "ahello", "my", "name", "a", "a", "a", "ngsg" };
    int count_a = std::count(array.begin(), array.end(), "a");
    //5д. С помощью алгоритма count_if() сосчитайте количество строк,
    //которые совпадают с заданной строкой. Подсказка: смотри тему
    //объекты-функции
    int count_A = std::count_if(array.begin(), array.end(), starObjectWith("n"));
    cout << count_a << " " << count_A << endl;


    cout << " wasssssup\n\n ";
}

template<typename T> void Swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

void Print_Vector(Vector& other) {
    other.Out();
}


bool isSumGreaterThanTwo(const Vector& v) {
    return (v.x + v.y) > 2;
}

bool startsWithA(string s) {
    return s[0] == 'a' && !s.empty();
}
