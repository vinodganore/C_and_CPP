#include<iostream.h>
#include<conio.h>
class abc
{
int x,y;
public:
	void show()
	{
		x=4;
		y=5;
		cout<<"add is "<<*this;
		cout<<x<<"  "<<y;
	}
};
void main()
{
abc o;
cout<<"add at main is"<<&o;
o.show();
getch();
}