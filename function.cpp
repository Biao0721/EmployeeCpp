#include<iostream>
#include<stdio.h>
#include<fstream> 
#include<vector>
#include<sstream> 
#include<string>
#include"function.h"
#include"employee.h"
#include"print.h"
using namespace std;

void addEmployee(listpoint1 *head) {
	while (head->next != NULL) {
		head = head->next;
	}
	listpoint1 *flag = (listpoint1*)malloc(sizeof(listpoint1));
	head->next = flag;
	flag->last = head;
	flag->next = NULL;
	flag->fireEmployee = false;
	flag->e = new fullTimeEmployee();
	head = flag;
}
void addEmployee(listpoint2 *head) {
	while (head->next != NULL) {
		head = head->next;
	}
	listpoint2 *flag = (listpoint2*)malloc(sizeof(listpoint2));
	head->next = flag;
	flag->last = head;
	flag->next = NULL;
	flag->fireEmployee = false;
	flag->e = new temporaryEmployee();
	head = flag;
}

void writeCsv(fullTimeEmployee e){
	ofstream outFile;
	outFile.open("C:\\Users\\87776\\Desktop\\fullTimeEmployee.csv", ios::app);
	outFile << e.getNum() << "," << e.getName() << "," << e.getGender() << "," << e.getAge() << "," << e.getAddress() << "," << e.getWages() << ","
		<< e.getMoney1() << "," << e.getMoney2() << "," << e.getMoney3() << "," << e.getMoney4() << "," << e.getMoney5() << "," << e.getSumMoney() << endl;
	outFile.close();
}
void writeCsv(temporaryEmployee e) {
	ofstream outFile;
	outFile.open("C:\\Users\\87776\\Desktop\\temporaryEmployee.csv", ios::app);
	outFile << e.getNum() << "," << e.getName() << "," << e.getGender() << "," << e.getAge() << "," << e.getAddress() << "," << e.getWages() << ","
		<< e.getMoney1() << "," << e.getMoney2() << "," << e.getSumMoney() << endl;
	outFile.close();
}

void readCsv(listpoint1 *temp) {
	temp->last = NULL;
	temp->next = NULL;
	vector<vector<string>> strArray;

	//读取正式员工
	ifstream inFile("C:\\Users\\87776\\Desktop\\fullTimeEmployee.csv", ios::in||ios::out);
	string lineStr;
	
	while (getline(inFile, lineStr)) {
		stringstream ss(lineStr);       //读取csv的一行数据并全部存入ss中
		string str;
		vector<string> lineArray;
		while (getline(ss, str, ','))
			lineArray.push_back(str);   //一行数据以vector保存
		strArray.push_back(lineArray);  //每一行vector存入strArray中
	}

	if (strArray.size() <= 1) {
	}
	else {
		for (int i = 1; i < strArray.size(); i++) {
			listpoint1 *flag = (listpoint1*)malloc(sizeof(listpoint1));
			fullTimeEmployee *employee = new fullTimeEmployee(0);
			employee->setNum(stoi(strArray[i][0]));
			employee->setName(strArray[i][1]);
			employee->setGender(strArray[i][2]);
			employee->setAge(stoi(strArray[i][3]));
			employee->setAddress(strArray[i][4]);
			employee->setWages(stoi(strArray[i][5]));
			employee->setMoney1(stoi(strArray[i][6]));
			employee->setMoney2(stoi(strArray[i][7]));
			employee->setMoney3(stoi(strArray[i][8]));
			employee->setMoney4(stoi(strArray[i][9]));
			employee->setMoney5(stoi(strArray[i][10]));
			employee->setSumMoney();
			flag->e = employee;
			if (flag->e->getNum() < 0) {
				flag->fireEmployee = true;
			}
			else {
				flag->fireEmployee = false;
			}
			flag->last = temp;
			flag->next = NULL;
			temp->next = flag;
			temp = flag;
		}
		update(temp);
	}
	inFile.close();
}
void readCsv(listpoint2 *temp) {
	temp->last = NULL;
	temp->next = NULL;
	vector<vector<string>> strArray;

	//读取临时员工
	ifstream inFile("C:\\Users\\87776\\Desktop\\temporaryEmployee.csv", ios::in);
	string lineStr;

	while (getline(inFile, lineStr)) {
		stringstream ss(lineStr);       //读取csv的一行数据并全部存入ss中
		string str;
		vector<string> lineArray;
		while (getline(ss, str, ','))
			lineArray.push_back(str);   //一行数据以vector保存
		strArray.push_back(lineArray);  //每一行vector存入strArray中
	}

	if (strArray.size() <= 1) {
	}
	else {
		for (int i = 1; i < strArray.size(); i++) {
			listpoint2 *flag = (listpoint2*)malloc(sizeof(listpoint2));
			temporaryEmployee *employee = new temporaryEmployee(0);
			employee->setNum(stoi(strArray[i][0]));
			employee->setName(strArray[i][1]);
			employee->setGender(strArray[i][2]);
			employee->setAge(stoi(strArray[i][3]));
			employee->setAddress(strArray[i][4]);
			employee->setWages(stoi(strArray[i][5]));
			employee->setMoney1(stoi(strArray[i][6]));
			employee->setMoney2(stoi(strArray[i][7]));
 			employee->setSumMoney();
			flag->e = employee;
			if (flag->e->getNum() < 0) {
				flag->fireEmployee = true;
			}
			else {
				flag->fireEmployee = false;
			}
			flag->last = temp;
			flag->next = NULL;
			temp->next = flag;
			temp = flag;
		}
		update(temp);
	}
	inFile.close();
}

