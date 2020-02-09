#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#include<string>
using namespace std;

/*
职工的种类包括：正式职工和临时工。
定义一个基本的职工类，基本信息包括：编号、姓名、性别、年龄、家庭住址、基本职务工资。
*/

class employee {
private:
	int num = 0;             //职工编号
	string name = "";        //职工姓名
	string gender = "";      //性别
	int age = 0;             //年龄
	string address = "";     //家庭住址
	int wages = 0;           //基本职务工资
public:
	void setNum(int _num);
	void setName(string _name);
	void setGender(string _gender);
	void setAge(int _age);
	void setAddress(string _address);
	void setWages(int _wages);
	void set();
	int getNum();
	string getName();
	string getGender();
	int getAge();
	string getAddress();
	int getWages();
	employee();

};

/*派生出正式职工类，增加的属性包括：岗位津贴、养老金、住房公积金、所得税、医疗保险、实发工资*/
class fullTimeEmployee : public employee {
private:
	int moreMoney1 = 0;  //岗位津贴
	int moreMoney2 = 0;  //养老金
	int moreMoney3 = 0;  //住房公积金
	int moreMoney4 = 0;  //所得税
	int moreMoney5 = 0;  //医疗保险
	int sumMoney = 0;    //实发工资
public:
	void setMoney1(int _moreMoney1);
	void setMoney2(int _moreMoney2);
	void setMoney3(int _moreMoney3);
	void setMoney4(int _moreMoney4);
	void setMoney5(int _moreMoney5);
	void setSumMoney();
	void set();
	int getMoney1();
	int getMoney2();
	int getMoney3();
	int getMoney4();
	int getMoney5();
	int getSumMoney();
	fullTimeEmployee();
	fullTimeEmployee(int i);
};

/*临时工增加的属性包括：奖金、所得税、实发工资*/
class temporaryEmployee : public employee {
	int moreMoney1 = 0;   //奖金
	int moreMonry2 = 0;   //所得税
	int sumMoney = 0;     //实发工资
public:
	void setMoney1(int _moreMoney1);
	void setMoney2(int _moreMoney2);
	void setSumMoney();
	void set();
	int getMoney1();
	int getMoney2();
	int getSumMoney();
	temporaryEmployee();
	temporaryEmployee(int i);
};

#endif // !EMPLOYEE_H_

#pragma once