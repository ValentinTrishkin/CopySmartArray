// CopySmartArray.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<algorithm>

class smart_array
{
public:	
	
	smart_array(int size)
	{
		size_ = size;
		arr = new int[size_];
	}
	smart_array& operator = (smart_array& copy)
	{
		if (&copy != this)
		{
			arr = copy.arr;
		}
		return *this;
	}
	smart_array(smart_array& copy)
	{
		arr = new int[copy.size_];
		for (int i = 0; i < copy.size_; i++)
		{
			arr[i] = copy.arr[i];
		}
		size_ = copy.size_;
	}
	
	void add_element(int num)
	{
		if (element < size_)
		{
			arr[element] = num;
			element += 1;
		}
		else (throw std::exception("Количество элементов больше количества элементов в массиве."));
	}
	int get_element(int index)
	{
		if (index >= size_ || index < 0)
		{
			throw std::exception("Некорректно указан индекс массива.");
		}
		return arr[index];
	}
	~smart_array() { delete[] arr; }
	
private:
	int size_ = 0;
	int* arr = nullptr;
	int element = 0;
};

int main()
{
	setlocale(LC_ALL, "Rus");
	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		smart_array new_array(2);
		new_array.add_element(44);
		new_array.add_element(34);

		arr = new_array;
		std::cout << arr.get_element(1) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	
	


}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