void update(listpoint1 *temp) {
	listpoint1 *p = (listpoint1*)malloc(sizeof(listpoint1*));
	listpoint1 *q = (listpoint1*)malloc(sizeof(listpoint1*));
	listpoint1 *flag = (listpoint1*)malloc(sizeof(listpoint1*));
	listpoint1 *note = p;

	int i, j;
	for (p = temp; p->last; p = p->last) {
		for (q = p->last; q->last; q = q->last) {
			i = p->e->getSumMoney();
			j = q->e->getSumMoney();
			if (i < j) {
				flag->e = p->e;
				p->e = q->e;
				q->e = flag->e;
			}
		}
	}


}
void update(listpoint2 *temp) {
	listpoint2 *p = (listpoint2*)malloc(sizeof(listpoint2*));
	listpoint2 *q = (listpoint2*)malloc(sizeof(listpoint2*));
	listpoint2 *flag = (listpoint2*)malloc(sizeof(listpoint2*));

	int i, j;
	for (p = temp; p->last; p = p->last) {
		for (q = p->last; q->last; q = q->last) {
			i = p->e->getSumMoney();
			j = q->e->getSumMoney();
			if (i < j) {
				flag->e = p->e;
				p->e = q->e;
				q->e = flag->e;
			}
		}
	}
}

void printWages(listpoint1 *temp, int i) {
	listpoint1 *flag = temp->next;
	int num = 1;
	int sum = 0;
	for (; flag; flag = flag->next) {
		if (flag->fireEmployee) {
			continue;
		}
		sum += flag->e->getSumMoney();
		num++;
	}
	num--;
	if (i == 1) {
		cout << "                                **********************************************************\n\n";
		cout << "                                               正式员工的总工资为：" << sum << endl;
		cout << "\n                                **********************************************************\n\n";
	}
	else{
		cout << "                                **********************************************************\n\n";
		cout << "                                               正式员工的平均工资为：" << (sum / num) << endl;
		cout << "\n                                **********************************************************\n\n";
	}
}
void printWages(listpoint2 *temp, int i) {
	listpoint2 *flag = temp->next;
	int num = 1;
	int sum = 0;
	for (; flag; flag = flag->next) {
		if (flag->fireEmployee) {
			continue;
		}
		sum += flag->e->getSumMoney();
		num++;
	}
	num--;
	if (i == 1) {
		cout << "                                **********************************************************\n\n";
		cout << "                                               临时员工的总工资为：" << sum << endl;
		cout << "\n                                **********************************************************\n\n";
	}
	else {
		cout << "                                **********************************************************\n\n";
		cout << "                                               临时员工的平均工资为：" << (sum / num) << endl;
		cout << "\n                                **********************************************************\n\n";
	}
}

