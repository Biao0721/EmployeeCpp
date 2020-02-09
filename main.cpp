#include<iostream>
#include<stdio.h>
#include"employee.h"
#include"function.h"
#include"print.h"
using namespace std;

int main() {
	listpoint1 *temp1, *head1;
	listpoint2 *temp2, *head2;

	temp1 = head1 = (listpoint1*)malloc(sizeof(listpoint1));
	temp2 = head2 = (listpoint2*)malloc(sizeof(listpoint2));

	while (true) {
		readCsv(temp1);
		readCsv(temp2);

		printFunction();
		
		int flag;
		cin >> flag;
		
		system("cls");

		if (flag == 8) {
			exit(1);
		}

		int i, j;
		switch (flag)
		{
		case 1://匹配数据
			printFunction1();
			cin >> i;
			system("cls");
			if (i == 1 || i == 2) {
				printFunction1(head1, i);
				printFunction1(head2, i);
			}
			else
			{
				cout << "                                                       输入错误，请重新输入\n";
			}
			cout << "                                                 ";
			system("pause");
			break;
		case 2://按照实发工资排序输出
			printFunction2(head1, head2);
			cout << "                                                 ";
			system("pause");
			break;
		case 3://增加新员工
			printFunction3();
			cin >> i;
			if (i == 1) {
				addEmployee(temp1);
			}
			else if (i == 2) {
				addEmployee(temp2);
			}
			else {
				cout << "                                                       输入错误，请重新输入\n";
			}
			break;
		case 4://查询数据
			printFunction4();
			cin >> i;//选择你要查询的员工类型
			system("cls");
			printFunction4(" ");
			cin >> j;//选择你的查询方式
			printEmplpoyee(i, j, head1, head2);
			cout << "\n                                                   ";
			system("pause");
			break;
		case 5://修改记录
			printFunction4();
			cin >> i;
			system("cls");
			changeEmplpoyee(i, head1, head2);
			cout << "\n                                                   ";
			system("pause");
			break;
		case 6://删除记录
			printFunction4();
			cin >> i;//要选择删除的员工类型
			printFunction6();
			cin >> j;//要选择删除的方式
			deleteEmplpoyee(i, j, head1, head2);
			cout << "\n                                                   ";
			system("pause");
			break;
		case 7:
			cout << "                                **********************************************************\n";
			cout << endl;
			cout << "                                                   正式员工：" << endl;
			printEmployees(head1);
			cout << endl;
			cout << "                                **********************************************************\n" << endl;
			cout << "                                                   临时员工：" << endl;
			printEmployees(head2);
			cout << endl;
			cout << "                                **********************************************************\n";
			cout << "                                                   ";
			system("pause");
			break;
		default:
			cout << "                                                       输入错误，请重新输入\n";
			break;
		}
		system("cls");
		saveEmployee(head1);
		saveEmployee(head2);
	}

	return 0;
}