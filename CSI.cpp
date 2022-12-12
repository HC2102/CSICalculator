#include<iostream> 
#include <string>
#define MAX 100
using namespace std;

class Student
{
	private:
		double PT1,PT2,Lab1,Lab2,Pres1,Pres2,FE,FR;
	public:
		string fullName;
		void getInfo();
		void output();
};
void Student::getInfo()
{
	cout << "Enter student name:	";
	cin.ignore();
	getline(cin,fullName);
	cout <<"Enter student's PT1 mark:	";
	cin >> PT1;
	cout <<"Enter student's PT2 mark:	";
	cin >> PT2;
	cout <<"Enter student's Lab1 mark:	";
	cin >> Lab1;
	cout <<"Enter student's Lab2 mark:	";
	cin >> Lab2;
	cout <<"Enter student's Presentation1 mark:	";
	cin >> Pres1;
	cout <<"Enter student's Presentation2 mark:	";
	cin >> Pres2;
	cout <<"Enter student's Final Exam mark:	";
	cin >> FE;
	cout <<"\n"<< "Data recorded! \n";
}

void Student::output()
{
	FR =((PT1+PT2)*0.5)*0.3+((Lab1+Lab2)*0.5)*0.2+((Pres1+Pres2)*0.5)*0.1+FE*0.4;
	cout << "Name:				"<<fullName;
	cout << "\nPT1:				"<<PT1;
	cout << "\nPT2:				"<<PT2;
	cout << "\nLab1:				"<<Lab1;
	cout << "\nLab2:				"<<Lab2;
	cout << "\nPresentation 1:	                "<<Pres1;
	cout << "\nPresentation 2:	                "<<Pres2;
	cout << "\nFinal Exam:	                "<<FE;
	cout << "\nFinal Result:		        "<<FR;
	
}

void display()
{
	cout <<"=============STUDENT LIST OF CSI 104============="<<"\n";
	cout <<"Choose an option"<<"\n";
	cout <<"1. Add a new student information"<<"\n";
	cout <<"2. Display current student list"<<"\n";
	cout <<"3. Sorting"<<"\n";
	cout <<"4. Edit student information"<<"\n";
	cout <<"0. Exit"<<"\n";
	cout <<"=================================================="<<"\n";
}
	
int main()
{
	
	Student std[MAX],tmp;
	int n =0,i,j, run =1;
	int ntmp;
	int nCurrent =0;
	while (run ==1)
	{
		int option,id;
		display();
		scanf("%d",&option);
		system("cls");
		switch (option)
		{
			case 1:
				cout<<"Enter total number of student	";
				cin>>n;
				for(i =0 ;i<n;i++)
				{
					cout<<"Enter details of student  "<<nCurrent+i+1<<":\n";
					std[nCurrent+i].getInfo();
				}
				nCurrent = nCurrent + n;
				system ("cls");
				break;
			case 2:
				cout <<"==========Student list==========\n";
				for (i=0;i<=nCurrent-1;i++)
				{	cout<<"---------------------------------"<<"\n";
					cout<<"Student no	"<<i+1<<"\n";
					std[i].output();
					cout<<"\n"<<"---------------------------------";
				}
				cout<<"\n===========End of the list===========\n";
				break;
			case 3:
				for(i=nCurrent-1;i>=0;i--)
				{
					for(j=0; j<i;j++)
					{
						string s1(std[j].fullName);
						string s2(std[i].fullName);
						if(s1>s2)
						{
							tmp=std[j];
							std[j]=std[i];
							std[i]=tmp;
						}	
					}
				}
				cout <<"List sorted\n";
				break;
			case 4:
				cout << "Choose a student id to change";
				cin>>id;
				std[id-1].getInfo();
				system("cls");
				break;
			default:
				run = 0;
				break;
		}
	}
	
}
//Some change here!