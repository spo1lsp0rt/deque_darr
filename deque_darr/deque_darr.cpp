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
	T* a{};
	size_t d_size{};

public:
	deque() = default;
	deque(const deque<T>& _deque) {
		*this = _deque;
	}
	deque(const size_t& _size, const T& val) {
		a = new T[_size];
		for (size_t i = 0; i < _size; i++) {
			a[i] = val;
		}
		d_size = _size;
	}
	deque(const size_t& _size) {
		a = new T[_size];
		for (size_t i = 0; i < _size; i++) {
			a[i] = 0;
		}
		d_size = _size;
	}
	~deque() {
		clear();
	}

	void assign(const size_t& _size, const T& val) {
		if (d_size) delete[] a;
		a = new T[_size];
		for (size_t i = 0; i < _size; i++) {
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

	size_t size() const {
		return d_size;
	}

	bool empty() const {
		return d_size == 0;
	}

	size_t begin() const {
		return 0;
	}

	size_t end() const {
		if (d_size) return d_size - 1;
		return 0;
	}

	void insert(const size_t& pos, const T& val) {
		if (d_size == 0) {
			d_size++;
			a = new T[d_size];
			a[0] = val;
		}
		else {
			d_size++;
			T* temp = new T[d_size];
			for (size_t i = 0; i < pos; i++) {
				temp[i] = a[i];
			}
			temp[pos] = val;
			for (size_t i = pos; i < d_size - 1; i++) {
				temp[i + 1] = a[i];
			}
			delete[] a;
			a = new T[d_size];
			for (size_t i = 0; i < d_size; i++) {
				a[i] = temp[i];
			}
			delete[] temp;
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
			for (size_t i = 0; i < d_size - 1; i++) {
				temp[i + 1] = a[i];
			}
			delete[] a;
			a = new T[d_size];
			for (size_t i = 0; i < d_size; i++) {
				a[i] = temp[i];
			}
			delete[] temp;
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
			for (size_t i = 0; i < d_size - 1; i++) {
				temp[i] = a[i];
			}
			delete[] a;
			a = new T[d_size];
			for (size_t i = 0; i < d_size; i++) {
				a[i] = temp[i];
			}
			delete[] temp;
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
			for (size_t i = 0; i < d_size; i++) {
				temp[i] = a[i + 1];
			}
			delete[] a;
			a = new T[d_size];
			for (size_t i = 0; i < d_size; i++) {
				a[i] = temp[i];
			}
			delete[] temp;
		}
	}

	void pop_back() {
		if (d_size == 0) {
			throw std::out_of_range("err: out of range");
		}
		else {
			d_size--;
			T* temp = new T[d_size];
			for (size_t i = 0; i < d_size; i++) {
				temp[i] = a[i];
			}
			delete[] a;
			a = new T[d_size];
			for (size_t i = 0; i < d_size; i++) {
				a[i] = temp[i];
			}
			delete[] temp;
		}
	}

	void clear() {
		if (d_size) {
			delete[] a;
			a = nullptr;
			d_size = 0;
		}
	}

	bool operator==(const deque<T>& _deque) {
		if (d_size != _deque.d_size) return false;
		else {
			for (size_t i = 0; i < d_size; i++) {
				if (a[i] != _deque.a[i]) return false;
			}
		}
		return true;
	}

	deque<T>& operator=(const deque<T>& _deque) {
		if (!(*this == _deque) && !(_deque.d_size == 0)) {
			if (d_size != 0) delete[] a;
			d_size = _deque.d_size;
			a = new T[d_size];
			for (size_t i = 0; i < d_size; i++) {
				a[i] = _deque.a[i];
			}
		}
		return *this;
	}

	T& operator[](const size_t& pos) {
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
	for (size_t i = dq.begin(); i <= dq.end(); i++) {
		cout << dq[i] << " ";
	}
	//при присваивании самого себя срабатывает проверка, данные не потеряются
	dq = dq;
	cout << endl;
	for (size_t i = dq.begin(); i <= dq.end(); i++) {
		cout << dq[i] << " ";
	}
	cout << endl;
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