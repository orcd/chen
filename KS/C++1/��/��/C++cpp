// 编译不过一律0分，测试程序写清楚注释，每一个函数的功能要能实现才有分
1、设计一个学生类，包括学号、姓名、成绩，并设计接口函数用来输出这些学生数据并计算平均分。（分文件编程）		25'
	a) 姓名不能是 char *,  要求是MyString的对象成员
	b) 不能使用全局变量，用static成员代替
	c) 成员变量应该是私有，通过公有接口访问
	d) 编写main函数进行测试：
	输出如：
	学号 	姓名    成绩
	1		张XX		98
	2		王XX		90
	3		XXX		89
	平均成绩：	XX
	
	
2、从1中的学生类派生出一个研究生类(Graduate)，研究生比学生多出一个导师信息（导师名），	（分文件编程）		15'
并设计接口函数，用来显示研究生信息，包括 学号、姓名、成绩、导师信息。

	并编写main函数进行测试：
	输出如：
	学号 	姓名   	成绩		导师
	1	  	张XX		98		王XX
	2		王XX		90		XXX
	3		XXX		89		XXX
	平均成绩：	XX


3、编写一个C++程序, 计算程序员( programmer )工资，programmer设置为抽象接口类。								20'
	class programmer
	{
	public:
		virtual int getSal() = 0;
	};

	1）程序员属性拥有：工资，年龄，名字(int sal; int age; char name[128];)
	2）要求能计算出初级程序员 ( junior_programmer ) 中级程序员 ( mid_programmer ) 高级程序员 ( adv_programmer ) 的工资
	2）要求利用抽象类统一界面，方便程序的扩展，比如：新增计算 架构师 ( architect ) 的工资


4、完成字符串类的封装																						30'
	class MyString
	{
	public:
		//构造和析构
		MyString(int tmpLen = 0);
		MyString(const char *p);
		MyString(const MyString &obj);
		~MyString();

		//普通成员函数
		void display() const;
		char * c_str() const;
		int length(); //获取字符串长度

		//运算符重载
		// >> << 重载，友元函数
		friend istream &operator>>(istream &cin, MyString &obj);
		friend ostream &operator<<(ostream &cout, MyString &obj);

		// =, [] 重载
		MyString & operator=(const MyString &obj);
		MyString & operator=(const char *p);
		char &operator[](int index);

		// ==, != 重载
		bool operator==(const char *p);
		bool operator!=(const char *p);
		bool operator==(MyString &obj);
		bool operator!=(MyString &obj);

	private:
		char *str;
		int len;
	};
	
4、算法实现  {0，1，2，3，4，5，6，7，8，9，10，11，.......  20}  请打印所以的子集 ，并写入文件 			 10'
	

	
	