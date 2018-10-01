#include<iostream.h>
#include<conio.h>
class Bank
{
	int acno,bal;
	char n[10];
	public:
		void getRecord();
		void showRecord();
		void withdrawl();
		void deposit();
		int getAcno();
};
void Bank::getRecord()
{
	cout<<"\nenter data";
	cin>>acno>>n>>bal;
}
void Bank::showRecord()
{
	cout<<acno<<" "<<n<<" "<<bal<<endl;
}
int Bank::getAcno()
{
	return acno;
}
void Bank::withdrawl()
{
	int amt;
	cout<<"\nenter amt to be withdrawl";
	cin>>amt;
	if(bal-amt>=500)
	{
		bal=bal-amt;
		cout<<"\nsuccessfully withdrawled";
	}
	else
	{
		cout<<"\nnot enough bal";
	}
}
void Bank::deposit()
{
	int amt;
	cout<<"\nenter amt to be deposit";
	cin>>amt;
	bal=bal+amt;
	cout<<"\nsuccessfully deposited";
}
void main()
{
	int ch,i,f,n;
	Bank b[3];
	clrscr();
	do{
		cout<<"\n1:Add\n2:Show\n3:Withdraw\n4:Deposit\n5:Exit\nenter ur choice";
		cin>>ch;
		switch(ch)
		{
			case 1:
				for(i=0;i<3;i++)
				{
					b[i].getRecord();
				}
				break;
			case 2:
				for(i=0;i<3;i++)
				{
					b[i].showRecord();
				}
				break;
			case 3:
				f=0;
				cout<<"\nenter acno to withdraw";
				cin>>n;
				for(i=0;i<3;i++)
				{
					if(b[i].getAcno()==n)
					{
						b[i].withdrawl();
						f=1;
						break;
					}
				}
				if(f==0)
				cout<<"\nacno not found";
				break;
			case 4:
				f=0;
				cout<<"\nenter acno to deposit";
				cin>>n;
				for(i=0;i<3;i++)
				{
					if(b[i].getAcno()==n)
					{
						b[i].deposit();
						f=1;
						break;
					}
				}
				if(f==0)
				cout<<"\nacno not found";
				break;

		}
	}while(ch!=5);
}
