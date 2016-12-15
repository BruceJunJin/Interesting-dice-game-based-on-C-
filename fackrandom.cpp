#include <iostream>
#include <cstdlib>
using namespace std;
// firstly, roll the dice
int rolldice(){
	int dice1=1+rand()%6;
	int dice2=1+rand()%6;
	int sum= dice1+dice2;
	cout<<"player rolled"<<dice1<<"+"<<dice2<<"="<<sum<<endl;
	return sum;
}
enum State {Win,Lose,Continue};
int main(){
	int sum, mypoint;
	State status;
	unsigned seed;
	cout<<"please input seed:";
	cin>>seed;
	srand(seed);//种子传递rand
	sum=rolldice();
	switch (sum){
		case 7:
		case 11:
		  status =Win;
		  break;
		case 2:
		case 3:
		case 12:
		  status= Lose;
		  break;
		default:
		  status= Continue;
		  mypoint = sum;
		  cout<<"point is"<<mypoint<<endl;
		  break;
	}
	while(status==Continue){
		sum=rolldice();
		if (sum==mypoint)
		  status=Win;
		else if (sum==7)
           status=Lose;       
	}
	if (status==Win)
		cout<<"Win!"<<endl;
	else
		cout<<"Lose"<<endl;
	return 0;
}