#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<list>
#include<functional>
#include<algorithm>
#include<numeric>
using namespace std;
//int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 99 };
//要求：
//（1）将ia复制到一个vector容器vec中和一个list容器中lst中。
//（2）将vec容器中的奇数值元素删除。
//（3）使用内置算法(accumulate)计算vec窗器所有元素的和。
//（4）使用内置算法(count_if)计算lst容器中大于5的元素的个数。

bool greaterThan5(int val)
{
	return val > 5;
}
void test01()
{
	int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 99 };
	//(1)将ia复制到一个vector容器vec中和一个list容器中lst中。
	vector<int> vec(ia, ia + sizeof(ia) / sizeof(int)); ////将v[begin(), end())区间中的元素拷贝给本身。
	list<int>lst(ia, ia + sizeof(ia) / sizeof(int));
	//遍历，查看复制结果
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << ",";
	}
	cout << endl;
	//遍历链表,查看结果
	for (list<int>::iterator it = lst.begin(); it != lst.end(); it++)
	{
		cout << *it << ",";
	}
	cout << endl;
	cout << ".-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-." << endl;
	//（2）将vec容器中的奇数值元素删除。
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		if (*it % 2 != 0)//是奇数就删除，然后再重头遍历
		{
			vec.erase(it);
			it = vec.begin();
		}
	}
	if (*(vec.begin()) % 2 != 0)//再检查一下首个元素是否为奇数，是的话就删除
	{
		vec.erase(vec.begin());
	}
	cout << endl;
	//遍历，检查删除结果
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << ",";
	}
	cout << endl;

	//（3）使用内置算法(accumulate)计算vec窗器所有元素的和。
	int sum = accumulate(vec.begin(), vec.end(), 0);// 计算容器元素累计总和(容器开始迭代器,容器结束迭代器,累加值)
	cout << "accumulate:" << sum << endl;

	//（4）使用内置算法(count_if)计算lst容器中大于5的元素的个数。
	int n = count_if(lst.begin(), lst.end(), greaterThan5); //统计元素出现次数(容器开始迭代器,容器结束迭代器,谓词)
	cout << "大于5的元素个数:" << n << endl;
}
int main()
{
	test01();

	system("pause");
	return EXIT_SUCCESS;
}