void printEmployee(listpoint1 *temp) {
	listpoint1 *flag = temp->next;
	for (; flag; flag = flag->next) {
		if (flag->fireEmployee) {
			continue;
		}
		cout << "                                            "<< flag->e->getName() << " " << flag->e->getSumMoney() << endl;
	}
}
void printEmployee(listpoint2 *temp) {
	listpoint2 *flag = temp->next;
	for (; flag; flag = flag->next) {
		if (flag->fireEmployee) {
			continue;
		}
		cout << "                                            " << flag->e->getName() << " " << flag->e->getSumMoney() << endl;
	}
}

listpoint1* findEmplpoyee(listpoint1 *head, int i) {
	listpoint1 *temp = head->next;
	string name;

	switch (i)
	{
	case 1:
		int num;
		cout << "                                                   请输入编号：";
		cin >> num;
		for (; temp; temp = temp->next) {
			if (abs(temp->e->getNum()) == num) {
				return temp;
			}
		}
		break;
	case 2:
		cout << "                                                   请输入姓名：";
		cin >> name;
		for (; temp; temp = temp->next) {
			if (temp->e->getName() == name) {
				return temp;
			}
		}
		break;
	case 3:
		int money;
		cout << "                                                   请输入工资：";
		cin >> money;
		for (; temp; temp = temp->next) {
			if (temp->e->getSumMoney() == money) {
				return temp;
			}
		}
		break;
	default:
		cout << "                                                   输入格式有误，请重新输入";
		break;
	}

	return NULL;
}
listpoint2* findEmplpoyee(listpoint2 *head, int i) {
	listpoint2 *temp = head->next;
	string name;

	switch (i)
	{
	case 1:
		int num;
		cout << "                                                   请输入编号：";
		cin >> num;
		for (; temp; temp = temp->next) {
			if (abs(temp->e->getNum()) == num) {
				return temp;
			}
		}
		break;
	case 2:
		cout << "                                                   请输入姓名：";
		cin >> name;
		for (; temp; temp = temp->next) {
			if (temp->e->getName() == name) {
				return temp;
			}
		}
		break;
	case 3:
		int money;
		cout << "                                                   请输入工资：";
		cin >> money; 
		for (; temp; temp = temp->next) {
			if (temp->e->getSumMoney() == money) {
				return temp;
			}
		}
		break;
	default:
		cout << "                                                   输入格式有误，请重新输入";
		break;
	}

	return NULL;
}

void printEmplpoyee(int i, int j, listpoint1 *head1, listpoint2 *head2) {
	if (i == 1) {
		listpoint1 *flag = findEmplpoyee(head1, j);
		if (flag == NULL) {
			cout << "                                                   未找到目标职员或目标以全部输出";
		}
		else{
			print(flag);
		}
		if (j == 3 && flag->next) {
			printEmplpoyee(1, 3, flag, head2);
		}
	}
	else if(i == 2){
		listpoint2 *flag = findEmplpoyee(head2, j);
		if (flag == NULL) {
			cout << "                                                   未找到目标职员或目标以全部输出";
		}
		else {
			print(flag);
		}
		if (j == 3 && flag->next) {
			printEmplpoyee(1, 3, head1, flag);
		}
	}
	else{
		cout << "                                                   输入员工类型有误";
	}
}

