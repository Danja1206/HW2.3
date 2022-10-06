#pragma once
#include <vector>
#include <iostream>
#include <optional>

using namespace std;

class Matrix
{
public:
	Matrix(istream& stream) : determinator(nullopt)
	{
		cout << "Введите размер матрицы: ";
		cin >> SIZE;

		matrix.reserve(SIZE);

		for (int i = 0; i < SIZE; i++)
		{
			matrix.push_back(vector<int32_t>());
			matrix[i].reserve(SIZE);
			for (int j = 0; j < SIZE; j++)
			{
				optional<int> a = cin.get();
				if (a) matrix[i].push_back(a.value());
				else
				{
					cout << endl;
					for (int ii = 0; ii <= i; ii++)
					{
						for (int jj = 0; jj < ((ii < i) ? SIZE : j); jj++)
						{
							cout << matrix[ii][jj] << "";
						}
						if (ii < i) cout << endl;
					}
					j--;
				}
			}
		}
		calculate();
	}
	
	void printMatrix()
	{
		for (auto& i : matrix)
			for (auto& j : i)
				cout << j << " ";
		cout << endl;
	};
	void printAnswer()
	{
		if (determinator)
			cout << "Определитель матрицы = " << determinator.value();
		else
			cout << "Не найден определитель";
		cout << endl;
	}
protected:
	Matrix(Matrix& prevMatrix, size_t& element_index) : determinator(nullopt), SIZE(prevMatrix.SIZE - 1)
	{
		matrix.reserve(SIZE);
		for (size_t i = 0; i < SIZE; i++)
		{
			matrix.push_back(std::vector<int32_t>());
			matrix[i].reserve(SIZE);
			for (size_t j = 0; j < prevMatrix.SIZE; j++)
			{
				if (element_index != j) matrix[i].push_back(prevMatrix.matrix[i + 1][j]);
			}
		}
		calculate();
	}
	void calculate()
	{
		switch (SIZE)
		{
		case 1:
			determinator = matrix[0][0];
		case 2:
			determinator = matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
			break;
		default:
			minors.reserve(SIZE);
			determinator = 0;
			for (size_t i = 0; i < SIZE; i++)
			{
				minors.push_back(Matrix(*this, i));
				determinator.emplace() = determinator.value() + matrix[0][i] * minors[i].determinator.value() * (i % 2 == 0 ? 1 : (-1));
			}
			break;
		}
	}
private:
	vector<vector<int>> matrix;
	int SIZE;
	optional<int> determinator;
	vector<Matrix> minors;
};