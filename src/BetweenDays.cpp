/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
const int monthDays[12] = { 31, 28, 31, 30, 31, 30,
31, 31, 30, 31, 30, 31 };
struct node{
	int data;
	struct node *next;
};
struct Date
{
	int d;
	int y;
	int m;

};
int countLeapYears(Date d)
{
	int years = d.y;
	if (d.m <= 2)
		years--;
	return years / 4 - years / 100 + years / 400;
}
int diff(Date dt1, Date dt2)
{
	long int n1 = dt1.y * 365 + dt1.d;
	for (int i = 0; i<dt1.m - 1; i++)
	n1 += monthDays[i];
	n1 += countLeapYears(dt1);
	long int n2 = dt2.y * 365 + dt2.d;
	for (int i = 0; i<dt2.m - 1; i++)
	n2 += monthDays[i];
	n2 += countLeapYears(dt2);
	return (n2 - n1);
}
int check(char date[])
{
		int i = 06;
		int year = 0;
		char temp = '0';
		for (i = 0; i<6; i++)
		{
			if (date[i] == '0' && date[i + 1] == '0')
			{
				printf("enter proper date .. it cant b zero ");
				return 0;
			}
		}
		for (i = 6; i<10; i++)
		{
			year = (year * 10) + (date[i] - '0');
		}
		if (year % 4 == 0) {
			temp = '1';
			if (year % 100 == 0)
			{
				if (year % 400 == 0)
				{
					temp = '1';
				}
				else {
					temp = '0';
				}

			}

		}

		if (temp == '0' && date[3] == '0' && date[4] == '2' && date[0] == '2' && date[1] == '9')
		{
			printf(" error in leap year");
			return 0;
		}
		else { return 1; }
}



int between_days(struct node *date1head, struct node *date2head)
{
	if (date1head == NULL || date2head == NULL)
	{
		return -1;
	}
	else
	{
		struct  node *k;
		struct  node *l;
		k = date1head;
		l = date1head;
		char *dat1=NULL;
		char *dat2=NULL;
		int *date1=NULL;
		int *date2=NULL;
		int j = 0;
		while (date1head != NULL)
		{
			 dat1[j] = date1head->data;
			 date1[j] = date1head->data;
			 date1head = date1head->next;

		}
		j = 0;
		while (date2head != NULL)
		{
			dat2[j] = date2head->data;
			date2[j] = date2head->data;
			date2head = date2head->next;

		}
		if (!(check(dat1) && check(dat2)))
		{
			return -1;
		}
		int d1, m1, y1, d2, m2, y2;
		d1 = date1[0] * 10 + date1[1];
		d2 = date2[0] * 10 + date2[2];
		m1 = date1[2] * 10 + date1[3];
		m2 = date2[2] * 10 + date2[3];
		y1 = date1[4] * 1000 + date1[5] * 100 + date1[6] * 10 + date1[7];
		y2 = date2[4] * 1000 + date2[5] * 100 + date2[6] * 10 + date2[7];
		struct Date mydate1;
		struct Date mydate2;
		mydate1.d = d1;
		mydate1.m = m1;
		mydate1.y = y1;
		mydate2.d = d2;
		mydate2.m = m2;
		mydate2.y = y2;
		int result;
		result = diff(mydate1, mydate2);
	}
}












       