void print(listpoint1 *flag) {
	cout << "                                                   编号：" << abs(flag->e->getNum()) << endl;
	cout << "                                                   姓名：" << flag->e->getName() << endl;
	cout << "                                                   性别：" << flag->e->getGender() << endl;
	cout << "                                                   年龄：" << flag->e->getAge() << endl;
	cout << "                                                   家庭住址：" << flag->e->getAddress() << endl;
	cout << "                                                   实发工资：" << flag->e->getSumMoney() << endl << endl;

}
void print(listpoint2 *flag) {
	cout << "                                                   编号：" << abs(flag->e->getNum()) << endl;
	cout << "                                                   姓名：" << flag->e->getName() << endl;
	cout << "                                                   性别：" << flag->e->getGender() << endl;
	cout << "                                                   年龄：" << flag->e->getAge() << endl;
	cout << "                                                   家庭住址：" << flag->e->getAddress() << endl;
	cout << "                                                   实发工资：" << flag->e->getSumMoney() << endl << endl;
}

void printEmployees(listpoint1 *head) {
	listpoint1 *temp = head->next;
	for (; temp; temp = temp->next) {
		if (temp->fireEmployee) {
			continue;
		}
		cout << endl;
		print(temp);
	}
}
void printEmployees(listpoint2 *head) {
	listpoint2 *temp = head->next;
	for (; temp; temp = temp->next) {
		if (temp->fireEmployee) {
			continue;
		}
		cout << endl;
		print(temp);
	}
}


