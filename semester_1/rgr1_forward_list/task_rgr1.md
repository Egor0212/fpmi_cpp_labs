# Расчетно-графическая работа №1.ООП. Односвязный список

Ознакомьтесь с классом `ForwardList` в файле [forward_list_impl.h](forward_list/forward_list_impl.h). Над каждым методом в комментариях описана суть его работы. Подумайте, какие поля будут в этом классе.

Обратите внимание на то, как и где объявлен класс `ForwardListIterator`, реализующий итератор для односвязного списка. Подробнее про _ForwardIterator_ можно почитать [здесь](https://en.cppreference.com/w/cpp/named_req/ForwardIterator).

> Подумайте, что из себя должен представлять константный итератор (`ConstIterator`)? Действительно ли он будет такой же, как и `ForwardListIterator`(см. файл [forward_list_impl.h](./forward_list/forward_list_impl.h))? Если нет, то чем он будет отличаться от `ForwardListIterator`? К этому вопросу мы ещё вернёмся в будущем.

Реализуйте сравнение (`operator=`) в классе `ForwardListIterator` в файле [forward_list_impl.h](./forward_list/forward_list_impl.h).

Реализуйте методы класса `ForwardList` в файле [forward_list_impl.cpp](forward_list/forward_list_impl.cpp) (не запрещается добавлять свои методы для решения каких либо задач или для удобства работы, если по названию и сигнатуре этих методов будет без комментариев понятно их действие).

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