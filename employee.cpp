#include<iostream>
#include<fstream> 
#include<stdio.h>
#include"employee.h"
#include"function.h"
using namespace std;

employee::employee() {}
//设置基类参数
void employee::setNum(int _num) {
	num = _num;
}
void employee::setName(string _name) {
	name = _name;
}
void employee::setGender(string _gender) {
	gender = _gender;
}
void employee::setAge(int _age) {
	age = _age;
}
void employee::setAddress(string _address) {
	address = _address;
}
void employee::setWages(int _wages) {
	wages = _wages;
}
void employee::set() {
	int _num, _age, _wages;
	string _name, _gender, _address;
	cout << "\n                                                      输入员工编号：";
	cin >> _num;
	cout << "\n                                                      输入职工姓名：";
	cin >> _name;
	cout << "\n                                                      输入职工性别：";
	cin >> _gender;
	cout << "\n                                                      输入职工年龄：";
	cin >> _age;
	cout << "\n                                                      输入家庭住址：";
	cin >> _address;
	cout << "\n                                                      输入基本工资：";
	cin >> _wages;
	employee::setNum(_num);
	employee::setName(_name);
	employee::setGender(_gender);
	employee::setAge(_age);
	employee::setAddress(_address);
	employee::setWages(_wages);
}
//获得基类里的参数
int employee::getNum() {
	return num;
}
string employee::getName() {
	return name;
}
string employee::getGender() {
	return gender;
}
int employee::getAge() {
	return age;
}
string employee::getAddress() {
	return address;
}
int employee::getWages() {
	return wages;
}


fullTimeEmployee::fullTimeEmployee() {
	employee::set();
	fullTimeEmployee::set();
	writeCsv(*this);
}
fullTimeEmployee::fullTimeEmployee(int i) {}
//设置参数
void fullTimeEmployee::setMoney1(int _moreMoney1) {
	moreMoney1 = _moreMoney1;
}
void fullTimeEmployee::setMoney2(int _moreMoney2) {
	moreMoney2 = _moreMoney2;
}
void fullTimeEmployee::setMoney3(int _moreMoney3) {
	moreMoney3 = _moreMoney3;
}
void fullTimeEmployee::setMoney4(int _moreMoney4) {
	moreMoney4 = _moreMoney4;
}
void fullTimeEmployee::setMoney5(int _moreMoney5) {
	moreMoney5 = _moreMoney5;
}
void fullTimeEmployee::setSumMoney() {
	//实发工资=基本职务工资+岗位津贴-养老金-住房公积金-所得税-医疗保险-所得税
	sumMoney = getWages() + moreMoney1 - moreMoney2 - moreMoney3 - moreMoney4 - moreMoney5;
}
void fullTimeEmployee::set() {
	int money;

	cout << "\n                                                      输入岗位津贴：";
	cin >> money;
	fullTimeEmployee::setMoney1(money);
	cout << "\n                                                      输入其养老金：";
	cin >> money;
	fullTimeEmployee::setMoney2(money);
	cout << "\n                                                      输入住房公积金：";
	cin >> money;
	fullTimeEmployee::setMoney3(money);
	cout << "\n                                                      输入其所得税：";
	cin >> money;
	fullTimeEmployee::setMoney4(money);
	cout << "\n                                                      输入医疗保险：";
	cin >> money;
	fullTimeEmployee::setMoney5(money);
	system("cls");
	fullTimeEmployee::setSumMoney();
}
//获得参数
int fullTimeEmployee::getMoney1() {
	return moreMoney1;
}
int fullTimeEmployee::getMoney2() {
	return moreMoney2;
}
int fullTimeEmployee::getMoney3() {
	return moreMoney3;
}
int fullTimeEmployee::getMoney4() {
	return moreMoney4;
}
int fullTimeEmployee::getMoney5() {
	return moreMoney5;
}
int fullTimeEmployee::getSumMoney() {
	return sumMoney;
}


temporaryEmployee::temporaryEmployee() {
	employee::set();
	temporaryEmployee::set();
	writeCsv(*this);
}
temporaryEmployee::temporaryEmployee(int i) {}
//设置参数
void temporaryEmployee::setMoney1(int _moreMoney1) {
	moreMoney1 = _moreMoney1;
}
void temporaryEmployee::setMoney2(int _moreMoney2) {
	moreMonry2 = _moreMoney2;
}
void temporaryEmployee::setSumMoney() {
	//实发工资=基本职务工资+奖金-所得税
	sumMoney = getWages() + moreMoney1 - moreMonry2;
}
void temporaryEmployee::set() {
	int money;

	cout << "\n                                                      输入所得奖金：";
	cin >> money;
	temporaryEmployee::setMoney1(money);
	cout << "\n                                                      输入其所得税：";
	cin >> money;
	temporaryEmployee::setMoney2(money);
	system("cls");
	temporaryEmployee::setSumMoney();
}
//获得参数
int temporaryEmployee::getMoney1() {
	return moreMoney1;
}
int temporaryEmployee::getMoney2() {
	return moreMonry2;
}
int temporaryEmployee::getSumMoney() {
	return sumMoney;
}