void changeEmplpoyee(int i, listpoint1 *head1, listpoint2 *head2) {
	int j;//选择要修改数据
	string judge;
	int x;
	string y;

	if (i == 1) {
		listpoint1 *flag = findEmplpoyee(head1, 1);
		print(flag);
		printFunction5(head1);
		cin >> j;

		switch (j)
		{
		case 1:
			cout << "                                                   原编号：" << flag->e->getNum() << endl;
			cout << "                                                   修改编号：";
			cin >> x;
			cout << "                                                   是否确认修改(是、否）";
			cin >> judge;
			if (judge == "是") {
				flag->e->setNum(x);
			}
			break;
		case 2:
			cout << "                                                   原姓名：" << flag->e->getName() << endl;
			cout << "                                                   修改姓名：";
			cin >> y;
			cout << "                                                   是否确认修改(是、否）";
			cin >> judge;
			if (judge == "是") {
				flag->e->setName(y);
			}
			break;
		case 3:
			cout << "                                                   原性别：" << flag->e->getGender() << endl;
			cout << "                                                   修改性别：";
			cin >> y;
			cout << "                                                   是否确认修改(是、否）";
			cin >> judge;
			if (judge == "是") {
				flag->e->setGender(y);
			}
			break;
		case 4:
			cout << "                                                   原年龄：" << flag->e->getAge() << endl;
			cout << "                                                   修改年龄：";
			cin >> x;
			cout << "                                                   是否确认修改(是、否）";
			cin >> judge;
			if (judge == "是") {
				flag->e->setAge(x);
			}
			break;
		case 5:
			cout << "                                                   原家庭住址：" << flag->e->getAddress() << endl;
			cout << "                                                   修改家庭住址：";
			cin >> y;
			cout << "                                                   是否确认修改(是、否）";
			cin >> judge;
			if (judge == "是") {
				flag->e->setAddress(y);
			}
			break;
		case 6:
			cout << "                                                   原基本职工工资：" << flag->e->getWages() << endl;
			cout << "                                                   修改基本职工工资：";
			cin >> x;
			cout << "                                                   是否确认修改(是、否）";
			cin >> judge;
			if (judge == "是") {
				flag->e->setWages(x);
			}
			break;
		case 7:
			cout << "                                                   原岗位津贴：" << flag->e->getMoney1() << endl;
			cout << "                                                   修改岗位津贴：";
			cin >> x;
			cout << "                                                   是否确认修改(是、否）";
			cin >> judge;
			if (judge == "是") {
				flag->e->setMoney1(x);
			}
			break;
		case 8:
			cout << "                                                   原养老金：" << flag->e->getMoney2() << endl;
			cout << "                                                   修改养老金：";
			cin >> x;
			cout << "                                                   是否确认修改(是、否）";
			cin >> judge;
			if (judge == "是") {
				flag->e->setMoney2(x);
			}
			break;
		case 9:
			cout << "                                                   原住房公积金：" << flag->e->getMoney3() << endl;
			cout << "                                                   修改住房公积金：";
			cin >> x;
			cout << "                                                   是否确认修改(是、否）";
			cin >> judge;
			if (judge == "是") {
				flag->e->setMoney3(x);
			}
			break;
		case 10:
			cout << "                                                   原住房公积金：" << flag->e->getMoney4() << endl;
			cout << "                                                   修改住房公积金：";
			cin >> x;
			cout << "                                                   是否确认修改(是、否）";
			cin >> judge;
			if (judge == "是") {
				flag->e->setMoney4(x);
			}
			break;
		case 11:
			cout << "                                                   原住房公积金：" << flag->e->getMoney5() << endl;
			cout << "                                                   修改住房公积金：";
			cin >> x;
			cout << "                                                   是否确认修改(是、否）";
			cin >> judge;
			if (judge == "是") {
				flag->e->setMoney5(x);
			}
			break;
		default:
			cout << "                                                   输入修改序号错误，请重新输入\n";
			break;
		}
	}
	else if (i == 2) {
	    listpoint2 *flag = findEmplpoyee(head2, 1);
		print(flag);
		printFunction5(head2);
		cin >> j;
		switch (j)
		{
		case 1:
			cout << "                                                   原编号：" << flag->e->getNum() << endl;
			cout << "                                                   修改编号：";
			cin >> x;
			cout << "                                                   是否确认修改(是、否）";
			cin >> judge;
			if (judge == "是") {
				flag->e->setNum(x);
			}
			break;
		case 2:
			cout << "                                                   原姓名：" << flag->e->getName() << endl;
			cout << "                                                   修改姓名：";
			cin >> y;
			cout << "                                                   是否确认修改(是、否）";
			cin >> judge;
			if (judge == "是") {
				flag->e->setName(y);
			}
			break;
		case 3:
			cout << "                                                   原性别：" << flag->e->getGender() << endl;
			cout << "                                                   修改性别：";
			cin >> y;
			cout << "                                                   是否确认修改(是、否）";
			cin >> judge;
			if (judge == "是") {
				flag->e->setGender(y);
			}
			break;
		case 4:
			cout << "                                                   原年龄：" << flag->e->getAge() << endl;
			cout << "                                                   修改年龄：";
			cin >> x;
			cout << "                                                   是否确认修改(是、否）";
			cin >> judge;
			if (judge == "是") {
				flag->e->setAge(x);
			}
			break;
		case 5:
			cout << "                                                   原家庭住址：" << flag->e->getAddress() << endl;
			cout << "                                                   修改家庭住址：";
			cin >> y;
			cout << "                                                   是否确认修改(是、否）";
			cin >> judge;
			if (judge == "是") {
				flag->e->setAddress(y);
			}
			break;
		case 6:
			cout << "                                                   原基本职工工资：" << flag->e->getWages() << endl;
			cout << "                                                   修改基本职工工资：";
			cin >> x;
			cout << "                                                   是否确认修改(是、否）";
			cin >> judge;
			if (judge == "是") {
				flag->e->setWages(x);
			}
			break;
		case 7:
			cout << "                                                   原奖金：" << flag->e->getMoney1() << endl;
			cout << "                                                   修改奖金：";
			cin >> x;
			cout << "                                                   是否确认修改(是、否）";
			cin >> judge;
			if (judge == "是") {
				flag->e->setMoney1(x);
			}
			break;
		case 8:
			cout << "                                                   原所得税：" << flag->e->getMoney2() << endl;
			cout << "                                                   修改所得税：";
			cin >> x;
			cout << "                                                   是否确认修改(是、否）";
			cin >> judge;
			if (judge == "是") {
				flag->e->setMoney2(x);
			}
			break;
		default:
			cout << "                                                   输入修改序号错误，请重新输入\n";
			break;
		}
	}
	else {
		cout << "                                                   输入员工类型有误";
	}
}

