# Расчетно-графическая работа №1.ООП. Односвязный список

Ознакомьтесь с классом `ForwardList` в файле [forward_list_impl.h](forward_list/forward_list_impl.h). Над каждым методом в комментариях описана суть его работы. Подумайте, какие поля будут в этом классе.

Реализуйте методы класса `ForwardList` в файле [forward_list_impl.cpp](forward_list/forward_list_impl.cpp) (не запрещается добавлять свои методы для решения каких либо задач или для удобства работы, если по названию и сигнатуре этих методов будет без комментариев понятно их действие).

> Обратите внимание на то, как и где объявлен класс `ForwardListIterator`, реализующий итератор для односвязного списка. Подробнее про _ForwardIterator_ можно почитать [здесь](https://en.cppreference.com/w/cpp/named_req/ForwardIterator).

Дополните методы класса `ForwardListIterator` и методы `begin()` и `end()` класса `ForwardList` в заголовочном файле (обратите внимание, что их два вида: константные и неконстантные).

> Подумайте, какой тип должны возвращать константные верcии методов `begin()` и `end()`? Действительно ли это будет `ForwardListIterator`(см. файл [forward_list_impl.h](./forward_list/forward_list_impl.h))? К этому вопросу мы ещё вернёмся в будущем.

Ваша реализация должна пройти все тесты. Они находятся в файле [test.cpp](forward_list/test.cpp). Программа собирается и запускается аналогично лабораторной с классом `Vector` (ниже приведу просто команды, подробнее можно почитать [тут](../lab7_oop/README.md)):
```shell
# Из директории 'rgr1_forward_list/'
# (не из корневой папки!!!!)
mkdir build
cd build
cmake ..
make test_forward_list
./test_forward_list

# Тестирование с санитайзерами
# Из директории 'rgr1_forward_list/'
mkdir adan_build
cd asan_build
cmake -DCMAKE_BUILD_TYPE=ASAN ..
make test_forward_list
./test_forward_list
```