/*
 Дек(deque) — это сокращенная фраза «double - ended - queue», что, в переводе с английского, означает — двусторонняя очередь.
 Контейнер Дек очень похож на контейнер — Вектор, также как и Вектора, Деки являются динамическими массивами.
 Разница между Вектором и Деком состоит лишь в том, что в деках динамический массив открыт с двух сторон.
 Это и позволяет очень быстро добавлять новые элементы как в конец так и в начало контейнера.

 Ниже представлена программный код реализации дека на базе динамического массива.
 Удалось реализовать методы:
 assign, front, back, size, empty, begin, end, insert(pos,val),
 push_front, push_back, pop_front, pop_back, clear
*/
#include <iostream>

template <typename T>
class deque
{
private:
	T *a;
	unsigned int d_size;

public:
	deque(const unsigned int& _size, const T& val) {
		a = new T[_size];
		for (unsigned int i = 0; i < _size; i++) {
			a[i] = val;
		}
		d_size = _size;
	}
	deque(const unsigned int& _size) {
		a = new T[_size];
		for (unsigned int i = 0; i < _size; i++) {
			a[i] = NULL;
		}
		d_size = _size;
	}

	void assign(const unsigned int& _size, const T& val) {
		if (d_size != 0) delete a;
		a = new T[_size];
		for (unsigned int i = 0; i < _size; i++) {
			a[i] = val;
		}
		d_size = _size;
	}

	T& front() {
		return a[0];
	}

	T& back() {
		return a[d_size - 1];
	}

	unsigned int size() {
		return d_size;
	}

	bool empty() {
		return d_size == 0;
	}

	unsigned int begin() const {
		return 0;
	}

	unsigned int end() const {
		return d_size - 1;
	}

	void insert(const unsigned int& pos, const T& val) {
		if (d_size == 0) {
			d_size++;
			a = new T[d_size];
			a[0] = val;
		}
		else {
			d_size++;
			T* temp = new T[d_size];
			for (unsigned int i = 0; i < pos; i++) {
				temp[i] = a[i];
			}
			temp[pos] = val;
			for (unsigned int i = pos; i < d_size - 1; i++) {
				temp[i + 1] = a[i];
			}
			delete a;
			a = new T[d_size];
			for (unsigned int i = 0; i < d_size; i++) {
				a[i] = temp[i];
			}
			delete temp;
		}
	}

	void push_front(const T& val) {
		if (d_size == 0) {
			d_size++;
			a = new T[d_size];
			a[0] = val;
		}
		else {
			d_size++;
			T* temp = new T[d_size];
			temp[0] = val;
			for (unsigned int i = 0; i < d_size - 1; i++) {
				temp[i + 1] = a[i];
			}
			delete a;
			a = new T[d_size];
			for (unsigned int i = 0; i < d_size; i++) {
				a[i] = temp[i];
			}
			delete temp;
		}
	}

	void push_back(const T& val) {
		if (d_size == 0) {
			d_size++;
			a = new T[d_size];
			a[0] = val;
		}
		else {
			d_size++;
			T* temp = new T[d_size];
			for (unsigned int i = 0; i < d_size - 1; i++) {
				temp[i] = a[i];
			}
			delete a;
			a = new T[d_size];
			for (unsigned int i = 0; i < d_size; i++) {
				a[i] = temp[i];
			}
			delete temp;
			a[d_size - 1] = val;
		}
	}

	void pop_front() {
		if (d_size == 0) {
			throw std::out_of_range("err: out of range");
		}
		else {
			d_size--;
			T* temp = new T[d_size];
			for (unsigned int i = 0; i < d_size; i++) {
				temp[i] = a[i + 1];
			}
			delete a;
			a = new T[d_size];
			for (unsigned int i = 0; i < d_size; i++) {
				a[i] = temp[i];
			}
			delete temp;
		}
	}

	void pop_back() {
		if (d_size == 0) {
			throw std::out_of_range("err: out of range");
		}
		else {
			d_size--;
			T* temp = new T[d_size];
			for (int i = d_size - 1; i >= 0; i--) {
				temp[i] = a[i];
			}
			delete a;
			a = new T[d_size];
			for (unsigned int i = 0; i < d_size; i++) {
				a[i] = temp[i];
			}
			delete temp;
		}
	}

	void clear() {
		delete a;
		d_size = 0;
	}

	T& operator[](const unsigned int& pos) {
		if (pos >= d_size) {
			throw std::out_of_range("err: out of range");
		}
		else return a[pos];
	}
};

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	deque<int> dq(3, 1);
	//изменили первое значение дека вызовом front()
	dq.front() = 777;
	//изменили промежуточное значение дека вызовом оператора []
	dq[1] = 888;
	//изменили последнее значение дека вызовом back()
	dq.back() = 999;
	cout << "Первое значение дека: " << dq.front() << endl;
	cout << "Промежуточное значение дека: " << dq[1] << endl;
	cout << "Последнее значение дека: " << dq.back() << endl;

	cout << "Пуст ли дек? Ответ: " << dq.empty() << endl;
	dq.clear();
	cout << "Очистили дек. Пуст ли дек? Ответ: " << dq.empty() << endl;

	dq.assign(5, 9);
	cout << "Воспользовались assign(). \nВывод дека:  ";
	for (size_t i = dq.begin(); i <= dq.end(); i++) {
		cout << dq[i] << " ";
	}
	cout << endl << "Размер дека: " << dq.size() << endl;
	dq.insert(dq.begin(), 0);
	cout << endl << "Воспользовались insert() для begin(). \nВывод дека:  ";
	for (size_t i = dq.begin(); i <= dq.end(); i++) {
		cout << dq[i] << " ";
	}
	dq.pop_back();
	dq.pop_front();
	cout << endl << "Воспользовались pop_back() и pop_front(). \nВывод дека:  ";
	for (size_t i = dq.begin(); i <= dq.end(); i++) {
		cout << dq[i] << " ";
	}
	dq.push_back(-5);
	dq.push_front(-5);
	cout << endl << "Воспользовались push_back() и push_front(). \nВывод дека:  ";
	for (size_t i = dq.begin(); i <= dq.end(); i++) {
		cout << dq[i] << " ";
	}
	cout << endl;
	return 0;
}