void deleteEmplpoyee(int i, int j, listpoint1 *head1, listpoint2 *head2) {
	if (i == 1) {
		
		if (j == 1) {
			printEmployees(head1);
			cout << endl;
			listpoint1 *flag = findEmplpoyee(head1, 1);
			flag->fireEmployee = true;
		}
		else if (j == 2) {
			printEmployees(head1);
			cout << endl;
			listpoint1 *flag = findEmplpoyee(head1, 1);
			if (flag->next == NULL) {
				flag->last->next = NULL;
			}
			else {
				flag->last->next = flag->next;
				flag->next->last = flag->last;
			}
			delete(flag);
		}
		else if (j == 3) {
			printEmployees(head1);
			cout << endl;
			listpoint1 *flag = findEmplpoyee(head1, 1);
			flag->fireEmployee = false;
		}
		else{
			cout << "                                                   输入删除类型有误";
		}
	}
	else if(i == 2){
		if (j == 1) {
			printEmployees(head2);
			cout << endl;
			listpoint2 *flag = findEmplpoyee(head2, 1);
			flag->fireEmployee = true;
		}
		else if (j == 2) {
			printEmployees(head2);
			cout << endl;
			listpoint2 *flag = findEmplpoyee(head2, 1);
			if (flag->next == NULL) {
				flag->last->next = NULL;
			}
			else {
				flag->last->next = flag->next;
				flag->next->last = flag->last;
			}
			delete(flag);
		}
		else if (j == 3) {
			printEmployees(head2);
			cout << endl;
			listpoint2 *flag = findEmplpoyee(head2, 1);
			flag->fireEmployee = false;
		}
		else {
			cout << "                                                   输入删除类型有误";
		}
	}
	else {
		cout << "                                                   输入员工类型有误";
	}
}

void saveEmployee(listpoint1 *head) {
	ofstream outFile1;
	outFile1.open("C:\\Users\\87776\\Desktop\\fullTimeEmployee.csv", ios::out);  //正式员工
	//建立表头
	//基本信息包括：编号、姓名、性别、年龄、家庭住址、基本职务工资
	outFile1 << "编号" << ',' << "姓名" << "," << "性别" << "," << "年龄" << "," << "家庭住址" << "," << "基本职务工资" << ",";
	//增加的属性包括：岗位津贴、养老金、住房公积金、所得税、医疗保险、实发工资
	outFile1 << "岗位津贴" << "," << "养老金" << "," << "住房公积金" << "," << "所得税" << "," << "医疗保险" << "," << "实发工资" << endl;
	

	listpoint1 *flag = head->next;
	for (; flag; flag = flag->next) {
		if (flag->fireEmployee) {
			flag->e->setNum(0 - flag->e->getNum());
		}
		writeCsv(*flag->e);
	}
}
void saveEmployee(listpoint2 *head) {
	ofstream outFile2;
	outFile2.open("C:\\Users\\87776\\Desktop\\temporaryEmployee.csv", ios::out); //临时员工
	//基本信息包括：编号、姓名、性别、年龄、家庭住址、基本职务工资
	outFile2 << "编号" << ',' << "姓名" << "," << "性别" << "," << "年龄" << "," << "家庭住址" << "," << "基本职务工资" << ",";
	//增加的属性包括：奖金、所得税、实发工资
	outFile2 << "奖金" << "," << "所得税" << "," << "实发工资" << endl;

	listpoint2 *flag = head->next;
	for (; flag; flag = flag->next) {
		if (flag->fireEmployee) {
			flag->e->setNum(0 - flag->e->getNum());
		}
		writeCsv(*flag->e);
	}
}