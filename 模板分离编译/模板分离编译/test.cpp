#define _CRT_SECURE_NO_WARNINGS

#include"vector.h"

int main()
{
	cdc::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
	cout << endl;

	return 0;
}























