#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct menu
{
	int item;
	char name[25];
	char size[20];
	int price;
};
struct menu menuList[12];
int nitems , served , ordered;
char name[50];
int main()
{
int n;

	menuList[0].item = 1;
	strcpy(menuList[0].name , "Burger");
	strcpy(menuList[0].size , "150 gm");
	menuList[0].price = 120;
	
	menuList[1].item = 2;
	strcpy(menuList[1].name , "Pizza");
	strcpy(menuList[1].size , "250 gm");
	menuList[1].price = 240;
	
	menuList[2].item = 3;
	strcpy(menuList[2].name , "Dosa");
	strcpy(menuList[2].size , "200 gm");
	menuList[2].price = 130;
	
	menuList[3].item = 4;
	strcpy(menuList[3].name , "Shawarma Roll");
	strcpy(menuList[3].size , "2pc");
	menuList[3].price = 140;
	
	menuList[4].item = 5;
	strcpy(menuList[4].name , "Cutlet");
	strcpy(menuList[4].size , "4pc");
	menuList[4].price = 80;
	
	menuList[5].item = 6;
	strcpy(menuList[5].name , "Noodles");
	strcpy(menuList[5].size , "150 gm");
	menuList[5].price = 150;
	
	menuList[6].item = 7;
	strcpy(menuList[6].name , "Fried Rice");
	strcpy(menuList[6].size , "150 gm");
	menuList[6].price = 45;
	
	menuList[7].item = 8;
	strcpy(menuList[7].name , "Biryani");
	strcpy(menuList[7].size , "200 gm");
	menuList[7].price = 180;
	
	menuList[8].item = 9;
	strcpy(menuList[8].name , "Momos");
	strcpy(menuList[8].size , "5pc");
	menuList[8].price = 50;
	
	menuList[9].item = 10;
	strcpy(menuList[9].name , "Cold Coffee");
	strcpy(menuList[9].size , "200 ml");
	menuList[9].price = 90;
	
	menuList[10].item = 11;
	strcpy(menuList[10].name , "Idli");
	strcpy(menuList[10].size , "100 gm");
	menuList[10].price = 70;
	
	menuList[11].item = 12;
	strcpy(menuList[11].name , "Halwa");
	strcpy(menuList[11].size , "100 gm");
	menuList[11].price = 100;	
printf("Welcome to the Bhukkad Restraunt");

while(1)
{
	printf("\n1. Order\n2. Serve\n3. Display\n4. Exit the Program\nEnter your selection\n");
	scanf(" %d" , &n);
	switch (n)
	{
		case 1: order();
				break;
		case 2: serve();
				break;
		case 3: display();
				break;
		case 4: printf("It was a nice experience with you.\nHope to see you soon");
				return 0;
				break;
		default: printf("Please choose within the options");
	}
}
return 0;
}

int order()
{
	int a, q, j, order , nitems , order_List[20] , order2 , total=0;
	char adi;
	
	nitems = sizeof menuList / sizeof menuList[0] ;
	printf("\n----------------------------------MENU--------------------------------");
	for (a=0;a<nitems;a++)
	{
		printf("\n-----------------%d-----------------%s-------------------%s--------------------%d" , menuList[a].item , menuList[a].name , menuList[a].size , menuList[a].price );
	}
	printf("\nEnter your name : ");
	scanf("%s" , name);
	printf("How many items you want to order? ");
	scanf("%d" , &order);
	if(order==0)
	{
		printf("None items ordered\nHope you visit us again :)");
	}
	else
	{
		for(j=0;j<order;j++)
		{
			printf("Enter the %d food item code\n" , j+1);
			scanf("%d" , &order_List[j] );
			if(order_List[j]==0 || order_List[j] > nitems)
			{
				printf("Out of the menu option , Try again\n");
				order_List[j] = 0;
				j--;
			}
			else
			{
				printf("%s of %s\n" , menuList[order_List[j]-1].size , menuList[order_List[j]-1].name );
				printf("Please enter the quantity: ");
				scanf("%d" , &q);
				total = total + (q*menuList[order_List[j]-1].price);
			}
		}
		printf("Do you want to order anything else ?(y/n)\n");
		scanf(" %c" , &adi);
		if(adi=='Y' || adi=='y')
		{
			printf("How many items you want to order? ");
			scanf("%d" , &order2);
			for(;j<(order + order2);j++)
			{
				printf("Enter the %d food item code\n" , j+1);
				scanf("%d" , &order_List[j] );
				if(order_List[j]==0 || order_List[j] > nitems)
				{
					printf("Out of the menu option , Try again\n");
					order_List[j] = 0;
					j--;
				}
				else
				{
					printf("%s of %s\n" , menuList[order_List[j]-1].size , menuList[order_List[j]-1].name );
					printf("Please enter the quantity: ");
					scanf("%d" , &q);
					total = total + (q*menuList[order_List[j]-1].price);
				}
			}		
		}
		printf("Total number of items ordered %d \nThankyou %s for your order.Your total bill is %d " , ()order+order2) , name, total);
		ordered++;	
	}
}

int serve()
{
	int r = rand() % 20;
	printf("Order no. %d by %s is ready\nEnjoy your meal :)" , r, name);
	served++;
}
int display()
{
	printf("Total Order Taken = %d\nTotal Order Served = %d\nNumber of Orders Waiting to be served = %d", ordered , served , (ordered-served));
}

